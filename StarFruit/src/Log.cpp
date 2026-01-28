#define STARFRUIT_EXPORTS
#include "Log.h"

namespace StarFruit {

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        // StarFruits logger ---
        s_CoreLogger = spdlog::stdout_color_mt("StarFruit");
        s_CoreLogger->set_level(spdlog::level::trace);
        
        // Sandbox client logger ---
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }

}