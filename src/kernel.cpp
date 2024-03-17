#include "sys/term.cpp"
#include "sys/debug.cpp"
#include "sys/ANSIColor.hpp"
#include "sys/config.h"

extern "C" void kernel_main() {
    termInitialize();
    PrintlnDebug("Debug test!", ANSI_YELLOW_FG, ANSI_BLACK_BG);
    termWriteLine("         .-\"-.");
    termWriteLine("       _/.-.-.\\_");
    termWriteLine("      ( ( o o ) )");
    termWriteLine("       |/  \"  \\|    Monke Stronk");
    termWriteLine("        \\'/^'/'");
    termWriteLine("        /`\\ /`\\");
    termWriteLine("       /  /|\\  \\");
    termWriteLine("      ( (/ T \\) )");
    termWriteLine("         \\__/^\\__/");
    termWriteOK("Booted MonkeOS ");
    termWriteLineOK(monkeversion);
}
