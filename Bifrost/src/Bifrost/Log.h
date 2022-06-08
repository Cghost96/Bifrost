#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Bifrost
{

	class BIFROST_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define BF_CORE_TRACE(...)    ::Bifrost::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BF_CORE_INFO(...)     ::Bifrost::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BF_CORE_WARN(...)     ::Bifrost::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BF_CORE_ERROR(...)    ::Bifrost::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BF_CORE_FATAL(...)    ::Bifrost::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define BF_TRACE(...)	      ::Bifrost::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BF_INFO(...)	      ::Bifrost::Log::GetClientLogger()->info(__VA_ARGS__)
#define BF_WARN(...)	      ::Bifrost::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BF_ERROR(...)	      ::Bifrost::Log::GetClientLogger()->error(__VA_ARGS__)
#define BF_FATAL(...)	      ::Bifrost::Log::GetClientLogger()->fatal(__VA_ARGS__) 