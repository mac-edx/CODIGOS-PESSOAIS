#include <string.h>
#include "include/init.h"
#include "include/display.h"

char *text = "";         // texto do menu
const uint I2C_SDA = 14; // Pino SDA do barramento I2C
const uint I2C_SCL = 15; // Pino SCL do barramento I2C
ssd1306_t disp;

void init_display() {
    i2c_init(I2C_PORT, 400 * 1000); // Configura I2C a 400 KHz

    gpio_set_function(PINO_SCL, GPIO_FUNC_I2C);
    gpio_set_function(PINO_SDA, GPIO_FUNC_I2C);

    gpio_pull_up(PINO_SCL);
    gpio_pull_up(PINO_SDA);

    disp.external_vcc = false;

    ssd1306_init(&disp, 128, 64, 0x3C, I2C_PORT);

    clear_display(); // Limpa o display
}


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