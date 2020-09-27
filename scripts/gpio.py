import gpiod

class gpio_device:
    def __init__(self, gpio_pin, gpio_func, gpio_chip_name = 'gpiochip0'):
        self.gpio_chip_name = gpio_chip_name
        self.chip = gpiod.Chip(gpio_chip_name, gpiod.Chip.OPEN_BY_NAME)
        self.is_pin(gpio_pin)
        #
        self.gpio_pin = gpio_pin
        self.gpio_func = gpio_func
        #
    
    def is_pin(self, gpio_pin):
        for pin in self.chip.get_all_lines().to_list():
            if gpio_pin == pin.offset():
                return True
        print('Pin not found')
        exit(-1)
                
