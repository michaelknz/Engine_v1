workspace "Engine"
	configurations { "Debug", "Release" }

project "Engine"
	kind "WindowedApp"
    language "C++"
	architecture "x86"
	targetdir "bin/%{prj.name}/%{cfg.buildcfg}"
	libdirs "libs"
	links {"glew32.lib", "glew32s.lib","SDL2.lib","SDL2main.lib","SDL2test.lib"}
	includedirs "include"
	postbuildcommands{
		("{COPY} %{wks.location}dll/ %{wks.location}bin/%{prj.name}/%{cfg.buildcfg}")
	}

	vpaths {
    ["Headers"] = { "**.h", "**.hpp" },
    ["Sources"] = {"**.c", "**.cpp"},
    }

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"}

	filter { "configurations:Debug" }
		symbols "On"

	filter { "configurations:Release" }
		optimize "On"

	filter { "system:windows" }
		links { "OpenGL32" }

	filter { "system:not windows" }
		links { "GL" }
