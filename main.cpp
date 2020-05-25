#include "glfw.h"
#include "cleanup.h"

// General main class to host the execution of all functions
class VK3D
{
public:
	void run()
	{
		// Run the application
		initGLFW();
		loopGLFW();
		
		cleanup();
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