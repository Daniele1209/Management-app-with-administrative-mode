#include <crtdbg.h>
#include "UI.h"
int main()
{
	//Repository repo{}
	Repository repo{};
	Service service{ repo };
	UI ui{ service };
	ui.ui_console();

	return 0;
}