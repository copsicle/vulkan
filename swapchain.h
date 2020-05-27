#pragma once

#include <array>

struct SwapChainSupportDetails
{
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
void createFramebuffers();
void initSwapChain();
VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);