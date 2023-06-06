#include <taurus/stdlib.h>
#include <taurus/gpio.h>

void main()
{
	int i;

	printf("Blink GPIO 25");

	//GPIO_set_pin_mode(PIN_21, OUT);
	
	while(1)
	{
		
		GPIO_write_pin(GPIO_25, HIGH);
		printf("\nLEDs ON");
		for(i=0; i< 0x800000;i++); // Delay

		GPIO_write_pin(GPIO_25, LOW);
		printf("\nLEDs OFF");

		for(i=0; i< 0x800000;i++); // Delay
	}
}




