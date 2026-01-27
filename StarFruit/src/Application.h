#pragma once

#include "Core.h"

namespace StarFruit {

  class STARFRUIT_API Application {
    private:
      int test = 10;

    public:
      Application();
      virtual ~Application();
      void Run();
  };

  Application* CreateApplication();

}
