project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"
    location "../build"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.hpp",
		"src/**.cpp"
	}

	includedirs
	{
		"../Quartz/include",
		"../Quartz/vendor/spdlog/include"
		-- "%{wks.location}/Hazel/vendor/spdlog/include",
		-- "%{wks.location}/Hazel/vendor",
		-- "%{IncludeDir.glm}",
		-- "%{IncludeDir.entt}"
	}

	links
	{
		"Quartz",
		"GLFW"
	}

	filter "system:linux"
		systemversion "latest"
		links
		{
			"X11",
			"Xrandr",
			"Xi",
			"pthread",
			"dl"
		}

	filter "system:windows"
		systemversion "latest"
		links
		{
			"opengl32"
		}

	filter "configurations:Debug"
		defines "QZ_DEBUG"
		runtime "Debug"
		symbols "On"

		-- postbuildcommands
		-- {
		-- 	"{COPYDIR} \"%{LibraryDir.VulkanSDK_DebugDLL}\" \"%{cfg.targetdir}\""
		-- }

	filter "configurations:Release"
		defines "QZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "QZ_DIST"
		runtime "Release"
		optimize "On"
