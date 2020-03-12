// /* 
//  * Kevin Zheng and William Chi (Group 16)
//  * ECE 231
//  * Baird Soules
//  * 13 February 2020
//  * Lab 1: From C to C to C; programmed in C: being a Musical Signal Generator
//  * Test Program 3: ADC
//  */
// 
// #include <asf.h>
// #include <avr/io.h>
// 
// uint16_t adc_value;
// 
// void adc_init(void);
// uint16_t read_adc(uint8_t channel);
// 
// int main(void)
// {
// 	adc_init();
// 	DDRB = 0b00000001;
// 	while(1)
// 	{
// 		adc_value = read_adc(5);
// 		if (adc_value > 0x01ec) PORTB = 0b00000001;
// 		else PORTB = 0b00000000;
// 	}
// }
// 
// void adc_init(void)
// {
// 	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
// 	ADMUX |= (1<<REFS0);
// 	ADCSRA |= (1<<ADEN);
// 	ADCSRA |= (1<<ADSC);
// }
// 
// uint16_t read_adc(uint8_t channel)
// {
// 	ADMUX &= 0xF0;
// 	ADMUX |= channel;
// 	ADCSRA |= (1<<ADSC);
// 	while(ADCSRA & (1<<ADSC));
// 	return ADCW;
// }