/* learn-in-depth diploma
First_Term_First_Project_High_Pressure_System
Eng: Ebram Habib
*/

MEMORY
{
	flash(RX)	: ORIGIN = 0X08000000, LENGTH = 512M
	sram(RWX)	: ORIGIN = 0X20000000, LENGTH = 512M
}

SECTIONS
{
	.text : 
	{
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_TEXT = . ; /* End of .text section*/
	}>flash

	.data : 
	{
		_S_DATA = . ;
		*(.data*)
		. = ALIGN(4);
		_E_DATA = . ;
	}>sram AT>flash
	
	.bss : 
	{
		_S_BSS = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = . ;

		. = ALIGN(4);
		. = . + 0x1000 ;
		_STACK_TOP = . ;
	}>sram
}