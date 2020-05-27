#pragma once
// Include GLFW, STB, TOL, GLM and Vulkan
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>
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
extern VkDescriptorSetLayout descriptorSetLayout;
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

extern std::vector<VkBuffer> uniformBuffers;
extern std::vector<VkDeviceMemory> uniformBuffersMemory;

extern VkDescriptorPool descriptorPool;
extern std::vector<VkDescriptorSet> descriptorSets;

extern VkImage depthImage;
extern VkDeviceMemory depthImageMemory;
extern VkImageView depthImageView;

extern VkImage textureImage;
extern VkDeviceMemory textureImageMemory;
extern VkImageView textureImageView;
extern VkSampler textureSampler;