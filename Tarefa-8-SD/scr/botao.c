#include "hardware/gpio.h"
#include "include/init.h"
#include "include/botao.h"


bool botao_clicado()
{
    static int prev = 1;
    int btn = gpio_get(botao);
    bool clicado = (prev == 1 && btn == 0);
    prev = btn;
    if(clicado){
        sleep_ms(25);
    }
    return clicado;
}/*

bool botao_pressionado()
{
    if(gpio_get(botao) == 0)
    {         
        return true;
    }
    else
    {
        return false;
    }
}*/