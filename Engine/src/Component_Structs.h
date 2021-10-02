#ifndef COMPONENT_STRUCTS_H
#define COMPONENT_STRUCTS_H

#include <string>

struct Base_Info {

};

struct Mesh_Component_Info:public Base_Info {
	std::string filename;
};

#endif
