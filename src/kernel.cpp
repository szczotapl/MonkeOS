#include "term.cpp"
#include "debug.cpp"

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
    termWriteOK("Booted MonkeOS!");
}
