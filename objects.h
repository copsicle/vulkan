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
// Global objects
extern GLFWwindow* window;
extern VkInstance instance;
extern VkDebugUtilsMessengerEXT debugMessenger;