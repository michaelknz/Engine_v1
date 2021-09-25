# version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 Color;

out vec4 Color4;

void main(){
	gl_Position=vec4(position,1.0);
	Color4=vec4(Color,1.0);
}