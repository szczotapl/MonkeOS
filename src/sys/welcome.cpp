#include "term.cpp"
#include "config.hpp"
#include "ANSIColor.hpp"
#include "debug.cpp"

void welcome() {
    PrintlnDebug("Booted MonkeOS.", ANSI_GREEN_FG, ANSI_BLACK_BG);
    PrintlnDebug("Poland Strong!!!", ANSI_WHITE_FG, ANSI_RED_BG);
    termWriteLine(" =====================================================");
    termWrite("|                       MonkeOS ");
    termWrite(monkeversion);
    termWriteLine("                   |");
    termWriteLine(" =====================================================");
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
    termWrite(monkeversion);
    termWrite(" ");
    if (monkeAlpha) {
        termWriteLine("alpha");
    } else if (monkeBeta) {
        termWriteLine("beta");
    }
}