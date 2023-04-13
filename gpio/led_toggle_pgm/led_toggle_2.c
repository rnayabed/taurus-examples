

#define GPIO_0_BASE_ADDRESS			0x10080000
#define GPIO_0_DDR_ADDRESS          0x100C0000

#define GPIO_1_BASE_ADDRESS			0x10180000
#define GPIO_1_DDR_ADDRESS          0x101C0000

#define IN                          0
#define OUT                         1

#define HIGH                        1
#define LOW                         0

#include "stdlib.h"

void set_pin_mode(int pin, int direction)
{
    if (pin < 16)
    {
        if (direction == OUT)
        {
            *((unsigned short*) GPIO_0_DDR_ADDRESS) |= 1 << pin;
        }
        else
        {
            *((unsigned short*) GPIO_0_DDR_ADDRESS) &= ~(1 << pin);
        }
    }
    else
    {
        if (direction == OUT)
        {
            *((unsigned short*) GPIO_1_DDR_ADDRESS) |= 1 << (pin - 16);
        }
        else
        {
            *((unsigned short*) GPIO_1_DDR_ADDRESS) &= ~(1 << (pin - 16));
        }
    }

    __asm__ __volatile__ ("fence");
}

void gpio_write(int pin, int data)
{
    if (pin < 16)
    {
        *((unsigned short*) (GPIO_0_BASE_ADDRESS | (1 << pin + 2))) = data << pin;
        __asm__ __volatile__ ("fence");
    }
    else
    {
        pin-=16;
        *((unsigned short*) (GPIO_1_BASE_ADDRESS | (1 << pin + 2))) = data << pin;
        __asm__ __volatile__ ("fence");
    }


}


void init_all()
{
    *((unsigned short*) GPIO_0_DDR_ADDRESS) = 0xffff;
    *((unsigned short*) GPIO_1_DDR_ADDRESS) = 0xffff;

    *((unsigned short*) (GPIO_1_BASE_ADDRESS | (1 << 8))) = 1 << 6;
    *((unsigned short*) (GPIO_1_BASE_ADDRESS | (1 << 9))) = 1 << 7;
    *((unsigned short*) (GPIO_1_BASE_ADDRESS | (1 << 10))) = 1 << 8;
}

void sleep()
{
    for (int i = 0; i <= 10000000; i++) {}
}

void main33()
{
    // Pin 25 = 25 - 16 = 9, GPIO 1

    init_all();
    int pin = 11;

    set_pin_mode(pin, OUT);
   // gpio_write(25, HIGH);

    int status = HIGH;
    while(1)
    {
        status = (status == HIGH) ? LOW : HIGH;
        gpio_write(pin, status);
        sleep();
    }
}
