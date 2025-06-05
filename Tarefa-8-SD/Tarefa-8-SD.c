#include <stdio.h>
#include "include/init.h"
#include "include/botao.h"
#include "include/display.h"

 uint8_t valor = 0;

void principal()
{

   
    while (1)
    {
        botao_pressionado();
        if (botao_pressionado())
        {
            valor = 0;

            gpio_put(latchpin, 0);
            sleep_us(1); // pulso de latch
            gpio_put(latchpin, 1);

            for (int i = 0; i < 8; i++)
            {
                gpio_put(clkpin, 0);
                sleep_us(1);
                int bit = gpio_get(serialpin);
                valor |= (bit << i);
                gpio_put(clkpin, !clkpin);

            }
            printf("valor: %u", valor);
            texto(valor);
        }

        sleep_ms(200);
    }
}

int main()
{
    init();
    principal();
}
