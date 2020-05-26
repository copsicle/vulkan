#include "objects.h"
#include "glfw.h"

GLFWwindow* window;
VkSurfaceKHR surface;
// Create window pointer and surface

void initGLFW()
{
	// Initialize GLFW
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	// Launch window, put pointer in window object
	window = glfwCreateWindow(WIDTH, HEIGHT, "GLFW Window", nullptr, nullptr);
}

void createSurface()
{
	// Create Vulkan surface on GLFW window
	if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS)
		throw std::runtime_error("Failed to create window surface");
}

void loopGLFW()
{
	// Keep the window running and responsive to user actions
	while (!glfwWindowShouldClose(window))
		glfwPollEvents();

	vkDeviceWaitIdle(device);
}