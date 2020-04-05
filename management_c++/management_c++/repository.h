#pragma once
#include "turret.h"
#include "dynamic_array.h"

class Repository {
private:
	Dynamic_vector<Turret> turrets;

public:
	//initialise the repo
	Repository() {}
	int get_the_size();
	int add_turret(const Turret& tur);
	//Turret find_turret_location(const std::string& location);
	Turret get_all_turrets(int pos);
	int delete_turret(std::string str);
	int update_turret(const Turret tur, std::string str);
};