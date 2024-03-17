#pragma once
#include <string.h>
#include "port.cpp"

void WriteCharDebug(char chr) {
    outb(0xE9, chr);
}

void PrintDebug(const char* string) {
    for (int i = 0; string[i] != '\0'; i++) {
        WriteCharDebug(string[i]);
    }
}

void PrintlnDebug(const char* string) {
    PrintDebug(string);
    WriteCharDebug('\n');
}