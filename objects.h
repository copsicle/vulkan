#pragma once
// Include GLFW and Vulkan
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
// Include essential libraries
#include <iostream>
#include <stdexcept>
#include <cstdlib>
// Global objects
extern GLFWwindow* window;
extern VkInstance instance;