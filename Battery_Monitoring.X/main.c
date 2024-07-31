/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ512GU410
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/mccp6_compare.h"
#include "DELAY.h"

#define GREEN 1
#define RED 2
#define BLUE 3

/*
                         Main application
 */

/******************************************************************************/

uint8_t red_tab[] = {0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x4,0x4,0x4,0x4,
                     0x4,0x4,0x4,0x4,0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7};

uint8_t green_tab[] = {0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x7,0x7,0x7,0x7,
                        0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7};

uint8_t blue_tab[] = {0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x4,0x4,0x4,0x4,
                     0x4,0x4,0x4,0x4,0x7,0x7,0x7,0x7,0x7,0x7,0x7,0x7};
void Delay(unsigned int msec)
{
   while(msec > 0)
   {
       __delay_ms(1);
      msec--;
    }
}

void Delay_us(unsigned int usec)
{
   while(usec > 0)
   {
       __delay_us(1);
      usec--;
    }
}

void Change_PWM(uint16_t value){
    
    CCP6RB=value;
}

void Reset(void){ //267us reset
    for (uint8_t i = 0; i<210;i++){
        CCP6RB = 0xA;
    }
}

void Green(void){
    
    Reset();
    Change_PWM(0x4);
    __delay_us(1);
    Change_PWM(0x4);
    __delay_us(1);
    Change_PWM(0x4);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
}

void Red(void){
    
    Reset();
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x4);
    __delay_us(1);
    Change_PWM(0x4);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
}

void Blue(void){
    
    Reset();
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x4);
    __delay_us(1);
    Change_PWM(0x4);
    __delay_us(1);
}

void Purple(void){
    Red();
    Blue();
}

void Yellow(void){
    Red();
    Red();
    Green();
    
}

void Test(void){
    uint8_t a = 0;
    Reset();
    Change_PWM(0x4);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Change_PWM(0x4);
    __delay_us(1);
    Change_PWM(0x7);
    __delay_us(1);
    Reset();
}

void Orange(void){
    Red();
    Red();
    Red();
    Red();
    Red();
    Red();
    Green();
}


int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    MCCP6_COMPARE_Start();

    while (1)
    {
        Blue();
        Reset();
        __delay_ms(2000);
        Red();
        Reset();
        __delay_ms(2000);
        Green();
        Reset();
        __delay_ms(2000);
        
    }

    return 1;
}
/**
 End of File
*/

