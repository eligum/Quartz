project "Quartz"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"
	location "../build"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"include/**.hpp",
		"src/**.cpp"
	}

	includedirs
	{
		"include",
		"vendor/spdlog/include",
		"vendor/glm/include",
		"vendor/GLFW/include"
	}

	filter "system:linux"
		systemversion "latest"

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "QZ_DEBUG"
		runtime "Debug"
		symbols "On"

		-- links
		-- {
			-- "%{Library.ShaderC_Debug}",
			-- "%{Library.SPIRV_Cross_Debug}",
			-- "%{Library.SPIRV_Cross_GLSL_Debug}"
		-- }

	filter "configurations:Release"
		defines "QZ_RELEASE"
		runtime "Release"
		optimize "On"

		-- links
		-- {
			-- "%{Library.ShaderC_Release}",
			-- "%{Library.SPIRV_Cross_Release}",
			-- "%{Library.SPIRV_Cross_GLSL_Release}"
		-- }

	filter "configurations:Dist"
		defines "QZ_DIST"
		runtime "Release"
		optimize "On"

		-- links
		-- {
			-- "%{Library.ShaderC_Release}",
			-- "%{Library.SPIRV_Cross_Release}",
			-- "%{Library.SPIRV_Cross_GLSL_Release}"
		-- }
