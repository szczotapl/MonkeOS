#include <cstddef>
#include <cstdint>
#include <cstring>
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

constexpr size_t VGA_WIDTH = 80;
constexpr size_t VGA_HEIGHT = 25;

size_t termRow;
size_t termColumn;
uint8_t termColor;
uint16_t* termBuffer;

void termInitialize() {
    termRow = 0;
    termColumn = 0;
    termColor = makeColor(VGAColor::LightGrey, VGAColor::Black);
    termBuffer = reinterpret_cast<uint16_t*>(0xB8000);
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            termBuffer[index] = makeVGAEntry(' ', termColor);
        }
    }
}

void termPutChar(char c) {
    if (c == '\n') {
        termColumn = 0;
        if (++termRow == VGA_HEIGHT) {
            for (size_t y = 1; y < VGA_HEIGHT; y++) {
                for (size_t x = 0; x < VGA_WIDTH; x++) {
                    const size_t destIndex = (y - 1) * VGA_WIDTH + x;
                    const size_t srcIndex = y * VGA_WIDTH + x;
                    termBuffer[destIndex] = termBuffer[srcIndex];
                }
            }
            for (size_t x = 0; x < VGA_WIDTH; x++) {
                const size_t index = (VGA_HEIGHT - 1) * VGA_WIDTH + x;
                termBuffer[index] = makeVGAEntry(' ', termColor);
            }
            termRow = VGA_HEIGHT - 1;
        }
    } else {
        const size_t index = termRow * VGA_WIDTH + termColumn;
        termBuffer[index] = makeVGAEntry(c, termColor);
        if (++termColumn == VGA_WIDTH) {
            termColumn = 0;
            if (++termRow == VGA_HEIGHT) {
                    termRow = 0;
                }
            }
    }
}

void write(const char* data) {
    for (size_t i = 0; data[i] != '\0'; i++)
        termPutChar(data[i]);
}

void writeLine(const char* data) {
    write(data);
    write("\n");
}

void writeError(const char* message) {
    termColor = makeColor(VGAColor::Red, VGAColor::Black);
    write("[ Error ] ");
    termColor = makeColor(VGAColor::LightGrey, VGAColor::Black);
    writeLine(message);
}

void writeInfo(const char* message) {
    termColor = makeColor(VGAColor::Cyan, VGAColor::Black);
    write("[ Info ] ");
    termColor = makeColor(VGAColor::LightGrey, VGAColor::Black);
    writeLine(message);
}

void writeWarn(const char* message) {
    termColor = makeColor(VGAColor::LightRed, VGAColor::Black);
    write("[ Warning ] ");
    termColor = makeColor(VGAColor::LightGrey, VGAColor::Black);
    writeLine(message);
}

extern "C" void kernel_main() {
    termInitialize();
    writeLine("         .-\"-.");
    writeLine("       _/.-.-.\\_");
    writeLine("      ( ( o o ) )");
    writeLine("       |/  \"  \\|    Monke Stronk");
    writeLine("        \\'/^'/'");
    writeLine("        /`\\ /`\\");
    writeLine("       /  /|\\  \\");
    writeLine("      ( (/ T \\) )");
    writeLine("         \\__/^\\__/");
    writeInfo("Booted MonkeOS!");
    writeError("Still under development");
    writeWarn("Test warn");
}
