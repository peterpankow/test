#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "fsl_iocon.h"
#include "fsl_common.h"
#include "board.h"

#include "pin_mux.h"

#define LED_GPIO GPIO0
#define LED_PIN  5U  // Beispiel: P0_5 – bitte anpassen je nach LED-Pin des Boards

void delay(void)
{
    for (volatile uint32_t i = 0; i < 3000000; i++) {
        __NOP();
    }
}

int main(void)
{
    CLOCK_EnableClock(kCLOCK_Gpio0);

    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput,
        0,
    };

    GPIO_PinInit(LED_GPIO, LED_PIN, &led_config);

    while (1) {
        GPIO_PortToggle(LED_GPIO, 1u << LED_PIN);
        delay();
    }
}
