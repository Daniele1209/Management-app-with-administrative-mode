#pragma once
#include "turret.h"
#include "service.h"

class UI {

private:
	Service service;

public:
	UI(const Service& s) : service(s){}
	
	void ui_console();

private:
	static void menu();
	void add_turret(std::string command);
	void list_turrets();
	void delete_turret(std::string command);
	void update_turret(std::string command);
};