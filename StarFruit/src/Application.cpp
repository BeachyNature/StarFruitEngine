#define STARFRUIT_EXPORTS
#include "Application.h"
#include "events/ApplicationEvent.h"
#include "Log.h"

namespace StarFruit {

    Application::Application()
    {
        SF_CORE_INFO("Welcome to Starfruit Engine!");
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        WindowResizeEvent e(1200, 720);
        SF_CORE_TRACE(e);

        while(true);
    }

}
