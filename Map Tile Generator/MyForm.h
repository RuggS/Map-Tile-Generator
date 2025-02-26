#pragma once
#include <string>
#include "hex.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;




namespace MapTileGenerator {

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

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
	private: System::Windows::Forms::Label^ HexDisplay;
	private: System::Windows::Forms::Button^ Clear;


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
			this->HexDisplay = (gcnew System::Windows::Forms::Label());
			this->Clear = (gcnew System::Windows::Forms::Button());
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
			// HexDisplay
			// 
			this->HexDisplay->AutoSize = true;
			this->HexDisplay->Location = System::Drawing::Point(59, 65);
			this->HexDisplay->MinimumSize = System::Drawing::Size(200, 200);
			this->HexDisplay->Name = L"HexDisplay";
			this->HexDisplay->Size = System::Drawing::Size(200, 200);
			this->HexDisplay->TabIndex = 2;
			// 
			// Clear
			// 
			this->Clear->Location = System::Drawing::Point(212, 12);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(106, 35);
			this->Clear->TabIndex = 3;
			this->Clear->Text = L"Clear";
			this->Clear->UseVisualStyleBackColor = true;
			this->Clear->Click += gcnew System::EventHandler(this, &MyForm::Clear_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(656, 398);
			this->Controls->Add(this->Clear);
			this->Controls->Add(this->HexDisplay);
			this->Controls->Add(this->CreateTile);
			this->Name = L"MyForm";
			this->Text = L"Tile Generator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CreateTile_Click(System::Object^ sender, System::EventArgs^ e) {
		//Generate Hex
		hex newHex;
		std::string hex = newHex.PrintHex();
		System::String^ s = HexDisplay->Text;
		s += gcnew String(hex.c_str());
		HexDisplay->Text = s;

	}
	private: System::Void Clear_Click(System::Object^ sender, System::EventArgs^ e) {
		HexDisplay->Text = "";
	}
};
}


