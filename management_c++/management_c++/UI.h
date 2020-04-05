#pragma once
//#include "service.h"

class UI {

private:
	//Service service;

public:
	//UI(const Service& s) : service(s){}
	
	void ui_console();

private:
	static void menu();
	void add_turret(char *command);
	void list_turrets(char *command);
	void delete_turret(char *command);
	void update_turret(char *command);
};