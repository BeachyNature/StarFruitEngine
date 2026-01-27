#pragma once

#ifdef _WIN32

extern StarFruit::Application* StarFruit::CreateApplication();

int main() {

    auto app = StarFruit::CreateApplication();  
    app->Run();
    delete app;

}

#endif
