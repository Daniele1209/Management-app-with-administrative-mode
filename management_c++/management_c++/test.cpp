#include "test.h"

void run_service_tests() {
	Repository repo{};
	Service service{ repo };
	service.add_turret_repo("east", "huge", 400, 4000, "tower");
	service.add_turret_repo("west", "medium", 250, 3400, "tower");
	service.add_turret_repo("north", "small", 120, 1000, "mountains");
	service.add_turret_repo("south", "medium", 230, 2700, "tower");
	assert(repo.get_the_size() == 4);
	service.delete_turret_list("east");
	assert(repo.get_the_size() == 3);
	service.update_list("south", "huge", 2230, 27, "castle");
	assert(repo.get_the_size() == 3);
	std::cout << "tests passes !\n\n";
}

void run_all_tests() {
	run_service_tests();
}