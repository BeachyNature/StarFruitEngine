#define STARFRUIT_EXPORTS
#include "sfpch.h"
#include "Log.h"
#include "Application.h"
#include "events/ApplicationEvent.h"

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
        if (e.IsInCategory(EventCategoryApp)){
            SF_CORE_TRACE(e);
        }

        while(true);
    }

}
