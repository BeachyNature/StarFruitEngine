#pragma once

#include <Core.h>
#include <memory>
#include <stdio.h>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace StarFruit {

    class STARFRUIT_API Log {

        public :
            static void Init();
            inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
            inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

        private:
            static std::shared_ptr<spdlog::logger> s_CoreLogger;
            static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// Core Logging Macros
#define SF_CORE_FATAL(...) ::StarFruit::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define SF_CORE_ERROR(...) ::StarFruit::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SF_CORE_WARN(...)  ::StarFruit::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SF_CORE_INFO(...)  ::StarFruit::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SF_CORE_TRACE(...) ::StarFruit::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client Logging Macros
#define SF_FATAL(...) ::StarFruit::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define SF_ERROR(...) ::StarFruit::Log::GetClientLogger()->error(__VA_ARGS__)
#define SF_WARN(...)  ::StarFruit::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SF_INFO(...)  ::StarFruit::Log::GetClientLogger()->info(__VA_ARGS__)
#define SF_TRACE(...) ::StarFruit::Log::GetClientLogger()->trace(__VA_ARGS__)
