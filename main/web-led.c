#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "portmacro.h"
#include "soc/gpio_num.h"

#define LED_PIN GPIO_NUM_2
#define DELAY 1000

void app_main(void)
{
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while(1) {
        gpio_set_level(LED_PIN, 1);
        vTaskDelay(DELAY / portTICK_PERIOD_MS);

        gpio_set_level(LED_PIN, 0);
        vTaskDelay(DELAY / portTICK_PERIOD_MS);
    }
}
