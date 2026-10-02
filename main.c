#include"head.h"
#define LED 7<<17
#define flame (!((IOPIN0>>5)&1))
int main(){
        char s[30];
        float temp,c;
        int mos;
        IODIR0=LED;
        adc_start();
        uart_start(9600);
        lcd_start();
        while(1){
        lcd_start();
                temp=temp_sence(0);
                mos=motion_sence(1);
                c=0;
                IOSET0=LED;
                if(temp<40.0){
                        sprintf(s,"temp = %.2f C ---> safe\r\n",temp);
                        uart_str(s);
                }else{
                        c=1;
                        sprintf(s,"temp = %.2f C ---> Not Safe\r\n",temp);
                        uart_str(s);
                }
                sprintf(s,"%.2f",temp);
                lcd_str(s,1);
                if(mos){
                        sprintf(s,"no one detected\r\n");
                        lcd_str("No one",2);
                        uart_str(s);
                }else{
                        sprintf(s,"some one detected at danger area\r\n");
                        lcd_str("Some one",2);
                        if(c==0)
                        c=2;
                        uart_str(s);
                }
                if(flame){
 uart_str("flame is on\r\n");
                        lcd_str("FireOn",3);
                        c=1;
                }else{
                        lcd_str("NoFire",3);
                        uart_str("no flame is detected\r\n");
                }
                if(c==1){
                        lcd_str("  Danger",4);
                        uart_str("Final Status : Danger\r\n");
                        IOCLR0=1<<19;
                }else if(c==2){
                        IOCLR0=1<<18;
                        lcd_str("Warning",4);
                        uart_str("Final Status : Warning\r\n");
                }else{
                        IOCLR0=1<<17;
                        lcd_str("SAFE",4);
                        uart_str("Final Status : Safe\r\n");
                }
                delay_ms(100);
        }
}

