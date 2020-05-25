#include "glfw.h"

GLFWwindow* window;

void initGLFW()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "GLFW Window", nullptr, nullptr);
}

void loopGLFW()
{
	while (!glfwWindowShouldClose(window))
		glfwPollEvents();
}