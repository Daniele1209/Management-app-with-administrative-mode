#include <crtdbg.h>
#include "UI.h"
int main()
{
	//Repository repo{}
	//Service service{ repo }
	//UI ui{ service }
	UI ui{};
	ui.ui_console();

	return 0;
}