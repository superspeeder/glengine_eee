#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Window.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "ShaderProgram.h"

const int WIDTH = 800;
const int HEIGHT = 800;
const std::string TITLE = "Gamer Title";
ContextSettings settings{};

int main(void) {

	settings.context_version_major = 4;
	settings.context_version_minor = 5;
	settings.opengl_profile = GLFW_OPENGL_CORE_PROFILE;

	Window* window = new Window(WIDTH, HEIGHT, TITLE, settings);

	glClearColor(1, 0, 0, 1);

	float verticies[4 * 2] = {
		-0.5f,-0.5f,
		0.5f,-0.5f,
		0.5f,0.5f,
		-0.5f,0.5f
	};

	unsigned int indicies[2 * 3] = {
		0,1,2,
		2,3,0
	};

	VertexArray* vao = new VertexArray();

	Buffer* vbo = new VBO(4*3,verticies);
	vbo->Bind();
	vao->_2D(0, GL_FLOAT, 0, 0);
	vao->EnableAttribute(0);

	Buffer* ibo = new IBO(3 * 2, indicies);
	ibo->Bind();

	VertexArray::BindNone();
	vbo->Unbind();

	// Shaders

	Shader* vertexShader, * fragmentShader;
	vertexShader = new Shader(RESOURCE("shaders/shader0/vertex.glsl"), GL_VERTEX_SHADER);
	fragmentShader = new Shader(RESOURCE("shaders/shader0/fragment.glsl"), GL_FRAGMENT_SHADER);

	ShaderProgram* shader0 = new ShaderProgram();
	shader0->AttachShader(vertexShader);
	shader0->AttachShader(fragmentShader);
	shader0->LinkProgram();
	delete vertexShader;
	delete fragmentShader;


	MAINLOOP({
		window->pollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader0->Use();
		shader0->Uniform4f("uColor",0,sin(glfwGetTime()) / 2.0f + 0.5f, 0, 1);
		vao->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
		VertexArray::BindNone();

		window->swapBuffers();
		}, window);

	delete vbo;
	delete shader0;
	delete verticies;
	TERMINATE(window);
	return 0;
}