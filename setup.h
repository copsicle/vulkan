#pragma once

#ifdef NDEBUG
const bool enableValidationLayers{ false };
#else
const bool enableValidationLayers{ true };
#endif

const std::vector<const char*> validationLayers
{
	"VK_LAYER_KHRONOS_validation"
};

void initVulkan();
void recreateSwapChain();