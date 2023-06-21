project "spdlog"
    location ("")
    kind "StaticLib"

    files 
    {
        "include/spdlog/spdlog.h",
        "include/spdlog/sinks/stdout_color_sinks.h",
        "src/spdlog.cpp",
    }

    defines { "SPDLOG_COMPILED_LIB", "_CRT_SECURE_NO_WARNINGS" }

