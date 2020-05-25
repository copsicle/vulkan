#include "cleanup.h"
#include "glfw.h"

void glfwCleanup()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void cleanup()
{
	glfwCleanup();
}