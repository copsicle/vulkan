#include "objects.h"
#include "glfw.h"

GLFWwindow* window;
// Create window pointer
void initGLFW()
{
	// Initialize GLFW
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	// Launch window, put pointer in window object
	window = glfwCreateWindow(WIDTH, HEIGHT, "GLFW Window", nullptr, nullptr);
}

void loopGLFW()
{
	// Keep the window running and responsive to user actions
	while (!glfwWindowShouldClose(window))
		glfwPollEvents();
}