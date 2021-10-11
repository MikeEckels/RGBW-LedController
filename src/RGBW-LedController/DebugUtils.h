#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#define DEBUG

#ifndef SER
#define SER Serial
#endif

#ifdef DEBUG
#define DEBUG_BEGIN(...) SER.begin(__VA_ARGS__)
#define DEBUG_PRINT(...) SER.print(__VA_ARGS__)
#define DEBUG_PRINTLN(...) SER.println(__VA_ARGS__)
#define DEBUG_PRINT_ERR(...) DEBUG_PRINT("[!] ");  DEBUG_PRINTLN(__VA_ARGS__)
#define DEBUG_PRINT_INFO(...) DEBUG_PRINT("    ");  DEBUG_PRINTLN(__VA_ARGS__)
#define DEBUG_PRINT_INFO_NO_LN(...) DEBUG_PRINT("    "); DEBUG_PRINT(__VA_ARGS__)
#define DEBUG_PRINT_NOTICE(...) DEBUG_PRINT("[+] ");  DEBUG_PRINTLN(__VA_ARGS__)
#define DEBUG_PRINTF(...)SER.printf(__VA_ARGS__)
#define DEBUG_PRINT_FULL(...)  \
        SER.print(millis());     \
        SER.print(": ");    \
        SER.print(__PRETTY_FUNCTION__); \
        SER.print(' ');      \
        SER.print(__LINE__);     \
        SER.print(' ');      \
        SER.print(__VA_ARGS__)
#define DEBUG_PRINT_FULLLN(...)  \
        SER.print(millis());     \
        SER.print(": ");    \
        SER.print(__PRETTY_FUNCTION__); \
        SER.print(' ');      \
        SER.print(__LINE__);     \
        SER.print(' ');      \
        SER.println(__VA_ARGS__)
#else
#define DEBUG_BEGIN(...)
#define DEBUG_PRINT(...)
#define DEBUG_PRINTLN(...)
#define DEBUG_PRINT_ERR(...)
#define DEBUG_PRINT_INFO(...)
#define DEBUG_PRINT_INFO_NO_LN(...)
#define DEBUG_PRINT_NOTICE(...)
#define DEBUG_PRINTF(...)
#define DEBUG_PRINT_FULL(...)
#define DEBUG_PRINT_FULLLN(...)
#endif

#endif //DEBUG_UTILS_H
