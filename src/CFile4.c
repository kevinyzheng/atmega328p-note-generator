// /* 
//  * Kevin Zheng and William Chi (Group 16)
//  * ECE 231
//  * Baird Soules
//  * 13 February 2020
//  * Lab 1: From C to C to C; programmed in C: being a Musical Signal Generator
//  * Test Program 4: Half-Period Lookup
//  */
// 
// #include <asf.h>
// #include <avr/io.h>
// 
// uint16_t adc_value;
// uint32_t half_period;
// 
// void adc_init(void);
// uint16_t read_adc(uint8_t channel);
// uint32_t half_period_loookup(uint16_t note_number);
// 
// int main(void)
// {
// 	adc_init();
// 	DDRB = 0b00000001;
// 	while(1) half_period = half_period_loookup((read_adc(5) / 41) + 1);
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
// 
// uint32_t half_period_loookup(uint16_t note_number)
// {
// 	if (note_number >= 13) return 122 - (note_number-13)*5.5;		// higher notes
// 	else if (note_number < 13) return 256-(note_number-1)*11.1667;	// lower notes
// }