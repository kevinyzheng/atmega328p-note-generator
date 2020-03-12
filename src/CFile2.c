// /* 
//  * Kevin Zheng and William Chi (Group 16)
//  * ECE 231
//  * Baird Soules
//  * 13 February 2020
//  * Lab 1: From C to C to C; programmed in C: being a Musical Signal Generator
//  * Test Program 2: Middle C Square Wave Generator
//  */
// 
// #include <asf.h>
// #include <avr/io.h>
// 
// int main(void)
// {
// 	DDRB = 0b00000001;
// 	while(1)
// 	{
// 		PORTB = 0b00000001;
// 		uint32_t high_half_period = 0x0081;
// 		while(high_half_period > 0)
// 		{
// 			uint32_t high_index = 0x0012;
// 			while(high_index > 0) high_index--;
// 			high_half_period--;
// 		}
// 		PORTB = 0b00000000;
// 		uint32_t low_half_period = 0x0081;
// 		while(low_half_period > 0)
// 		{
// 			uint32_t low_index = 0x0012;
// 			while(low_index > 0) low_index--;
// 			low_half_period--;
// 		}
// 	}
// }