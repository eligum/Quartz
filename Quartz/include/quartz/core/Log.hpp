#pragma once

#include "quartz/core/Base.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace quartz {

    class Log
    {
    public:
        static void init();

        static Ref<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
        static Ref<spdlog::logger>& getClientLogger() { return s_clientLogger; }

    private:
        static Ref<spdlog::logger> s_coreLogger;
        static Ref<spdlog::logger> s_clientLogger;
    };

} // namespace quartz

// Core log macros
#define HZ_CORE_TRACE(...)    ::quartz::Log::getCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)     ::quartz::Log::getCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)     ::quartz::Log::getCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)    ::quartz::Log::getCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_CRITICAL(...) ::quartz::Log::getCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define HZ_TRACE(...)         ::quartz::Log::getClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)          ::quartz::Log::getClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)          ::quartz::Log::getClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)         ::quartz::Log::getClientLogger()->error(__VA_ARGS__)
#define HZ_CRITICAL(...)      ::quartz::Log::getClientLogger()->critical(__VA_ARGS__)
