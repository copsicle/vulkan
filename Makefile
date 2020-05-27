VULKAN_SDK_PATH = /mnt/c/VulkanSDK/1.2.135.0/x86_64
GLFW_PATH = "/mnt/c/Users/Gonen/Documents/Visual Studio 2019/Libraries/glfw/include"

PROG = VK3D

CC = g++
CFLAGS = -std=c++17 -Wall -I$(VULKAN_SDK_PATH)/include -I$(GLFW_PATH)
LDFLAGS = -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan

OBJS = buffers.o cleanup.o commands.o descriptors.o devices.o glfw.o main.o model.o pipeline.o setup.o swapchain.o sync.o
DEPS = buffers.h cleanup.h commands.h descriptors.h devices.h glfw.h objects.h model.h pipeline.h setup.h swapchain.h sync.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: test clean

test: VulkanTest
	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_SDK_PATH)/etc/vulkan/explicit_layer.d ./VK3D

clean:
	rm -f $(PROG) $(OBJS)