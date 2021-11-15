#pragma once

#include "quartz/core/Base.hpp"
#include "quartz/core/Application.hpp"

extern quartz::Application* quartz::createApplication();

int main(int argc, char** argv)
{
    quartz::Log::init();
    QZ_CORE_INFO("Logger initialized!");
    QZ_CORE_WARN("All output is being written to a log file.");

    auto app = quartz::createApplication();
    app->run();
    delete app;
}
