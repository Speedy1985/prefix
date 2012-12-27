#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>
#include <math.h>

int main(int argc,char *argv[])
{
	int n_leds = 0;

	if(argc < 2) {
		(void)printf("Usage: %s leds (Max of 65536) \n", argv[0]);
		return 1;
	}
	
	n_leds = atol(argv[1]);
	
	printf("\n\n");
	printf("Create prefix for arduino boards, Scripted by Speedy1985 (c) 2012\n");
	printf("-----------------------------------------------------------------\n");	

	if(n_leds <= 0){
		printf("\nError, exit...\n\n");
		return 0;
	}

	int i;
	unsigned char  buffer[6 + (n_leds * 3)], // Header + 3 bytes per LED
	               lo, r, g, b;

	bzero(buffer, sizeof(buffer));  // Clear LED buffer

	// Header only needs to be initialized once, not
	// inside rendering loop -- number of LEDs is constant:
	buffer[0] = 'A';                          // Magic word
	buffer[1] = 'd';
	buffer[2] = 'a';
	buffer[3] = (n_leds - 1) >> 8;            // LED count high byte
	buffer[4] = (n_leds - 1) & 0xff;          // LED count low byte
	buffer[5] = buffer[3] ^ buffer[4] ^ 0x55; // Checksum
	
	printf("Prefix for %i LEDS: ",n_leds);
	for(i = 0; i < 6; i++){
		printf(" %02X",buffer[i]);
	}
	printf("\n");
	return 0;
}
