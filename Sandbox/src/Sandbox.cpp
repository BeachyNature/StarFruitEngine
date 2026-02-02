#define STARFRUIT_EXPORTS
#include <StarFruit.h>

class SandBox : public StarFruit::Application
{
    public:
        SandBox() 
        {
            SF_INFO("Initialized Client Logger...");
        }

        ~SandBox()
        {
            SF_INFO("Closing SandBox Client...");
        }
};

StarFruit::Application* StarFruit::CreateApplication()
{
    return new SandBox();
}
