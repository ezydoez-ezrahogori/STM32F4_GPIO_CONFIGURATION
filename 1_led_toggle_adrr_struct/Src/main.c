// where is the led connected
//port: A
//pin: 5

#define    PERIPH_BASE             (0x40000000UL)
#define    ABH1PERIPH_OFFSET       (0x00020000UL)
#define    ABH1PERIPH_BASE         (PERIPH_BASE + ABH1PERIPH_OFFSET)// where is the led connected
//port: A
//pin: 5

#define    PERIPH_BASE             (0x40000000UL)
#define    ABH1PERIPH_OFFSET       (0x00020000UL)
#define    ABH1PERIPH_BASE         (PERIPH_BASE + ABH1PERIPH_OFFSET)
#define    GPIOA_OFFSET            (0x0000UL)

#define    GPIOA_BASE              (ABH1PERIPH_BASE + GPIOA_OFFSET)

#define    RCC_OFFSET              (0x3800UL)
#define    RCC_BASE                (ABH1PERIPH_BASE + RCC_OFFSET)

#define    AHB1EN_R_OFFSET         (0x30UL)
#define    RCC_AHB1EN_R            (*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define    MODE_R_OFFSET           (0X00UL)
#define    GPIOA_MODE_R            (*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define    GPIOAEN                 (1U<<0)    // 0b 0000  0000 0000 0000 0000 0000 0000 0001


/*
 *(1U>>10)   // Set bit 10 to 1
 *&=~(1U>>11)  // set bit 11 to 0
 */

#define    OD_R_OFFSET             (0x14UL)
#define    GPIOA_OD_R              (*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define    PIN5                    (1U<<5)
#define    LED_PIN                 PIN5

int main(void){
	//*
	 //* 1. Set PA5 as output pin
	 //* 2. enable Clock access to GPIOA*/
RCC_AHB1EN_R |= GPIOAEN;

GPIOA_MODE_R |= (1U<<10);// Set bit 10 to 1
GPIOA_MODE_R &=~(1U<<11);  // set bit 11 to 0

while(1){
	/*set pin5 high*/

 //GPIOA_MODE_R |= LED_PIN;
	GPIOA_MODE_R ^= LED_PIN;
	for(int i=0; i<1000000; i++){

	}
        }
 }







































