#include "uart.h"

unsigned char string_buffer [100] = "learn-in-depth: <<Ebram Habib>>";
unsigned char string_buffer2 [100];
void main (void)
{
	uart_send_string (string_buffer);
}