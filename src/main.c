#include "gpio.h"
#include <time.h>
int main()
{
    gpio_structure* new_gpio_device = new_gpio(26, OUTPUT);
    while(1)
    {
        digitalWrite(new_gpio_device,HIGH);
        sleep(1);
        digitalWrite(new_gpio_device,LOW);
        sleep(1);
    }
    return 0;
}