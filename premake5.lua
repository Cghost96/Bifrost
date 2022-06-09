workspace "Bifrost"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bifrost"
	location "Bifrost"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BF_PLATFORM_WINDOWS",
			"BF_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "BF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BF_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "BF_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Bifrost/vendor/spdlog/include",
		"Bifrost/src"
	}

	links
	{
		"Bifrost"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BF_DIST"
		optimize "On" 