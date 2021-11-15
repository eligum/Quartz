#pragma once

#include <string>

namespace quartz {

    class Application
    {
    public:
        Application(const std::string& name = "Quartz App");
        virtual ~Application();

        void run();
    };

    // To be defined in CLIENT
    Application* createApplication();

} // namespace quartz
