VULKAN_SDK_PATH = /mnt/c/VulkanSDK/1.2.135.0/x86_64

PROG = VK3D

CC = g++
CFLAGS = -std=c++17 -g -Wall -I$(VULKAN_SDK_PATH)/include
LDFLAGS = -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan

OBJS = main.o glfw.o cleanup.o

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS) 

main.o:
	$(CC) $(CFLAGS) -c main.cpp

glfw.o: glfw.h
	$(CC) $(CFLAGS) -c glfw.cpp

cleanup.o: cleanup.h
	$(CC) $(CFLAGS) -c cleanup.cpp

.PHONY: test clean

test: VulkanTest
	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_SDK_PATH)/etc/vulkan/explicit_layer.d ./VK3D

clean:
	rm -f $(PROG) $(OBJS)