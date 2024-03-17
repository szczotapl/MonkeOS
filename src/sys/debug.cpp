#pragma once
#include <string.h>
#include "port.cpp"
#include "ANSIColor.hpp"

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