#pragma once
#include <random>
#include <string>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


class Hex {
private:
	int rolls[7] = {};

	const std::string Biome[8] = { "Arctic",
"Coastal",
"Desert",
"Forest",
"Grassland",
"Mountain",
"Swamp",
"Underdark" };

	const std::string Monuments[20] = { "Sealed burial mound or pyramid",
	"Plundered burial mound or pyramid",
	"Faces carved into a mountainside or cliff",
	"Giant statue carved into a mountainside or cliff",
	"Intact obelisk etched with a warning, historical lore, dedication or religious iconography",
	"Intact obelisk etched with a warning, historical lore, dedication or religious iconography",
	"Ruined or toppled obelisk",
	"Ruined or toppled obelisk",
	"Intact statue of a person or deity",
	"Intact statue of a person or deity",
	"Ruined or toppled statue of a person or deity",
	"Ruined or toppled statue of a person or deity",
	"Ruined or toppled statue of a person or deity",
	"Great stone wall, intact, with tower fortifications spaced at one-mile intervals",
	"Great stone wall in ruins",
	"Great stone arch",
	"Fountain",
	"Intact circle of standing stones",
	"Ruined or toppled circle of standing stones",
	"Totem pole" };

	const std::string WeirdLocations[20] = { "Dead magic zone",
	"Dead magic zone",
	"Wild magic zone",
	"Boulder carved with talking faces",
	"Crystal cave that mystically answers questions",
	"Ancient tree containing a trapped spirit",
	"Battlefield where lingering fog occasionally assumes humanoid forms",
	"Battlefield where lingering fog occasionally assumes humanoid forms",
	"Permanent portal to another plane of existence",
	"Permanent portal to another plane of existence",
	"Wishing well",
	"Giant crystal shard protruding from the ground",
	"Wrecked ship, which might be nowhere near water",
	"Haunted hill or barrow mound",
	"Haunted hill or barrow mound",
	"River ferry guided by a skeletal captain",
	"Field of petrified soldiers or other creatures",
	"Forest of petrified awakened trees",
	"Canyon containing a dragons' graveyard",
	"Floating earth mote with a tower on it" };

	std::string getTemp(int tempRoll, int d4) {
		if (tempRoll <= 14) {
			return "Temperature is normal for the season";
		}
		else if (tempRoll <= 17) {
			return "Temperature is " + std::to_string(d4 * 10) + " degrees Fahrenheit colder than normal";
		}
		else {
			return "Temperature is " + std::to_string(d4 * 10) + " degrees Fahrenheit hotter than normal";
		}
	}

	std::string getWind(int windRoll) {
		if (windRoll <= 12) {
			return "No wind";
		}
		else if (windRoll <= 17) {
			return "Light wind";
		}
		else {
			return "Strong wind";
		}
	}

	std::string getWeather(int weatherRoll) {
		if (weatherRoll <= 12) {
			return "No precipitation";
		}
		else if (weatherRoll <= 17) {
			return "Light rain or snow";
		}
		else {
			return "Heavy rain or snow";
		}
	}

public:
	Hex() {
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> d20(0, 19); // define the range
		std::uniform_int_distribution<> d8(0, 7); // define the range
		std::uniform_int_distribution<> d4(0, 3); // define the range
		rolls[0] = d8(gen);
		rolls[1] = d20(gen);
		rolls[2] = d20(gen);
		rolls[3] = d20(gen);
		rolls[4] = d20(gen);
		rolls[5] = d20(gen);
		rolls[6] = d4(gen);
	}

	std::string PrintHex() {
		std::string output = Biome[rolls[0]] + "\n";
		output.append(Monuments[rolls[1]] + "\n");
		output.append(WeirdLocations[rolls[2]] + "\n");
		output.append(getTemp(rolls[3], rolls[6]) + "\n");
		output.append(getWind(rolls[4]) + "\n");
		output.append(getWeather(rolls[5]));
		return output;
	}

};

namespace MapTileGenerator {

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private: int hexLabelCount = 0;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ CreateTile;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CreateTile = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// CreateTile
			// 
			this->CreateTile->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CreateTile->Location = System::Drawing::Point(62, 12);
			this->CreateTile->Name = L"CreateTile";
			this->CreateTile->Size = System::Drawing::Size(106, 35);
			this->CreateTile->TabIndex = 0;
			this->CreateTile->Text = L"Create Tile";
			this->CreateTile->UseVisualStyleBackColor = true;
			this->CreateTile->Click += gcnew System::EventHandler(this, &MyForm::CreateTile_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(499, 290);
			this->Controls->Add(this->CreateTile);
			this->Name = L"MyForm";
			this->Text = L"Tile Generator";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void CreateTile_Click(System::Object^ sender, System::EventArgs^ e) {
		//Generate Hex
		Hex newHex;
		std::string hex = newHex.PrintHex();

		// Create a new TextBox
		TextBox^ newTextBox = gcnew TextBox();

		// Set the location and size of the new TextBox
		newTextBox->Location = System::Drawing::Point(70, 50 + (hexLabelCount * 30)); // Positioning each new TextBox below the previous one
		newTextBox->Size = System::Drawing::Size(200, 20);
		//newTextBox->Text = gcnew String(hex.c_str());

		// Add the new TextBox to the form's controls
		this->Controls->Add(newTextBox);

		// Increment the counter for the next TextBox
		hexLabelCount++;
	}
	};
}
