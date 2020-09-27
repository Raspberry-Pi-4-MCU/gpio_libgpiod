import time
from gpio_next import Output

LED = Output(26, default_value = 0)
for i in range(10):
    LED.write(i & 1)
    time.sleep(1)
