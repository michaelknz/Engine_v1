#include "Main_Manager.h"
#include "Mesh_Component.h"
#include "Transform_Component.h"
#include "Texture_Component.h"

int main(int argc, char** argv) {
	int width = 800;
	int height = 600;
	std::string title = "Game Example";
	Main_Manager manager(width, height, title);
	Mesh_Component_Info inf("res/cube.obj");
	Texture_Component_Info tex("res/dice1.png");
	Transform_Component_Info trans(glm::vec3(0, 0, -6), glm::vec3(45, 45, 0), glm::vec3(1, 1, 1));
	manager.Add_Object<BaseObject>("monkey", &trans);
	manager.GetObjectByName("monkey")->Add_Component<Texture_Component>("Texture", &tex);
	manager.GetObjectByName("monkey")->Add_Component<Mesh_Component>("Mesh_Component", &inf);
	manager.Game_Loop();
	Connect_Manager::delete_Instace();
	return 0;
}