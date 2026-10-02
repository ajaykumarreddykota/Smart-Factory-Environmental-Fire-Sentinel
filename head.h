#include<lpc21xx.h>
#include<stdio.h>
extern void uart_start(unsigned int);
extern void uart_tx(unsigned char);
extern char uart_rx(void);
extern void uart_str(char *);
extern void adc_start(void);
extern int adc_read(unsigned char);
extern float temp_sence(unsigned char);
extern int motion_sence(unsigned char);
extern int flame_sence(unsigned char);
extern void delay_ms(unsigned int);
extern void lcd_start(void);
extern void lcd_str(char *,int);
extern void com_1(unsigned char,int);
extern void com_2(void);
extern void lcd_data(unsigned char);
extern void lcd_cmd(unsigned char);

