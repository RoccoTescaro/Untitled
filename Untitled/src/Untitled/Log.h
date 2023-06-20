#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace unt 
{
	struct Log 
	{
		inline static std::shared_ptr<spdlog::logger> ENGINE;
		inline static std::shared_ptr<spdlog::logger> CLIENT;
		
		inline static void init() 
		{
			spdlog::set_pattern("[%T] [%n] [%^%l%$]: %v");

			ENGINE = spdlog::stdout_color_mt("ENGINE");
			ENGINE->set_level(spdlog::level::trace);
			CLIENT = spdlog::stdout_color_mt("CLIENT");
			CLIENT->set_level(spdlog::level::trace);
			
			auto console_sink = dynamic_cast<spdlog::sinks::stdout_color_sink_mt*>(ENGINE->sinks().back().get());
			console_sink->set_color(spdlog::level::trace, FOREGROUND_INTENSITY);
			console_sink->set_color(spdlog::level::info, FOREGROUND_INTENSITY);
			console_sink->set_color(spdlog::level::warn, FOREGROUND_RED | FOREGROUND_GREEN);
			console_sink->set_color(spdlog::level::err, FOREGROUND_RED | FOREGROUND_INTENSITY);
			console_sink->set_color(spdlog::level::critical, BACKGROUND_RED | BACKGROUND_INTENSITY);
		};

	};
}

#define UNT_TRACE(logger, ...)		unt::Log::logger->trace(__VA_ARGS__)
#define UNT_INFO(logger, ...)		unt::Log::logger->info(__VA_ARGS__)
#define UNT_WARN(logger, ...)		unt::Log::logger->warn(__VA_ARGS__)
#define UNT_ERROR(logger, ...)		unt::Log::logger->error(__VA_ARGS__)
#define UNT_CRITICAL(logger, ...)	unt::Log::logger->critical(__VA_ARGS__)

#ifdef UNT_DEBUG
	#define UNT_ASSERT(logger, x, ...) { if(!(x)) { UNT_ERROR(logger, "Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define UNT_ASSERT(logger, x, ...)
#endif 