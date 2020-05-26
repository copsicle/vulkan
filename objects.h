#pragma once
// Include GLFW, GLM and Vulkan
#define GLFW_INCLUDE_VULKAN
#define GLM_FORCE_RADIANS
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
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

extern VkRenderPass renderPass;
//extern VkDescriptorSetLayout descriptorSetLayout;
extern VkPipelineLayout pipelineLayout;
extern VkPipeline graphicsPipeline;

extern VkCommandPool commandPool;
extern std::vector<VkCommandBuffer> commandBuffers;

extern std::vector<VkSemaphore> imageAvailableSemaphores;
extern std::vector<VkSemaphore> renderFinishedSemaphores;
extern std::vector<VkFence> inFlightFences;
extern std::vector<VkFence> imagesInFlight;
extern size_t currentFrame;

extern VkBuffer vertexBuffer;
extern VkDeviceMemory vertexBufferMemory;
extern VkBuffer indexBuffer;
extern VkDeviceMemory indexBufferMemory;

//extern std::vector<VkBuffer> uniformBuffers;
//extern std::vector<VkDeviceMemory> uniformBuffersMemory;

//extern VkDescriptorPool descriptorPool;
//extern std::vector<VkDescriptorSet> descriptorSets;

extern bool resizeFrame;