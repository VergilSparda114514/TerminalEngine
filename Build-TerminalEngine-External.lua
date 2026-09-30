VULKAN_SDK = os.getenv("VULKAN_SDK")
FTXUI_DIR = "../vendor/FTXUI"

IncludeDir = {}
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"
IncludeDir["glm"] = "../vendor/glm"
IncludeDir["FTXUI"] = "%{FTXUI_DIR}/include"

LibraryDir = {}
LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["FTXUI"] = "%{FTXUI_DIR}/bin/" .. outputdir .. "/FTXUI"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["ShaderC"] = "%{LibraryDir.VulkanSDK}/shaderc_combined.lib"
Library["FTXUI_Screen"] = "%{LibraryDir.FTXUI}/ftxui-screen.lib"
Library["FTXUI_DOM"] = "%{LibraryDir.FTXUI}/ftxui-dom.lib"
Library["FTXUI_Component"] = "%{LibraryDir.FTXUI}/ftxui-component.lib"

group "Dependencies"
   include "vendor/FTXUI"
   include "vendor/yaml-cpp"
group ""

group "Core"
    include "TECore/Build-TECore.lua"
group ""