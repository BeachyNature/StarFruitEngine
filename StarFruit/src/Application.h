#pragma once

#include <Core.h>

namespace StarFruit {

  class STARFRUIT_API Application {
  
    public:
      Application();
      virtual ~Application();
      void Run();
  
  };

  Application* CreateApplication();

}
