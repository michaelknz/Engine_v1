#include "Main_Manager.h"
#include "Mesh_Component.h"

int main(int argc, char** argv) {
	SDL_Event Event;
	int width = 800;
	int height = 600;
	std::string title = "Game Example";
	Main_Manager manager(width, height, title);
	Mesh_Component_Info inf;
	inf.filename = "res/monkey.fbx";
	manager.Add_Object<BaseObject>("monkey");
	manager.GetObjectByName("monkey")->Add_Component<Mesh_Component>("Mesh_Component", &inf);
	while (true) {
		if (SDL_PollEvent(&Event)) {
			if (Event.type == SDL_QUIT) {
				break;
			}
		}
		manager.Update();
	}

	return 0;
}