#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace DreamNGN {
	class DN_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;



	};
}


// Core Log macros
#define DN_CORE_TRACE( ... )	::DreamNGN::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DN_CORE_WARN( ... )		::DreamNGN::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DN_CORE_INFO( ... )		::DreamNGN::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DN_CORE_ERROR( ... )	::DreamNGN::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DN_CORE_FATAL( ... )	::DreamNGN::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define DN_TRACE( ... )			::DreamNGN::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DN_WARN( ... )			::DreamNGN::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DN_INFO( ... )			::DreamNGN::Log::GetClientLogger()->info(__VA_ARGS__)
#define DN_ERROR( ... )			::DreamNGN::Log::GetClientLogger()->error(__VA_ARGS__)
#define DN_FATAL( ... )			::DreamNGN::Log::GetClientLogger()->fatal(__VA_ARGS__)