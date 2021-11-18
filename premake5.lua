require("vendor/premake-export-cc/export-compile-commands")
require("vendor/premake-cmake/cmake")

workspace "Quartz"
	architecture "x86_64"
	location "build"
	-- startproject "Quartz-Editor"

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

group "dependencies"
	include "Quartz/vendor/GLFW"
-- 	include "Quartz/vendor/Glad"
-- 	include "Quartz/vendor/imgui"
-- 	include "Quartz/vendor/yaml-cpp"
group ""

include "Quartz"
include "Sandbox"
-- include "Quartz-Editor"
