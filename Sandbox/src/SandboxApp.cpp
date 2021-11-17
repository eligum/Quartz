#include <Quartz.hpp>
#include <quartz/core/EntryPoint.hpp>

class Sandbox : public quartz::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

quartz::Application* quartz::CreateApplication()
{
    return new Sandbox();
}
