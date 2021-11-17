#pragma once

#include "quartz/core/Base.hpp"
#include "quartz/core/Application.hpp"

extern quartz::Application* quartz::CreateApplication();

int main(int argc, char** argv)
{
    quartz::Log::Init();
    QZ_CORE_INFO("Logger initialized!");
    QZ_CORE_WARN("All output is being written to a log file.");

    auto app = quartz::CreateApplication();
    app->Run();
    delete app;
}
