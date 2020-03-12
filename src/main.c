/* 
 * Kevin Zheng and William Chi (Group 16)
 * ECE 231
 * Baird Soules
 * 13 February 2020
 * Lab 1: From C to C to C; programmed in C: being a Musical Signal Generator
 * Final Program: Musical Signal Generator		
 */

#include <asf.h>
#include <avr/io.h>

uint16_t adc_value;
uint32_t half_period;

uint32_t high_half_period, high_index;
uint32_t low_half_period, low_index;

void adc_init(void);
uint16_t read_adc(uint8_t channel);
uint32_t half_period_loookup(uint16_t note_number);

int main(void)
{
	adc_init();
	
	// set output pins
	DDRB = 0b00000001;

	while(1)
	{
		// each interval of ADC values is 41 wide
		// integer division by 41 of ADC value is one less than ad hoc note number
		half_period = half_period_loookup((read_adc(5) / 41) + 1);
		high_half_period = half_period;
		low_half_period = half_period;
		
		// PB0 HIGH - peak
		PORTB = 0b00000001;
		while(high_half_period > 0)
		{
			// repeat smaller unit of time
			high_index = 0x0012;
			while(high_index > 0) high_index--;
			high_half_period--;
		}
		
		// PB0 LOW - trough
		PORTB = 0b00000000;
		while(low_half_period > 0)
		{
			// repeat smaller unit of time
			low_index = 0x0012;
			while(low_index > 0) low_index--;
			low_half_period--;
		}
	}
}

void adc_init(void)
{
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADSC);
}

uint16_t read_adc(uint8_t channel)
{
	ADMUX &= 0xF0;
	ADMUX |= channel;
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return ADCW;
}

/*
 * Calculate half period of a given note number obtained from ADC
 * Returns int32 of number of instructions needed to produce given note number
 */
uint32_t half_period_loookup(uint16_t note_number)
{
	if (note_number >= 13) return 122 - (note_number-13)*5.5;			// higher notes
	else if (note_number < 13) return 255-(note_number-1)*11.083;		// lower notes
	return 0;
}