#include "io430.h"
#include "math.h"

#define beta 4000.0
#define T0 298.15
#define R 9860.0
#define R0 10000.0

extern  void get_Kelwin(void);    
extern  void Subtract(void);

unsigned short value = 0;
unsigned short K = 0;
unsigned short temp = 0;
unsigned short Ce = 0;
float value_2 =0;
float a = 0;
float b = 0;
float temperature = 0;

const unsigned char digit [10][2] =
{
  {0xFC, 0x28},  /* "0" 0*/
  {0x60, 0x20},  /* "1" 1*/
  {0xDB, 0x00},  /* "2" 2*/
  {0xF3, 0x00},  /* "3" 3*/
  {0x67, 0x00},  /* "4" 4*/
  {0xB7, 0x00},  /* "5" 5*/
  {0xBF, 0x00},  /* "6" 6*/
  {0xE4, 0x00},  /* "7" 7*/
  {0xFF, 0x00},  /* "8" 8*/
  {0xF7, 0x00},  /* "9" 9*/
};

void showDigit(char, int);
void init_GPIO(void);
void init_Timer_A(void);
void init_LCD(void);
void ADC_setup(void);
void displaySensor(float temp);
unsigned short get_Celsjusz(unsigned short x,unsigned short y);

int main( void )
{
  WDTCTL = WDTPW + WDTHOLD;
  init_GPIO();
  init_LCD();
  ADC_setup();
  init_Timer_A();
  a = log(R/R0);
  b = beta/T0;
  __bis_SR_register(GIE);
  while(1);
}

void showDigit(char d, int position)
{
  if (d >= '0' && d <= '9')
  {
    d -= 48;
  }
  
  switch(position)
  {
    case 1:
        LCDM10 = digit[d][0];
        LCDM11 = digit[d][1];
        break;

   case 2:
	LCDM6 = digit[d][0];
        LCDM7 = digit[d][1];
        break;

   case 3:
	LCDM4 = digit[d][0];
	LCDM5 = digit[d][1];
	break;

   case 4:
	LCDM19 = digit[d][0];
	LCDM20 = digit[d][1];
	break;

   case 5:
	LCDM15 = digit[d][0];
	LCDM16 = digit[d][1];
	break;

   case 6:
	LCDM8 = digit[d][0];
	LCDM9 = digit[d][1];
	break;
   default:
	break;
  }
}
void init_GPIO(void)
{
  PM5CTL0 &= ~LOCKLPM5; //wylacz stan wysokiej impedancji
  PJSEL0 |= 1<<4 | 1<<5; 
  P1DIR |= 0x01; //Output dla diody czerwonej
  P9DIR |= 0x80; //Output dla diody zielonej
  P1OUT |= 0x06; //Button pull-up
  P1REN |= 0x06; //pull up/down resistor enable
  P1IES |= 0x06; //from HI to LO, edge select
  P1IE |= 0x06; //interrupt enable
  P1IFG = 0x00; //zerujemy rejestr, aby miec pewnosc no interrupt pending
}
void init_Timer_A(void)
{
  TA0CCR0 = 40000; //zliczanie do ...
  TA0CTL |= ( (1<<8) | (1<<4) ); //Source ACLK | Up mode
  TA0CCTL0 |= 1<<4; //interrupt enable
}
void init_LCD(void)
{
  CSCTL0_H = 0xA5;              
  CSCTL4 &= ~LFXTOFF; //Wlaczenie LFXT
      do
    {
      CSCTL5 &= ~LFXTOFFG;                
      SFRIFG1 &= ~OFIFG;        
    }while (SFRIFG1 & OFIFG);                  
    CSCTL0_H = 0x96;            

  // LCD segments               
    LCDCPCTL0 = 0xFFFF; //0-15
    LCDCPCTL1 = 0xFC3F; //16-21 & 26-31
    LCDCPCTL2 = 0x0FFF; //32-43
  
  // Initialize LCD_C
  // ACLK, Divider = 16, Pre-divider = 8; 4-pin MUX
    LCDCCTL0 = LCDDIV__16 | LCDPRE__8 | LCD4MUX; 
    LCDCVCTL = VLCD_1 | VLCDREF_0 | LCDCPEN; 
    LCDCCPCTL = LCDCPCLKSYNC;           
    LCDCBLKCTL = (LCDBLKDIV1 | LCDBLKDIV0) | (LCDBLKPRE1 | LCDBLKPRE0);
    LCDCMEMCTL = LCDCLRM;               
    LCDCCTL0 |= LCDON;
}
void ADC_setup(void)
{
  ADC12CTL0 |= ( (1<<9) | (1<<4) ); //16 cycles sampling | ADC_ON
  ADC12CTL1 |= (1<<9); //SAMPCOM - source 
  ADC12CTL2 |= 0x0020; //ADC resolution, 12bit
  ADC12MCTL0 |= 0x000A; //pin P9.2 
  ADC12IER0 |= 1<<0; //enable interrupt
  ADC12CTL0 |= 1<<1; //enable conversion
  ADC12CTL0 |= 1<<0;
}
void displaySensor(float temp)
{
  int value_3 = (int)(temp);
  if(value_3>=10000)
  {
    showDigit((value_3/10000)%10 + '0',1);
  }
  if(value_3>=1000)
  {
    showDigit((value_3/1000)%10 + '0',2);
  }
  if(value_3>=100)
  {
    showDigit((value_3/100)%10 + '0',3);
  }
  if(value_3>=10)
  {
    showDigit((value_3/10)%10 + '0',4);
  }
  if(value_3>=1)
  {
    showDigit((value_3/1)%10 + '0',5);
  }
  // Decimal point
  LCDM5 |= 1<<0;
  // Degree symbol
  LCDM16 |= 1<<2;
}
unsigned short get_Celsjusz(unsigned short x,unsigned short y)
{
  return (x-y);
}
//*************************************************************************
//* ADC12 Interrupt Service Routine
//*************************************************************************
#pragma vector = ADC12_VECTOR
__interrupt void ADC12_ISR(void)
{
  value = ADC12MEM0;
  ADC12CTL0 |= 1<<0; //start sample and conversion
}
//*************************************************************************
//* TimerA0 Interrupt Service Routine
//*************************************************************************
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_ISR (void)
{
  value_2 = value;
  temperature = (beta/(a + log((4096 - value_2)/ value_2) + b));
  temperature *=100;
  temp = (unsigned short)(temperature);
  asm("clr.w R12");
  Subtract();
  P1OUT ^= 1<<0;
}
//*************************************************************************
//* Button 1 Interrupt Service Routine
//*************************************************************************
#pragma vector = PORT1_VECTOR
__interrupt void Button_1(void)
{
  unsigned long delay;
  for(delay=0;delay<20000;delay++);
  switch(P1IV)
  {
    case 4:
      {
        LCDCMEMCTL = LCDCLRM;
        displaySensor(Ce);
        LCDM8 = 0x9C; //litera C 6 pozycja
        P9OUT &= ~1<<7;
        break;
      }
    case 6:
      {
        get_Kelwin();
        LCDCMEMCTL = LCDCLRM;
        displaySensor(K);
        LCDM8 = 0x0E;
        LCDM9 =0x22; //Litera K 
        LCDM16 &= ~1<<2;
        P9OUT |= 1<<7;
        break;
      }
  }
}
