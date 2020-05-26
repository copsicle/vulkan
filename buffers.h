#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <chrono>

struct UniformBufferObject
{
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;
};

const std::vector<Vertex> vertices =
{
	{{-0.9f, -0.9f}, {1.0f, 0.0f, 0.0f}},
	{{0.9f, -0.9f}, {0.0f, 1.0f, 0.0f}},
	{{0.9f, 0.9f}, {0.0f, 0.0f, 1.0f}},
	{{-0.9f, 0.9f}, {1.0f, 0.0f, 1.0f}}
};

const std::vector<uint32_t> indices =
{
	0, 1, 2, 2, 3, 0
};

void initBuffers();