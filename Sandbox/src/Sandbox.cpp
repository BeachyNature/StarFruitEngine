#define STARFRUIT_EXPORTS
#include <StarFruit.h>
#include <stdio.h>

class SandBox : public StarFruit::Application
{
    public:
        SandBox() 
        {
            SF_CLIENT_INFO("Initialized Client Logger!");
        }

        ~SandBox()
        {
            SF_CLIENT_INFO("Closing SandBox Client..");
        }
};

StarFruit::Application* StarFruit::CreateApplication()
{
    return new SandBox();
}
