#define STARFRUIT_EXPORTS
#include "Application.h"
#include <stdio.h>

namespace StarFruit {

    Application::Application()
    {
        printf("Welcome to Starfruit Engine!\n");
        printf("Lets get started!\n");
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        while(true);
    }

}
