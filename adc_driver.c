#include"head.h"
#define DONE (!((ADDR>>31)&1))
int adc_val;
void adc_start(){
        PINSEL1=0x15400000;
        ADCR=0x00200400;
}
int adc_read(unsigned char ch){
        unsigned int result;
        ADCR|=1<<ch;
        ADCR|=1<<24;
        while(DONE);
        ADCR^=1<<24;
        ADCR^=1<<ch;
        result=(ADDR>>6)&0x3FF;
        return result;
}
float temp_sence(unsigned char ch){
        float vout,temp;
        adc_val=adc_read(ch);
        vout=adc_val*(3.3/1023);
        temp=vout/0.010;
        return temp;
}
int motion_sence(unsigned char ch){
        adc_val=adc_read(ch);
        if(adc_val != 1023) return 1;
        else
        return 0;
}

