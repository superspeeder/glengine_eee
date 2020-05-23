#pragma once

#include <GL/glew.h>

#include <GLFW/glfw3.h>

struct ContextSettings {
	bool resizable = true;
	bool visible = true;
	bool decorated = true;
	bool focused = true;
	bool auto_iconify = true;
	bool floating = false;
	bool maximized = false;
	bool center_cursor = true;
	bool transparent_framebuffer = false;
	bool focus_on_show = true;
	bool scale_to_monitor = false;

	int red_bits = 8;
	int green_bits = 8;
	int blue_bits = 8;
	int alpha_bits = 8;
	int depth_bits = 24;
	int stencil_bits = 8;

	int accum_red_bits = 0;
	int accum_green_bits = 0;
	int accum_blue_bits = 0;
	int accum_alpha_bits = 0;
	
	int aux_buffers = 0;
	int samples = 0;
	int refresh_rate = GLFW_DONT_CARE;
	
	bool stereo = false;
	bool srgb_capable = false;
	bool doublebuffer = true;

	int client_api = GLFW_OPENGL_API;
	int context_creation_api = GLFW_NATIVE_CONTEXT_API;

	int context_version_major = 1;
	int context_version_minor = 0;

	int robustness = GLFW_NO_ROBUSTNESS;
	int context_release_behaviour = GLFW_ANY_RELEASE_BEHAVIOR;

	bool opengl_forward_compat = false;
#ifdef DEBUG
	bool opengl_debug_context = true;
#else
	bool opengl_debug_context = false;
#endif
	int opengl_profile = GLFW_OPENGL_ANY_PROFILE;

	// no cocoa or x11 hints for now
};

class Context
{
private:
	ContextSettings settings;
	static bool isGlewInit;
public:
	Context(ContextSettings settings) : settings(settings) {};
	~Context();

	void applySettings();
	void makeCurrent(GLFWwindow* windowHandle);

};

