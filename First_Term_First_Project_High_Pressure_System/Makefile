#Prepared by Ebram Habib

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3	-gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name= First_Term_First_Project_High_Pressure_System

all: $(Project_name).bin
	@echo "=======Build is Done======="

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T Linker_Script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $(Project_name).elf -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin *.map *.axf *.elf.asm

clean:
	rm *.elf *.bin