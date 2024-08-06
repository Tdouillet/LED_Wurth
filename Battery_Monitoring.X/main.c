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

#define HI 2
#define LO 0
#define ONE 1
#define ZERO 0
/*
                         Main application
 */

/******************************************************************************/
uint8_t state = 2;
uint8_t bit = 0;
uint8_t count = 0;
uint8_t selected_tab[] = {};
uint8_t ind = 0;
uint8_t init = 1;

uint32_t red = 0b000000001111111100000000;

uint32_t green = 0b111111110000000000000000;

uint32_t blue = 0b000000000000000011111111;

uint32_t gradient = 0b1111;

uint32_t battery_gradient[] = {
    0x0DFF0D, 0x4EFF11, 0x8EFF15, 0xB7FA33, 0xB3AC34, 0xB3694C
};

uint32_t sunset_gradient[]={
  0x15348b, 0x35729d, 0x3d9193, 0x49ae8e, 0x65f275  
};

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

void Write1(void){
    DATA_SetHigh();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    DATA_SetLow();
    Nop();
    Nop();
    
}

void Write0(void){
    DATA_SetHigh();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    DATA_SetLow();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
}

void Reset(void){ //267us reset
    DATA_SetLow();
    __delay_us(200);
}

void Color(uint32_t color){
    
    uint32_t color_temp = color<<8;
    Reset();
    for (uint8_t i = 0; i<24; i++){
        if (color_temp&0x80000000){
            Write1();
        } else {
            Write0();
        }
        color_temp=color_temp<<1;
    }
    
}

void Gradient(uint32_t color, uint8_t range){
    uint32_t color_temp = color;
    for (uint8_t i = 0; i<range;i++){
        Color(color_temp);
        Delay(100);
        color_temp=color_temp<<1;
    }
    
}

void Gradient_Inverse(uint32_t color, uint8_t range){
    uint32_t color_temp = color;
    for (uint8_t i = 0; i<range;i++){
        Color(color_temp);
        Delay(100);
        color_temp=color_temp>>1;
    }
}

void Gradient_Tab(uint32_t tab[],uint32_t delay){
    for (uint32_t i = 0; i<(sizeof(tab)/sizeof(tab[0]));i++){
        Color(tab[i]);
        Delay(delay);
    }
}

void Gradient_Inverse_Tab(uint32_t tab[],uint32_t delay){
    for (uint32_t i = (sizeof(tab)/sizeof(tab[0]))-1; i>=0;i--){
        Color(tab[i]);
        Delay(delay);
    }
}

void Smooth_Flash(uint32_t flash[],uint32_t delay){
    Gradient_Tab(flash, delay);
    Gradient_Inverse_Tab(flash, delay);
    
}

void Red_Flash(uint32_t delay){
    uint32_t color = 0x0;
    for (uint8_t i = 0; i<0xFF;i++){
        Color(color);
        Delay(delay);
        color+=0x100;
    }
    for (uint8_t i = 0; i<0xFF;i++){
        Color(color);
        Delay(delay);
        color-=0x00000100;
    }
    Color(0);
    Delay(40);
    
}

void Green_Flash(uint32_t delay){
    uint32_t color = 0x0;
    for (uint8_t i = 0; i<0xFF;i++){
        Color(color);
        Delay(delay);
        color+=0x10000;
    }
    for (uint8_t i = 0; i<0xFF;i++){
        Color(color);
        Delay(delay);
        color-=0x00010000;
    }
    Color(0);
    Delay(40);
    
}

void Blue_Flash(uint32_t delay){
    uint32_t color = 0x0;
    for (uint8_t i = 0; i<0xFF;i++){
        Color(color);
        Delay(delay);
        color+=0x1;
    }
    for (uint8_t i = 0; i<0xFF;i++){
        Color(color);
        Delay(delay);
        color-=0x1;
    }
    Color(0);
    Delay(40);
    
}

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        Red_Flash(2);
        Green_Flash(2);
        Blue_Flash(2);
        
    }

    return 1;
}
/**
 End of File
*/

