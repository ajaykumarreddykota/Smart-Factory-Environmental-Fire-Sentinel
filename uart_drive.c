#include"head.h"
#define THRE (!((U0LSR>>5)&1))
#define RDR (!(U0LSR&1))
void uart_start(unsigned int x){
        unsigned int result,pclk;
        if(VPBDIV==0){
                pclk=15000000;
        }else if(VPBDIV==1){
                pclk=60000000;
        }else if(VPBDIV==2){
                pclk=30000000;
        }
        result=pclk/(16*x);
        PINSEL0=0x05;
        U0LCR=0x83;
        U0DLL=result&0xff;
        U0DLM=(result>>8)&0xFF;
        U0LCR=0x03;
}
void uart_tx(unsigned char x){
        U0THR=x;
        while(THRE);
}
char uart_rx(){
        while(RDR);
        return U0RBR;
}
void uart_str(char * s){
        while(*s){
                uart_tx(*s++);
        }
}

