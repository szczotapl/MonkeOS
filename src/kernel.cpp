#include "sys/term.cpp"
#include "sys/debug.cpp"
#include "sys/ANSIColor.hpp"
#include "sys/config.hpp"

extern "C" void kernel_main() {
    termInitialize();
    PrintlnDebug("Booted MonkeOS.", ANSI_GREEN_FG, ANSI_BLACK_BG);
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
    termWriteLine(monkeversion);
}
