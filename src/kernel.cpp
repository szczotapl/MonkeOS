#include "sys/term.cpp"
#include "sys/welcome.cpp"

extern "C" void kernel_main() {
    termInitialize();
    welcome();
}
