#include "quartz/core/Log.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace quartz {

	Ref<spdlog::logger> Log::s_core_logger_;
	Ref<spdlog::logger> Log::s_client_logger_;

	void Log::Init()
	{
		std::vector<spdlog::sink_ptr> log_sinks;
		log_sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		log_sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Quartz.log", true));

		log_sinks[0]->set_pattern("[%T]%^ %n: %v%$");
		log_sinks[1]->set_pattern("[%T] [%l] %n: %v");

		s_core_logger_ = std::make_shared<spdlog::logger>("QUARTZ", begin(log_sinks), end(log_sinks));
		spdlog::register_logger(s_core_logger_);
		s_core_logger_->set_level(spdlog::level::trace);
		s_core_logger_->flush_on(spdlog::level::trace);

		s_client_logger_ = std::make_shared<spdlog::logger>("APP", begin(log_sinks), end(log_sinks));
		spdlog::register_logger(s_client_logger_);
		s_client_logger_->set_level(spdlog::level::trace);
		s_client_logger_->flush_on(spdlog::level::trace);
	}

}
