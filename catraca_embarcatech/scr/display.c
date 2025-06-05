#include "init.h"
#include <string.h>
#include "inc/ssd1306.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"

char *text = "";         // texto do menu
const uint I2C_SDA = 14; // Pino SDA do barramento I2C
const uint I2C_SCL = 15; // Pino SCL do barramento I2C
ssd1306_t disp;

void print_texto(char *msg, uint pos_x, uint pos_y, uint scale)
{
    ssd1306_draw_string(&disp, pos_x, pos_y, scale, msg); // desenha texto
    ssd1306_show(&disp);                                  // apresenta no Oled
}

void texto(uint8_t valor)
{

    char decimal[5];
    sprintf(decimal, "%u", valor);
    ssd1306_clear(&disp); // Limpa o display
    print_texto("Decimal: ", 0, 32, 1);
    print_texto(decimal, 50, 32, 1);
}