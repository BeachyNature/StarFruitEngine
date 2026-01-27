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

int main() {

    SandBox* sandbox = new SandBox();
    sandbox->Run();
    delete sandbox;
}
