#pragma once
#include <string>

#include <GL/glew.h>

#include "Context.h"

#include <GLFW\glfw3.h>


#define MAINLOOP(loop,windowptr) while(windowptr->isOpen()) ##loop

#define TERMINATE(windowptr) delete windowptr; glfwTerminate();

class Window
{
private:
	static bool glfwHasInit;
	GLFWwindow* windowHandle;
	int width, height;
	std::string title;
	Context* context;
public:
	Window(int width_, int height_, std::string title_);
	Window(int width_, int height_, std::string title_, ContextSettings settings_);
	~Window();

	bool isOpen();
	void enableVSync();
	void pollEvents();
	void swapBuffers();
};

