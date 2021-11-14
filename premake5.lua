workspace "Quartz"
	architecture "x64"
	location "build"
	-- startproject "Hazelnut"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- group "Dependencies"
-- 	include "vendor/premake"
-- 	include "Hazel/vendor/GLFW"
-- 	include "Hazel/vendor/Glad"
-- 	include "Hazel/vendor/imgui"
-- 	include "Hazel/vendor/yaml-cpp"
-- group ""

include "Quartz"
-- include "Sandbox"
-- include "Hazelnut"
