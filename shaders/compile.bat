@echo off
for /r %%i in (*.frag, *.vert) do C:/VulkanSDK/1.2.135.0/Bin/glslc %%i -o %%~ni.spv