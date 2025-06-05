#include "hardware/gpio.h"
#include "include/botao.h"
#include "include/display.h"
#include "include/init.h"

// define os pinos de entrada e saida do registrador e do botao
#define latchpin 28
#define clkpin 17
#define serialpin 16
#define I2C_PORT i2c1
#define botao 6

void init()
{
    gpio_init(latchpin);
    gpio_set_dir(latchpin, GPIO_OUT);

    gpio_init(clkpin);
    gpio_set_dir(clkpin, GPIO_OUT);

    gpio_init(serialpin);
    gpio_set_dir(serialpin, GPIO_IN);

    gpio_init(botao);
    gpio_set_dir(botao, GPIO_IN);
    gpio_pull_up(botao);

    init_display(); // Inicializa o display

}