#include "gpio.h"

void main()
{
    int status = HIGH;

    while(1)
    {
        GPIO_write_pin(25, status);
        status = (status == HIGH) ? LOW : HIGH;

        for (int i = 0; i <= 10000000; i++) {}
    }
}
