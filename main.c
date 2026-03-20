#include <stdint.h>

#define GPIO0_BASE 0x40001000UL
#define GPIO_PORT0_DIR (*(volatile uint32_t*)(GPIO0_BASE + 0x2000))
#define GPIO_PORT0_PIN (*(volatile uint32_t*)(GPIO0_BASE + 0x3000))

#define LED_PIN (5U)  // Beispiel: P0_5 → ggf. anpassen für deine LED

static void delay(void)
{
    for (volatile uint32_t i = 0; i < 500000; i++) {
        __asm__("nop");
    }
}

int main(void)
{
    // GPIO 0: Pin als Ausgang konfigurieren
    GPIO_PORT0_DIR |= (1U << LED_PIN);

    while (1) {
        // Toggle LED
        GPIO_PORT0_PIN ^= (1U << LED_PIN);
        delay();
    }
}
