// Dynamic Import System
#ifdef _WIN32
    #ifdef STARFRUIT_EXPORTS
        #define STARFRUIT_API __declspec(dllexport)
    #else
        #define STARFRUIT_API __declspec(dllimport)
    #endif
#else
    #define STARFRUIT_API
#endif

// Include Sources
#include <string>
#include <sstream>
#include <functional>

// Macros
#define BIT(x) (1 << x)
