#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

int main(int argc, char** argv) {
	SDL_Event Event;
	int width = 800;
	int height = 600;
	std::string title = "Game Example";
	Display display(width, height, title);
	Shader shader("DefaultShader");
	float vert[] = { -0.5f,-0.5f,0.0f,1.0f,0.0f,0.0f,
				  0.0f,0.5f,0.0f,1.0f,0.0f,0.0f,
				  0.5f,-0.5f,0.0f,1.0f,0.0f,0.0f };
	Mesh mesh(vert, 18, 6);

	while (true) {
		if (SDL_PollEvent(&Event)) {
			if (Event.type == SDL_QUIT) {
				break;
			}
		}
		display.Clean_Display(0.5f, 0.5f, 0.5f, 1.0f);
		shader.Bind();
		mesh.DrawMesh();
		shader.Unbind();
		display.Swap();
	}

	return 0;
}