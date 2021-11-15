project "Sandbox"
    location "../build"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

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
		"Quartz"
	}

	filter "system:linux"
		systemversion "latest"

	filter "configurations:Debug"
		defines "QZ_DEBUG"
		runtime "Debug"
		symbols "on"

		-- postbuildcommands
		-- {
		-- 	"{COPYDIR} \"%{LibraryDir.VulkanSDK_DebugDLL}\" \"%{cfg.targetdir}\""
		-- }

	filter "configurations:Release"
		defines "QZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QZ_DIST"
		runtime "Release"
		optimize "on"
