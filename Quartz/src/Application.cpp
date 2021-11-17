#include "quartz/core/Application.hpp"
#include <GLFW/glfw3.h>

namespace quartz {

    Application::Application(const std::string& name)
    {
        glfwInit();
        glfwTerminate();
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (true) {}
    }

} // namespace quartz
