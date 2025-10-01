#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

// กำหนดขา GPIO สำหรับ LED ทั้ง 8 ดวง
LED led1(16);
LED led2(17);
LED led3(5);
LED led4(18);
LED led5(19);
LED led6(21);
LED led7(22);
LED led8(23);

void ALL_LED_OFF()
{
    led1.OFF();
    led2.OFF();
    led3.OFF();
    led4.OFF();
    led5.OFF();
    led6.OFF();
    led7.OFF();
    led8.OFF();
}

extern "C" void app_main(void)
{
    LED leds[] = {led1, led2, led3, led4, led5, led6, led7, led8};
    int num_leds = sizeof(leds) / sizeof(leds[0]);

    while (1)
    {
        // วิ่งไปข้างหน้า (จากซ้ายไปขวา)
        for (int i = 0; i < num_leds; i++)
        {
            ALL_LED_OFF();
            leds[i].ON();
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }

        // วิ่งย้อนกลับ (จากขวาไปซ้าย)
        for (int i = num_leds - 2; i >= 1; i--)
        {
            ALL_LED_OFF();
            leds[i].ON();
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
    }
}