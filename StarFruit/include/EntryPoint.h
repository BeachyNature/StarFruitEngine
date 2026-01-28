#pragma once

#ifdef _WIN32

extern StarFruit::Application* StarFruit::CreateApplication();

int main() {

    StarFruit::Log::Init();
    SF_CORE_INFO("Initialized Core Logger...");

    auto app = StarFruit::CreateApplication();  
    app->Run();
    delete app;
    return 0;
}

#endif
