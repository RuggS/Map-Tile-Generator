#include "MyForm.h"
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

string Biome[] = { "Arctic",
"Coastal",
"Desert",
"Forest",
"Grassland",
"Mountain",
"Swamp",
"Underdark" };

string Monuments[] = {"Sealed burial mound or pyramid",
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
"Totem pole"};

string WeirdLocations[] = {"Dead magic zone",
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
"Floating earth mote with a tower on it"};



void main()
{

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    MapTileGenerator::MyForm form;

    Application::Run(% form);

}

string getTemp(int tempRoll, int d4) {
    if (tempRoll <= 14) {
        return "Temperature is normal for the season";
    }
    else if (tempRoll <= 17) {
        return "Temperature is " + to_string(d4 * 10) + " degrees Fahrenheit colder than normal";
    }
    else {
        return "Temperature is " + to_string(d4 * 10) + " degrees Fahrenheit hotter than normal";
    }
}

string getWind(int windRoll) {
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

string getWeather(int weatherRoll) {
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

