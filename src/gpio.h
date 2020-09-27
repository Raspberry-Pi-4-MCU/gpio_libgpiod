#ifndef __gpio__h__
#define __gpio__h__
#include <gpiod.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#define OUTPUT 0
#define INPUT 1
#define HIGH 1
#define LOW 0
#define gpiochip 0
#define digitalWrite write_gpio
#define digitalRead read_gpio
// gpio struecture
typedef struct gpio_structure gpio_structure;
typedef struct gpio_structure
{
    uint8_t gpio_pin;
    uint8_t gpio_func;
    struct gpiod_chip *gpio_chip;
    struct gpiod_line *gpio_line;
}gpio_structure;
//
gpio_structure* new_gpio(uint8_t, uint8_t);
void write_gpio(gpio_structure*,uint8_t);
uint8_t read_gpio(gpio_structure*);
void pinMode(gpio_structure*, uint8_t);
//assert
#define IS_PIN(x,chip) ((x) > 0 && (x) <= gpiod_chip_num_lines(gpiod_chip_open_by_number((chip))))
#define assert_param(x) ((x)?(void)0:assert_failed((uint8_t *)__FILE__, __LINE__))
void assert_failed(uint8_t* file, uint32_t line);

#endif