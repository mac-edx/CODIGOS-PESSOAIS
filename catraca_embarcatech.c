#include <string.h>
#include "inc/ssd1306.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include <stdio.h>

// define os pinos de entrada e saida do registrador e do botao
#define latchpin 28
#define clkpin 17
#define serialpin 16
#define botao 6

static int prev = 1;
uint8_t valor = 0;


#define I2C_PORT i2c1
char *text = "";         // texto do menu
const uint I2C_SDA = 14; // Pino SDA do barramento I2C
const uint I2C_SCL = 15; // Pino SCL do barramento I2C
ssd1306_t disp;

void init()
{
    stdio_init_all();
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

void print_texto(char *msg, uint pos_x, uint pos_y, uint scale)
{
    ssd1306_draw_string(&disp, pos_x, pos_y, scale, msg); // desenha texto
    ssd1306_show(&disp);                                  // apresenta no Oled
}

void principal()
{       
        int btn = gpio_get(botao);
        if (prev == 1 && btn == 0)
        {

            gpio_put(latchpin, 0);
            sleep_us(1); // pulso de latch
            gpio_put(latchpin, 1);
            valor = 0; // zera o valor

            for(int i = 0; i < 8; i++){
                gpio_put(clkpin, 0);
                sleep_us(1);

                int bit = gpio_get(serialpin);
                valor |= (bit << (7 - i));

                gpio_put(clkpin, 1);
            }
                printf("Valor lido: %d\n", valor);
        }

            prev = btn;
            char decimal[5];
            sprintf(decimal, "%u", valor);
            ssd1306_clear(&disp); // Limpa o display
            print_texto("Chega aqui", 32, 10, 2);
            print_texto("Decimal: ", 32, 32, 1);
            print_texto(decimal, 80, 32, 1);
}


int main()
{
    init();
    while(1)
    {
        principal();
        sleep_ms(20); // Aguarda 1 segundo antes de repetir
    }
}
