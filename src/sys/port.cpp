#pragma once
#include <stdint.h>

inline void outb(uint16_t port, uint8_t val)
{
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

inline uint8_t inb(uint16_t port)
{
    uint8_t return_;
    asm volatile ("inb %1, %0" : "=a"(return_) : "Nd"(port));
    return return_;
}