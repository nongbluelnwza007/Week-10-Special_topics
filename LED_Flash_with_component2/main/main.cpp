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

void set_led_pattern(int i)
{
    ALL_LED_OFF();
    switch (i)
    {
    case 0:
        led1.ON();
        led8.ON();
        break;
    case 1:
        led2.ON();
        led7.ON();
        break;
    case 2:
        led3.ON();
        led6.ON();
        break;
    case 3:
        led4.ON();
        led5.ON();
        break;
    }
}

extern "C" void app_main(void)
{
    while (1)
    {
        // เฟสวิ่งเข้าหากัน
        for (int i = 0; i < 4; i++)
        {
            set_led_pattern(i);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }

        // เฟสวิ่งออกจากกัน (ย้อนกลับ)
        for (int i = 2; i >= 0; i--)
        {
            set_led_pattern(i);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
    }
}