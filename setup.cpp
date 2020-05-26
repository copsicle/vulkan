#include "objects.h"
#include "setup.h"
#include "devices.h"
#include "glfw.h"
#include "swapchain.h"
#include "pipeline.h"
#include "commands.h"
#include "buffers.h"
#include "descriptors.h"
#include "sync.h"
#include "cleanup.h"

VkInstance instance;
VkDebugUtilsMessengerEXT debugMessenger;

VkResult CreateDebugMessenger
(
	VkInstance instance,
	const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDebugUtilsMessengerEXT* pDebugMessenger
)
{
	auto func{ (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT") };
	if (func != nullptr)
		return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
	else
		return VK_ERROR_EXTENSION_NOT_PRESENT;
}

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback
(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageType,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	void* pUserData
)
{
	std::cerr << pCallbackData->pMessage << std::endl;
	return VK_FALSE;
}

void populateDebugMessenger(VkDebugUtilsMessengerCreateInfoEXT& debugInfo)
{
	debugInfo = {};
	debugInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	debugInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	debugInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
		VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	debugInfo.pfnUserCallback = debugCallback;
}

void setupDebugMessenger()
{
	if (!enableValidationLayers) return;

	VkDebugUtilsMessengerCreateInfoEXT debugInfo{};
	populateDebugMessenger(debugInfo);

	if (CreateDebugMessenger(instance, &debugInfo, nullptr, &debugMessenger) != VK_SUCCESS)
		throw std::runtime_error("could not setup debug messenger");
}

std::vector<const char*> getRequiredExtensions()
{
	uint32_t glfwExtensionCount{};
	const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	if (enableValidationLayers)
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

	return extensions;
}

bool checkValidationLayerSupport()
{
	uint32_t layerCount{};
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> layers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, layers.data());

	for (const char* layerName : validationLayers)
	{
		bool layerFound = false;

		for (const auto& layerProperties : layers)
		{
			layerFound = true;
			break;
		}

		if (!layerFound)
			return false;
	}

	return true;
}

void createInstance()
{
	if (enableValidationLayers && !checkValidationLayerSupport())
		throw std::runtime_error("validation layer not found");

	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Vulkan app";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_1;

	auto extensions{ getRequiredExtensions() };

	VkInstanceCreateInfo instanceInfo{};
	instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceInfo.pApplicationInfo = &appInfo;
	instanceInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	instanceInfo.ppEnabledExtensionNames = extensions.data();

	VkDebugUtilsMessengerCreateInfoEXT debugMsngrInfo;
	if (enableValidationLayers)
	{
		instanceInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		instanceInfo.ppEnabledLayerNames = validationLayers.data();

		populateDebugMessenger(debugMsngrInfo);
		instanceInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugMsngrInfo;
	}
	else
	{
		instanceInfo.enabledLayerCount = 0;
		instanceInfo.pNext = nullptr;
	}

	if (vkCreateInstance(&instanceInfo, nullptr, &instance) != VK_SUCCESS)
		throw std::runtime_error("failed to create vulkan instance");
}

void recreateSwapChain()
{
	int width{}, height{};
	glfwGetFramebufferSize(window, &width, &height);
	while (!width || !height)
	{
		glfwGetFramebufferSize(window, &width, &height);
		glfwWaitEvents();
	}

	vkDeviceWaitIdle(device);

	swapChainCleanup();

	initSwapChain();
	createRenderPass();
	createGraphicsPipeline();
	createFramebuffers();
	createUniformBuffers();
	initDescriptors();
	createCommandBuffers();
}

void initVulkan()
{
	createInstance();
	setupDebugMessenger();
	createSurface();
	initDevices();
	initSwapChain();
	initPipeline();
	createFramebuffers();
	createCommandPool();
	initBuffers();
	initDescriptors();
	createCommandBuffers();
	createSyncObjects();
}