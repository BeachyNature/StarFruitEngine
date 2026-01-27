#ifdef _WIN32
    #ifdef STARFRUIT_EXPORTS
        #define STARFRUIT_API __declspec(dllexport)
    #else
        #define STARFRUIT_API __declspec(dllimport)
    #endif
#else
    #define STARFRUIT_API
#endif
