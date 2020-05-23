#include "Context.h"

void Context::applySettings()
{
	if (!settings.resizable) glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	if (!settings.visible) glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	if (!settings.decorated) glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	if (!settings.focused) glfwWindowHint(GLFW_FOCUSED, GLFW_FALSE);
	if (!settings.auto_iconify) glfwWindowHint(GLFW_AUTO_ICONIFY, GLFW_FALSE);
	if (settings.floating) glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
	if (settings.maximized) glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
	if (!settings.center_cursor) glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_FALSE);
	if (settings.transparent_framebuffer) glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
	if (!settings.focus_on_show) glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_FALSE);
	if (settings.scale_to_monitor) glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
	
	if (settings.red_bits != 8) glfwWindowHint(GLFW_RED_BITS, settings.red_bits);
	if (settings.green_bits != 8) glfwWindowHint(GLFW_GREEN_BITS, settings.green_bits);
	if (settings.blue_bits != 8) glfwWindowHint(GLFW_BLUE_BITS, settings.blue_bits);
	if (settings.alpha_bits != 8) glfwWindowHint(GLFW_ALPHA_BITS, settings.alpha_bits);
	if (settings.depth_bits != 24) glfwWindowHint(GLFW_DEPTH_BITS, settings.depth_bits);
	if (settings.stencil_bits != 8) glfwWindowHint(GLFW_STENCIL_BITS, settings.stencil_bits);

	if (settings.accum_red_bits != 8) glfwWindowHint(GLFW_ACCUM_RED_BITS, settings.accum_red_bits);
	if (settings.accum_green_bits != 8) glfwWindowHint(GLFW_ACCUM_GREEN_BITS, settings.accum_green_bits);
	if (settings.accum_blue_bits != 8) glfwWindowHint(GLFW_ACCUM_BLUE_BITS, settings.accum_blue_bits);
	if (settings.accum_alpha_bits != 8) glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, settings.accum_alpha_bits);

	if (settings.aux_buffers != 0) glfwWindowHint(GLFW_AUX_BUFFERS, settings.aux_buffers);
	if (settings.samples != 0) glfwWindowHint(GLFW_SAMPLES, settings.aux_buffers);
	if (settings.refresh_rate != GLFW_DONT_CARE) glfwWindowHint(GLFW_REFRESH_RATE, settings.aux_buffers);

	if (settings.stereo) glfwWindowHint(GLFW_STEREO, GLFW_TRUE);
	if (settings.srgb_capable) glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);
	if (!settings.doublebuffer) glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_FALSE);

	if (settings.client_api != GLFW_OPENGL_API) glfwWindowHint(GLFW_CLIENT_API, settings.client_api);
	if (settings.context_creation_api != GLFW_NATIVE_CONTEXT_API) glfwWindowHint(GLFW_CONTEXT_CREATION_API, settings.context_creation_api);

	if (settings.context_version_major != 1) glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, settings.context_version_major);
	if (settings.context_version_minor != 0) glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, settings.context_version_minor);

	if (settings.robustness != GLFW_NO_ROBUSTNESS) glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, settings.robustness);
	if (settings.context_release_behaviour != GLFW_ANY_RELEASE_BEHAVIOR) glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, settings.context_release_behaviour);

	if (settings.opengl_forward_compat) glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

#ifdef DEBUG
	if (!settings.opengl_forward_compat) glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_FALSE);
#else
	if (settings.opengl_forward_compat) glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
	if (settings.opengl_profile != GLFW_OPENGL_ANY_PROFILE) glfwWindowHint(GLFW_OPENGL_PROFILE, settings.opengl_profile);

}

bool Context::isGlewInit = false;

void Context::makeCurrent(GLFWwindow* windowHandle)
{
	glfwMakeContextCurrent(windowHandle);
	
	if (!Context::isGlewInit) glewInit();

}


Context::~Context() {
	delete& settings;
}