workspace "Engine"
	configurations { "Debug", "Release" }
	startproject "Game"

project "Engine"
	kind "StaticLib"
	location "%{prj.name}"
    language "C++"
	architecture "x64"
	targetdir "bin/%{prj.name}/%{cfg.buildcfg}"
	libdirs "%{prj.name}/libs"
	links {"SDL2.lib","SDL2main.lib","assimp-vc142-mtd.lib","glew32.lib","SOIL.lib"}
	includedirs {"%{prj.name}/src","%{prj.name}/include/sdl", "%{prj.name}/include/soil", "%{prj.name}/include/glm", "%{prj.name}/include/glew", "%{prj.name}/include/assimp"}

	vpaths {
    ["Headers"] = { "**.h", "**.hpp" },
    ["Sources"] = {"**.c", "**.cpp"},
	["Shaders"] = {"**.vs", "**.frag"},
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

project "Game"
	kind "ConsoleApp"
	location "%{prj.name}"
	language "C++"
	architecture "x64"
	targetdir "bin/%{prj.name}/%{cfg.buildcfg}"
	libdirs "bin/Engine/%{cfg.buildcfg}"
	links {"Engine.lib"}
	includedirs{"%{wks.location}/Engine/src", "%{wks.location}/Engine/include/sdl", "%{wks.location}/Engine/include/glm", 
	"%{wks.location}/Engine/include/glew", "%{wks.location}/Engine/include/soil", "%{wks.location}/Engine/include/assimp"}
	postbuildcommands{
		("{COPY} %{wks.location}/%{prj.name}/dll/ %{wks.location}bin/%{prj.name}/%{cfg.buildcfg}")
	}
	vpaths {
    ["Headers"] = { "**.h", "**.hpp" },
    ["Sources"] = {"**.c", "**.cpp"},
	["Shaders"] = {"**.vs", "**.frag"},
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