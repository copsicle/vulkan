#pragma once
// Include GLFW and Vulkan
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
// Include essential libraries
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <cstdint>
// Include useful libraries
#include <algorithm>
// Global objects
extern GLFWwindow* window;
extern VkInstance instance;
extern VkDebugUtilsMessengerEXT debugMessenger;
extern VkSurfaceKHR surface;
extern VkPhysicalDevice physicalDevice;
extern VkDevice device;
extern VkQueue graphicsQueue;
extern VkQueue presentQueue;
extern VkSwapchainKHR swapChain;
extern std::vector<VkImage> swapChainImages;
extern VkFormat swapChainImageFormat;
extern VkExtent2D swapChainExtent;
extern std::vector<VkImageView> swapChainImageViews;
extern std::vector<VkFramebuffer> swapChainFramebuffers;