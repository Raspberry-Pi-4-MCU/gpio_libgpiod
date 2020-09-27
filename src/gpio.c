#include "gpio.h"

gpio_structure* new_gpio(uint8_t gpio_pin, uint8_t gpio_func)
{
    assert_param(IS_PIN(gpio_pin,gpiochip));
    gpio_structure* new_gpio_device = (gpio_structure*)calloc(sizeof(gpio_structure),1);
    new_gpio_device->gpio_chip = gpiod_chip_open_by_number(gpiochip);
    new_gpio_device->gpio_line = gpiod_chip_get_line(new_gpio_device->gpio_chip, gpio_pin);
    pinMode(new_gpio_device, gpio_func);
    return new_gpio_device;
}

void pinMode(gpio_structure* gpio_device, uint8_t gpio_func)
{
    if(gpiod_line_is_requested(gpio_device->gpio_line))gpiod_line_release(gpio_device->gpio_line);
    if(!gpio_func)gpiod_line_request_output(gpio_device->gpio_line, "pin",0);
    else gpiod_line_request_input(gpio_device->gpio_line, "pin");
}

void write_gpio(gpio_structure* gpio_device, uint8_t gpio_func)
{
    gpiod_line_set_value(gpio_device->gpio_line, gpio_func);
}

uint8_t read_gpio(gpio_structure* gpio_device)
{
    return gpiod_line_get_value(gpio_device->gpio_line);
}

void assert_failed(uint8_t* file, uint32_t line)
{
    printf("error at file %s, line %d",file,line);
    exit(-1);
}