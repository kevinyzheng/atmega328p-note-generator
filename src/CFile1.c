// /* 
//  * Kevin Zheng and William Chi (Group 16)
//  * ECE 231
//  * Baird Soules
//  * 13 February 2020
//  * Lab 1: From C to C to C; programmed in C: being a Musical Signal Generator
//  * Test Program 1: LED Blinker
//  */
// 
// #include <avr/io.h>
// 
// int main(void)
// {
// 	DDRB = 0b00000001;
// 	while(1)
// 	{
// 		PORTB = 0b00000001;
// 		uint32_t index0 = 0xffff;
// 		while(index0 > 0) index0--;
// 		
// 		PORTB = 0b00000000;
// 		uint32_t index1 = 0xffff;
// 		while(index1 > 0) index1--;
// 	}
// }