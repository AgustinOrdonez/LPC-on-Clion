#include <cstdint>
#include "LPC845.h"

#define CLK_GPIO1 18
#define CLK_IOCON 20

#define PORT 1
#define BIT 1

int main() {
    // Enable GPIO0, IOCON clocks
    SYSCON->SYSAHBCLKCTRL0 |= (1 << CLK_GPIO1) | (1 << CLK_IOCON);

    // Set pin 1.1(BLUE LED) to output
    GPIO->DIRSET[PORT] |= (1 << BIT);

    while (true) {
        // Toggle pin 1.1(BLUE LED)
        GPIO->NOT[PORT] |= (1 << BIT);
        // Delay
        for (uint32_t i = 0; i < 1000000; i++) {
            __asm("nop");
        }
    }
    return 0;
}
