#include "hex.h"
#include <random>


std::string hex::getTemp(int tempRoll, int d4) {
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

std::string hex::getWind(int windRoll) {
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

std::string hex::getWeather(int weatherRoll) {
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



hex::hex() {
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

std::string hex::PrintHex() {
	std::string output = Biome[rolls[0]] + "\n";
	output.append(Monuments[rolls[1]] + "\n");
	output.append(WeirdLocations[rolls[2]] + "\n");
	output.append(getTemp(rolls[3], rolls[6]) + "\n");
	output.append(getWind(rolls[4]) + "\n");
	output.append(getWeather(rolls[5]));
	return output;
}
