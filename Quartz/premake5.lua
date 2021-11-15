project "Quartz"
	location "../build"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	-- pic "On"

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
		"vendor/glm/include"
	}

	filter "system:linux"
		systemversion "latest"

	filter "configurations:Debug"
		defines "QZ_DEBUG"
		runtime "Debug"
		symbols "on"

		-- links
		-- {
			-- "%{Library.ShaderC_Debug}",
			-- "%{Library.SPIRV_Cross_Debug}",
			-- "%{Library.SPIRV_Cross_GLSL_Debug}"
		-- }

	filter "configurations:Release"
		defines "QZ_RELEASE"
		runtime "Release"
		optimize "on"

		-- links
		-- {
			-- "%{Library.ShaderC_Release}",
			-- "%{Library.SPIRV_Cross_Release}",
			-- "%{Library.SPIRV_Cross_GLSL_Release}"
		-- }

	filter "configurations:Dist"
		defines "QZ_DIST"
		runtime "Release"
		optimize "on"

		-- links
		-- {
			-- "%{Library.ShaderC_Release}",
			-- "%{Library.SPIRV_Cross_Release}",
			-- "%{Library.SPIRV_Cross_GLSL_Release}"
		-- }
