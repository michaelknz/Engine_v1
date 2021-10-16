#ifndef CONNECT_MANAGER_H
#define CONNECT_MANAGER_H

#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Connect_Manager {
public:
	static Connect_Manager* get_Instace();
	static void delete_Instace();
	void Set_Prog(GLuint pval);
	void Send_Model(glm::mat4 model);
	void Send_View(glm::mat4 view);
	void Send_Projection(glm::mat4 projection);
	~Connect_Manager();

private:
	Connect_Manager();
	static Connect_Manager* instance;
	GLuint prog;
};

#endif
