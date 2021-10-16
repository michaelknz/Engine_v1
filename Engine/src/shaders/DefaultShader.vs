# version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 Color;

out vec4 Color4;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
	gl_Position=projection*view*model*vec4(position,1.0);
	Color4=vec4(Color,1.0);
}