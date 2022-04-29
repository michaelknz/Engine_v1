#include <Engine.h>

int main(int argc, char** argv) {
	int width = 800;
	int height = 600;
	std::string title = "Game Example";
	Main_Manager manager(width, height, title);
	manager.Set_Bg_Color(Color(0.8f, 0.5f, 0.5f, 1.0f));
	Mesh_Component_Info inf("res/monkey.fbx");
	Texture_Component_Info tex("res/dice.png");
	Transform_Component_Info trans(glm::vec3(0, 0, -6), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
	manager.Add_Object<BaseObject>("monkey", &trans);
	manager.GetObjectByName("monkey")->Add_Component<Texture_Component>(TEXTURE_COMPONENT, &tex);
	manager.GetObjectByName("monkey")->Add_Component<Mesh_Component>(MESH_COMPONENT, &inf);
	manager.Game_Loop();
	return 0;
}