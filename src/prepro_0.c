#include <stdio.h>

#define MUL(x,y) ((x)*(y))
#define MAX(x,y) (((x)>(y))?(x):(y))


inline int max(int x, int y){ return (x>y)?x:y; }


/*

// 假设我们正在编写跨平台代码
#if defined(_WIN32)  // Windows平台
    #include <windows.h>
    #define PLATFORM "Windows"
    
#elif defined(__linux__)  // Linux平台
    #include <unistd.h>
    #define PLATFORM "Linux"
    
#elif defined(__APPLE__)  // macOS平台
    #include <TargetConditionals.h>
    #define PLATFORM "macOS"
    
#else
    #error "Unsupported platform!"
#endif

*/