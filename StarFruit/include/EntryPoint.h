#pragma once

#ifdef _WIN32

extern StarFruit::Application* StarFruit::CreateApplication();

int main() {

    StarFruit::Log::Init();
    SF_CORE_INFO("Initialized Core Log!");
    SF_CLIENT_WARN("Client log! Hello!");

    auto app = StarFruit::CreateApplication();  
    app->Run();
    delete app;

}

#endif
