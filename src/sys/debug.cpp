#pragma once
#include <string.h>
#include "port.cpp"

#define ANSI_BLACK_FG "\033[30m"
#define ANSI_RED_FG "\033[31m"
#define ANSI_GREEN_FG "\033[32m"
#define ANSI_YELLOW_FG "\033[33m"
#define ANSI_BLUE_FG "\033[34m"
#define ANSI_MAGENTA_FG "\033[35m"
#define ANSI_CYAN_FG "\033[36m"
#define ANSI_WHITE_FG "\033[37m"

#define ANSI_BLACK_BG "\033[40m"
#define ANSI_RED_BG "\033[41m"
#define ANSI_GREEN_BG "\033[42m"
#define ANSI_YELLOW_BG "\033[43m"
#define ANSI_BLUE_BG "\033[44m"
#define ANSI_MAGENTA_BG "\033[45m"
#define ANSI_CYAN_BG "\033[46m"
#define ANSI_WHITE_BG "\033[47m"

#define ANSI_RESET "\033[0m"

void WriteCharDebug(char chr) {
    outb(0xE9, chr);
}

void PrintDebug(const char* string, const char* fg = ANSI_WHITE_FG, const char* bg = ANSI_BLACK_BG) {
    for (int i = 0; fg[i] != '\0'; i++) {
        WriteCharDebug(fg[i]);
    }
    for (int i = 0; bg[i] != '\0'; i++) {
        WriteCharDebug(bg[i]);
    }
    for (int i = 0; string[i] != '\0'; i++) {
        WriteCharDebug(string[i]);
    }
    for (int i = 0; ANSI_RESET[i] != '\0'; i++) {
        WriteCharDebug(ANSI_RESET[i]);
    }
}

void PrintlnDebug(const char* string, const char* fg = ANSI_WHITE_FG, const char* bg = ANSI_BLACK_BG) {
    PrintDebug(string, fg, bg);
    WriteCharDebug('\n');
}