#ifndef DISPLAY_H
#define DISPLAY_H

#include "hardware/i2c.h"
#include "inc/ssd1306.h"

// Definições de pinos e módulo I2C
#define I2C_PORT i2c1
#define PINO_SCL 14
#define PINO_SDA 15

void init_display();
void clear_display();
void texto(uint8_t valor);

#endif