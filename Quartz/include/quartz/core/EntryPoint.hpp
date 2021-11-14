#pragma once

#include "quartz/core/Base.hpp"
#include "quartz/core/Application.hpp"

extern quartz::Application* quartz::createApplication();

int main(int argc, char** argv)
{
    quartz::Log::init();

    auto app = quartz::createApplication();
    app->run();
    delete app;
}
