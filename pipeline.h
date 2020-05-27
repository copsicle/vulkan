#pragma once

#include <fstream>

void initPipeline();
void createRenderPass();
void createGraphicsPipeline();
void createDepthResources();

VkFormat findDepthFormat();