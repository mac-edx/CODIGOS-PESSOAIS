#include "hardware/gpio.h"
#include "botao.h"
#include "display.h"
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

    // Inicialização do i2c
    i2c_init(I2C_PORT, 400 * 1000); // I2C Inicialização. Usando 400Khz.
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    disp.external_vcc = false;

    // Processo de inicialização completo do OLED SSD1306
    ssd1306_init(&disp, 128, 64, 0x3C, I2C_PORT);
}