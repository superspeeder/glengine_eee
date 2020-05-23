#include "Window.h"

#include <iostream>

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}


Window::Window(int width_, int height_, std::string title_)
{

	width = width;
	height = height;
	title = title;

	if (!Window::glfwHasInit) {
		if (!glfwInit()) {
			std::cout << "glfw not initialized\n";
		}
		else {
			std::cout << "glfw initialized!\n";
		}
	}

	glfwSetErrorCallback(error_callback);

	context = new Context(ContextSettings{});

	windowHandle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (windowHandle == NULL) std::cout << "Window couldn't be created";
	else std::cout << "Window successfully created\n";

	context->makeCurrent(windowHandle);
}

bool Window::glfwHasInit = false;

Window::Window(int width_, int height_, std::string title_, ContextSettings settings_)
{

	width = width_;
	height = height_;
	title = title_;

	if (!Window::glfwHasInit) {
		if (!glfwInit()) {
			std::cout << "glfw not initialized\n";
		}
		else {
			std::cout << "glfw initialized!\n";
		}
	}

	glfwSetErrorCallback(error_callback);

	context = new Context(settings_);
	context->applySettings();

	windowHandle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (windowHandle == NULL) std::cout << "Window couldn't be created";
	else std::cout << "Window successfully created\n";
	context->makeCurrent(windowHandle);
}

Window::~Window()
{
	glfwDestroyWindow(windowHandle);
	delete(context);
}

bool Window::isOpen()
{
	return !glfwWindowShouldClose(windowHandle);
}

void Window::enableVSync()
{
	glfwSwapInterval(1);
}

void Window::pollEvents()
{
	glfwPollEvents();
}

void Window::swapBuffers()
{
	glfwSwapBuffers(windowHandle);
}
