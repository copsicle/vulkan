#include "objects.h"
#include "glfw.h"
#include "setup.h"
#include "cleanup.h"

// General main class to host the execution of all functions
class VK3D
{
public:
	bool framebufferResized{ false };

	void run()
	{
		// Run the application
		initGLFW();
		initVulkan();
		loopGLFW();

		cleanup();
	}
private:
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height)
	{
		auto app{ reinterpret_cast<VK3D*>(glfwGetWindowUserPointer(window)) };
		app->framebufferResized = true;
	}

	void handleResize()
	{
		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
	}
};

int main()
{
	VK3D vk;
	// Create class object and run the application with error catching
	try
	{
		vk.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	// Exit code
	return EXIT_SUCCESS;
}