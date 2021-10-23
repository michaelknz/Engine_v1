#include "Main_Manager.h"

Main_Manager::Main_Manager(int width, int height, const std::string& title) {
	this->height = height;
	this->width = width;
	Init_Scene();
	display = new Display(width, height, title);
	cur_shader = new Shader("DefaultShader");
	event_system = new Event_System();
	cur_shader->Bind();
	Connect_Manager* man = Connect_Manager::get_Instace();
	man->Set_Prog(cur_shader->Get_Prog());
}

Main_Manager::~Main_Manager() {
	cur_shader->Unbind();
	delete display;
	delete cur_shader;
	delete event_system;
	for (std::map<std::string, BaseObject*>::iterator i = Scene.begin(); i != Scene.end(); ++i) {
		delete (*i).second;
	}
}

void Main_Manager::Init_Scene() {
	Add_Camera();
}

void Main_Manager::Add_Camera() {
	Transform_Component_Info trans(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	Add_Object<Camera>("camera", &trans);
	Camera_Component_Info cam(90.0f, 0.1f, 100.0f, (float)width / (float)height);
	Scene["camera"]->Add_Component<Camera_Component>("camera", &cam);
}

void Main_Manager::Update_Objects() {
	for (int i = 0; i < objects_names.size(); ++i) {
		Scene[objects_names[i]]->Update();
	}
}

void Main_Manager::Update(float r, float g, float b, float a) {
	display->Clean_Display(r, g, b, a);
	Update_Objects();
	display->Swap();
}

void Main_Manager::Game_Loop() {
	while (true) {
		event_system->Get_Events();
		if (event_system->Is_App_Closed()) {
			break;
		}
		Update(0.5f, 0.5f, 0.5f, 1.0f);
	}
}

BaseObject* Main_Manager::GetObjectByName(const std::string& name) {
	return Scene[name];
}