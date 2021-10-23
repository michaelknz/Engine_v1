workspace "Engine"
	configurations { "Debug", "Release" }

project "Engine"
	kind "ConsoleApp"
	location "Engine"
    language "C++"
	architecture "x64"
	targetdir "bin/%{prj.name}/%{cfg.buildcfg}"
	libdirs "libs"
	links {"SDL2.lib","SDL2main.lib","assimp-vc142-mtd.lib","glew32.lib","SOIL.lib"}
	includedirs {"include/sdl","include/assimp", "include/glew", "include/glm", "include/soil"}
	postbuildcommands{
		("{COPY} %{wks.location}dll/ %{wks.location}bin/%{prj.name}/%{cfg.buildcfg}")
	}

	vpaths {
    ["Headers"] = { "**.h", "**.hpp" },
    ["Sources"] = {"**.c", "**.cpp"},
	["Shaders"] = {"**.vs", "**.frag"},
	["Libs"] = {"glad.c"}
    }

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/shaders/**.vs",
		"%{prj.name}/src/shaders/**.frag"}

	filter { "configurations:Debug" }
		symbols "On"

	filter { "configurations:Release" }
		optimize "On"

	filter { "system:windows" }
		links { "OpenGL32" }

	filter { "system:not windows" }
		links { "GL" }
