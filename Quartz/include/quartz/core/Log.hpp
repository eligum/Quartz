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
        static void Init();

        static Ref<spdlog::logger>& GetCoreLogger() { return s_core_logger_; }
        static Ref<spdlog::logger>& GetClientLogger() { return s_client_logger_; }

    private:
        static Ref<spdlog::logger> s_core_logger_;
        static Ref<spdlog::logger> s_client_logger_;
    };

} // namespace quartz

// Core log macros
#define QZ_CORE_TRACE(...)    ::quartz::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QZ_CORE_INFO(...)     ::quartz::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QZ_CORE_WARN(...)     ::quartz::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QZ_CORE_ERROR(...)    ::quartz::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QZ_CORE_CRITICAL(...) ::quartz::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define QZ_TRACE(...)         ::quartz::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QZ_INFO(...)          ::quartz::Log::GetClientLogger()->info(__VA_ARGS__)
#define QZ_WARN(...)          ::quartz::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QZ_ERROR(...)         ::quartz::Log::GetClientLogger()->error(__VA_ARGS__)
#define QZ_CRITICAL(...)      ::quartz::Log::GetClientLogger()->critical(__VA_ARGS__)
