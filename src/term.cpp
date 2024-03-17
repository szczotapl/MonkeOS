#pragma once

#include <stdint.h>
#include <stddef.h>
#include <string.h>

enum class VGAColor : uint8_t {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGrey = 7,
    DarkGrey = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    LightBrown = 14,
    White = 15
};

uint8_t makeColor(VGAColor fg, VGAColor bg) {
    return static_cast<uint8_t>(fg) | static_cast<uint8_t>(bg) << 4;
}

uint16_t makeVGAEntry(char c, uint8_t color) {
    uint16_t c16 = c;
    uint16_t color16 = color;
    return c16 | color16 << 8;
}

const size_t VGA_COLS = 80;
const size_t VGA_ROWS = 25;

size_t termRow = 0;
size_t termColumn = 0;
uint8_t defaultColor;
uint16_t* termBuffer = (uint16_t)0xb8000;

void termClearScreen(uint8_t color = defaultColor) {
    for (uint16_t pos = 0; pos < VGA_ROWS VGA_COLS; pos++) {
        termBuffer[pos] = makeVGAEntry(' ', color);
    }
}

void termInitialize() {
    defaultColor = makeColor(VGAColor::LightGrey, VGAColor::Black);
    termClearScreen(defaultColor);
}

void termPutChar(char c, uint8_t color = defaultColor) {
    if (c == '\n') {
        termColumn = 0;
        if (++termRow == VGA_ROWS) {
            for (size_t y = 1; y < VGA_ROWS; y++) {
                for (size_t x = 0; x < VGA_COLS; x++) {
                    const size_t destIndex = (y - 1) * VGA_COLS + x;
                    const size_t srcIndex = y * VGA_COLS + x;
                    termBuffer[destIndex] = termBuffer[srcIndex];
                }
            }
            for (size_t x = 0; x < VGA_COLS; x++) {
                const size_t index = (VGA_ROWS - 1) * VGA_COLS + x;
                termBuffer[index] = makeVGAEntry(' ', color);
            }
            termRow = VGA_ROWS - 1;
        }
    } else {
        const size_t index = termRow * VGA_COLS + termColumn;
        termBuffer[index] = makeVGAEntry(c, color);
        if (++termColumn == VGA_COLS) {
            termColumn = 0;
            if (++termRow == VGA_ROWS) {
                    termRow = 0;
                }
            }
    }
}

void termWrite(const char* data, uint8_t color = defaultColor) {
    for (size_t i = 0; data[i] != '\0'; i++)
        termPutChar(data[i], color);
}

void termWriteLine(const char* data, uint8_t color = defaultColor) {
    termWrite(data, color);
    termWrite("\n");
}

void termWriteError(const char* message, uint8_t color = defaultColor) {
    termWrite("[ERR] ", makeColor(VGAColor::Red, VGAColor::Black));
    termWriteLine(message, color);
}

void termWriteInfo(const char* message, uint8_t color = defaultColor) {
    termWrite("[INFO] ", makeColor(VGAColor::LightCyan, VGAColor::Black));
    termWriteLine(message, color);
}

void termWriteWarn(const char* message, uint8_t color = defaultColor) {
    termWrite("[WARN] ", makeColor(VGAColor::LightBrown, VGAColor::Black));
    termWriteLine(message, color);
}