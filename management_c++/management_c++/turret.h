#pragma once
#include <iostream>

class Turret {
private:
	std::string location;
	int size;
	int aura_level;
	std::string vision;

public:
	Turret();

	Turret(const std::string& location, const int size , const int aura_level, const std::string& vision);

	std::string get_location() const { return location; }
	int get_size() const { return size; }
	int get_aura_level() const { return aura_level; }
	std::string getSource() const { return vision; }

	bool operator==(const Turret& t);
};