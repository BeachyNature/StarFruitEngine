#define STARFRUIT_EXPORTS
#include <StarFruit.h>

class SandBox : public StarFruit::Application
{
    public:
        SandBox() 
        {

        }

        ~SandBox()
        {

        }
};

StarFruit::Application* StarFruit::CreateApplication()
{
    return new SandBox();
}
