#include "Connect_Manager.h"

Connect_Manager* Connect_Manager::instance = nullptr;

Connect_Manager::Connect_Manager() {

}

Connect_Manager::~Connect_Manager() {

}

Connect_Manager* Connect_Manager::get_Instace() {

	if (instance == nullptr) {
		instance = new Connect_Manager();
	}
	return instance;
}

void Connect_Manager::delete_Instace() {
	if (instance != nullptr) {
		delete instance;
	}
}

void Connect_Manager::Set_Prog(GLuint pval) {
	prog = pval;
}

void Connect_Manager::Send_Model(glm::mat4 model) {
	glUniformMatrix4fv(glGetUniformLocation(prog, "model"), 1, GL_FALSE, glm::value_ptr(model));
}