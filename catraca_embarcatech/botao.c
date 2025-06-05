#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "botao.h"

#define botao 6

bool botao_clicado()
{
    static int prev = 1;
    int btn = gpio_get(botao);
    bool clicado = (prev == 1 && btn == 0);
    prev = btn;
    return clicado;
}
