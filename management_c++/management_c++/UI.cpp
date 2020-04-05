#include "UI.h"
#include <string>
#include <iostream>
#include <string>
using namespace std;

void UI::menu() {
	cout << "add - to add a turret\n";
	cout << "delete - to delete a turret\n";
	cout << "update - to change the turret\n";
	cout << "list - to print all the turrets\n";
	cout << "exit - to exit the app\n";
	cout << "mode - to change the mode (admin or user)\n";
}

void UI::add_turret(char *command) {
	
}
void UI::list_turrets(char *command) {

}
void UI::delete_turret(char *command) {

}
void UI::update_turret(char *command) {

}

void UI::ui_console() {
	menu();
	int ok = 1;
	string mode = "A";
	while (ok)
	{
		while (mode == "A" && ok == 1) {
			char cmd[100], cmd_aux[100], * command;
			cout << ">>>";
			cin.getline(cmd, 100);


			strcpy(cmd_aux, cmd);
			command = strtok(cmd_aux, " ");

			if (strcmp(command, "add") == 0) {
				add_turret(cmd);
			}
			else if (strcmp(command, "update") == 0) {
				update_turret(cmd);
			}
			else if (strcmp(command, "delete") == 0) {
				delete_turret(cmd);
			}
			else if (strcmp(command, "list") == 0) {
				list_turrets(cmd);
			}
			else if (strcmp(command, "mode") == 0) {
				command = strtok(0, " ");
				if (strcmp(command, "B") == 0) {
					mode = "B";
					cout << "You are now in mode: user\n";
				}
				else
					cout << "Invalid user type !\n";
			}
			else if (strcmp(command, "exit") == 0) {
				ok = 0;
			}
			else printf("Not a valid command !\n");
		}

		while (mode == "B" && ok == 1) {
			char cmd[100], cmd_aux[100], * command;
			cout << ">>>";
			cin.getline(cmd, 100);


			strcpy(cmd_aux, cmd);
			command = strtok(cmd_aux, " ");

			if (strcmp(command, "add") == 0) {
				add_turret(cmd);
			}
			else if (strcmp(command, "update") == 0) {
				update_turret(cmd);
			}
			else if (strcmp(command, "delete") == 0) {
				delete_turret(cmd);
			}
			else if (strcmp(command, "list") == 0) {
				list_turrets(cmd);
			}
			else if (strcmp(command, "mode") == 0) {
				command = strtok(0, " ");
				if (strcmp(command, "A") == 0) {
					mode = "A";
					cout << "You are now in mode: administrator\n";
				}
				else
					cout << "Invalid user type diiic!\n";
			}
			else if (strcmp(command, "exit") == 0) {
				ok = 0;
			}
			else printf("Not a valid command !\n");
		}
	}
}