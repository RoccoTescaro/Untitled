base_path = "../"

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

project_path = base_path .. "%{prj.name}"

project "Untitled"
    location (project_path)
    kind "StaticLib"
    
    files 
    {
        project_path .. "/src/**.h",
        project_path .. "/src/**.cpp", 
    }

    includedirs
    {
        project_path .. "/src",
        project_path .. "/lib/spdlog/include"
    }

project "Sandbox"
    location (project_path)
    kind "ConsoleApp"
    
    files 
    {
        project_path .. "/src/**.h",
        project_path .. "/src/**.cpp", 
    }

    includedirs
    {
        base_path .. "Untitled/src",
        base_path .. "Untitled/lib/spdlog/include" -- why ? --
    }

    links
    {
        "Untitled"
    }

