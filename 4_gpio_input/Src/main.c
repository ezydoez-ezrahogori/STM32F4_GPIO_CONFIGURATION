#include<stm32f4xx.h>

#define     GPIOCEN        (1U<<2)

#define     GPIOAEN        (1U<<0)
#define     PIN5           (1U<<5)
#define     LED_PIN        PIN5

#define     PIN13          (1U<<13)
#define     BUTTON_PIN     PIN13


int  main(void){
    /*Enable clock access to GPIOA and GPIOC */
	RCC->AHB1ENR |=GPIOAEN;
	RCC->AHB1ENR |=GPIOCEN;
    /*Set PA5 as the output pin*/
	GPIOA->MODER  |=(1U<<10);
    GPIOA->MODER  &=~(1U<<11);

    /*Set PC13 as input pin*/

    GPIOC->MODER  &=~(1U<<26);
    GPIOC->MODER  &=~(1U<<27);

	while(1)
	{
       /*check if BTTN is pressed*/

		if(GPIOC->IDR & BUTTON_PIN ){
		/*Turn on the Led*/
		GPIOA->BSRR =LED_PIN;
		}

		else{
			/*Turn off the led*/
		GPIOA->BSRR =(1U<<21);

		}
	}
}
