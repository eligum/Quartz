include "Dependencies.lua"

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

group "Dependencies"
	include "vendor/premake"
	include "Quartz/vendor/GLFW"
	include "Quartz/vendor/Glad"
	include "Quartz/vendor/imgui"
	include "Quartz/vendor/yaml-cpp"
group ""

include "Quartz"
-- include "Sandbox"
-- include "Hazelnut"
