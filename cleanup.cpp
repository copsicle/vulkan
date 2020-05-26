#include "objects.h"
#include "cleanup.h"
#include "setup.h"

void DestroyDebugUtilsMessengerEXT
(
	VkInstance instance,
	VkDebugUtilsMessengerEXT debugMessenger,
	const VkAllocationCallbacks* pAllocator
)
{
	auto func{ (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT") };
	if (func != nullptr)
		func(instance, debugMessenger, pAllocator);
}

void vulkanCleanup()
{
	if (enableValidationLayers) DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);

	vkDestroyInstance(instance, nullptr);
}

void glfwCleanup()
{
	// Cleanup GLFW objects
	glfwDestroyWindow(window);
	glfwTerminate();
}

void cleanup()
{
	// Call all cleanup operations
	vulkanCleanup();
	glfwCleanup();
}