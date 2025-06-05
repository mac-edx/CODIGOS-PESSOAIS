#include <string.h>
#include "inc/ssd1306.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include <stdio.h>
#include "include/init.h"
#include "include/botao.h"
#include "include/display.h"

void principal()
{

    uint8_t valor = 0;
    while (1)
    {

        if (botao_clicado())
        {

            gpio_put(latchpin, 0);
            sleep_us(1); // pulso de latch
            gpio_put(latchpin, 1);

            for (int i = 0; i < 8; i++)
            {
                gpio_put(clkpin, 0);
                sleep_us(1);
                int bit = gpio_get(serialpin);
                valor |= (bit << i);

                gpio_put(clkpin, 1);
            }
            printf("o codigo chega aqui!");
        }

        texto(valor);

        sleep_ms(200);
    }
}

int main()
{
    init();
    principal();
}
