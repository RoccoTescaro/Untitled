base_path = "../"
project_path = base_path .. "%{prj.name}"

workspace "Untitled"
    location (base_path)
    configurations {"Debug", "Release", "Distribution"}
    architecture "x64"
    targetdir (base_path .. "_bin/%{cfg.buildcfg}/%{prj.name}")
    objdir (base_path .. "_int/%{cfg.buildcfg}/%{prj.name}")
    startproject "Sandbox"
    staticruntime "on"
    language "C++"
    cppdialect "C++20"
    systemversion "latest"

    files 
    {
        project_path .. "/**.h",
        project_path .. "/**.cpp", 
    }

    includedirs
    {
        base_path .. "Untitled/src",
        base_path .. "lib/spdlog/include",
        base_path .. "lib/glfw/include",
    }

    filter "configurations:Debug"
        defines "UNT_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "UNT_RELEASE"
        runtime "Release"
        symbols "on"
        optimize "on"

    filter "configurations:Distribution"
        defines "UNT_DISTRIBUTION"
        runtime "Release"
        optimize "on"


project "Untitled"
    location (project_path)
    kind "StaticLib"

    pchheader "pch.h"
    pchsource (project_path .. "/src/pch.cpp")

    links { "spdlog", "glfw", "opengl32.lib" }


project "Sandbox"
    location (project_path)
    kind "ConsoleApp"
    
    links { "Untitled" }


include (base_path .. "lib/spdlog")
include (base_path .. "lib/glfw")