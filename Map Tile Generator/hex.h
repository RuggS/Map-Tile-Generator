#pragma once
#include <string>
class hex {
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
	std::string getTemp(int tempRoll, int d4);
	std::string getWind(int windRoll);
	std::string getWeather(int weatherRoll);

public:
	 hex();

	std::string PrintHex();
};

