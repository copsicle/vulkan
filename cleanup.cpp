#include "objects.h"
#include "cleanup.h"

void glfwCleanup()
{
	// Cleanup GLFW objects
	glfwDestroyWindow(window);
	glfwTerminate();
}

void cleanup()
{
	// Call all cleanup operations
	glfwCleanup();
}