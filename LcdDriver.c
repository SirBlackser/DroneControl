#include <stdio.h>
#include <avr/io.h>
#include "LcdDriver.h"

//----------------------------------------------------------------------------------------------
//GENERAL COMMANDS
void lcdAutoBaud()
{
	fprintf(stderr, "U");
}

void lcdSetBaud(int i)
{
	if (i > 15) i = 15;
	fprintf(stderr, "Q%c", i);
}

void lcdReplaceBackground(int color)
{
	//int red 5 green 6 blue 5
	//red, blue 0-31, green 0-63
	//change background color
	//fprintf(stderr, "B%c%c", 0b11111111, 0b11111111);		//white
	//_delay_ms(20);
	switch(color)
	{
		case 0: {fprintf(stderr, "B%c%c", 0b11111000, 0b00000000); break;}		//"LIGHT_RED"
		case 1: {fprintf(stderr, "B%c%c", 0b01111000, 0b00000000); break;}		//"DARK_RED"
		case 2: {fprintf(stderr, "B%c%c", 0b11111011, 0b11100000); break;}		//"ORANGE"
		case 3: {fprintf(stderr, "B%c%c", 0b01111111, 0b11100000); break;}		//"YELLOW"
		case 4: {fprintf(stderr, "B%c%c", 0b00000111, 0b11100000); break;}		//"LIGHT_GREEN"
		case 5: {fprintf(stderr, "B%c%c", 0b00000011, 0b11100000); break;}		//"DARK_GREEN"
		case 6: {fprintf(stderr, "B%c%c", 0b00000000, 0b00011111); break;}		//"LIGHT_BLUE"
		case 7: {fprintf(stderr, "B%c%c", 0b00000000, 0b00001111); break;}		//"DARK_BLUE"
		case 8: {fprintf(stderr, "B%c%c", 0b11111000, 0b00011111); break;}		//"VIOLET"
		case 9: {fprintf(stderr, "B%c%c", 0b00000000, 0b00000000); break;}		//"BLACK"
		case 10: {fprintf(stderr, "B%c%c", 0b11111111, 0b11111111); break;}		//"WHITE"
	}
}

void lcdClear()
{
	fprintf(stderr, "E");
}

void lcdControlMode(int i, int j)
{
	switch(i)
	{
		case 0: {fprintf(stderr, "Y%c%c", i, j); break;}		//Backlight control (0-1)
		case 1: {fprintf(stderr, "Y%c%c", i, j); break;}		//Display on-off (0-1)
		case 2: {fprintf(stderr, "Y%c%c", i, j); break;}		//Display contrast adjust (0-15)
		case 3: {fprintf(stderr, "Y%c%c", i, j); break;}		//Display powerUp-shutdown (0-1)
		case 4: {fprintf(stderr, "Y%c%c", i, j); break;}		//Display Orientation (1-4)
	}
}

//----------------------------------------------------------------------------------------------
//GRAPHICS COMMANDS
/*
//FAILED
void lcdAddUserBitmap()
{
	fprintf(stderr, "A%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x01, 0x00, 0b00000110, 0b01100000, 0b00001100, 0b00110000, 0b00011000, 0b00011000, 0b00011000, 0b00011000, 0b00011011, 0b00011011, 0b00111111, 0b11111100, 0b01111100, 0b00111110, 0b01111110, 0b01111110, 0b11011010, 0b01011011, 0b10011001, 0b10011001, 0b10011101, 0b10111001, 0b10001101, 0b10110001, 0b00000111, 0b11100000, 0b00000011, 0b11000000, 0b00111111, 0b11111100, 0b00011110, 0b01111000);
}

//FAILED
void lcdDrawUserBitmap(int x, int y, char color1, char color2)
{
	fprintf(stderr, "D%c%c%c%c%c%c%c%c", 0x01, 0x00, 0, x, 0, y, color1, color2); 
}
*/

void lcdCircle(int x, int y, int radius, char color1, char color2)
{
	fprintf(stderr, "C%c%c%c%c%c%c%c%c", 0, x, 0, y, 0, radius, color1, color2);
}

void lcdTriangle(int x1, int y1, int x2, int y2, int x3, int y3, char color1, char color2)
{
	fprintf(stderr, "G%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0, x1, 0, y1, 0, x2, 0, y2, 0, x3, 0, y3, color1, color2);
}

void lcdSetBackground(int color)
{
	//int red 5 green 6 blue 5
	//red, blue 0-31, green 0-63
	//change background color
	//fprintf(stderr, "B%c%c", 0b11111111, 0b11111111);		//white
	//_delay_ms(20);
	switch(color)
	{
		case 0: {fprintf(stderr, "B%c%c", 0b11111000, 0b00000000); break;}		//"LIGHT_RED"
		case 1: {fprintf(stderr, "B%c%c", 0b01111000, 0b00000000); break;}		//"DARK_RED"
		case 2: {fprintf(stderr, "B%c%c", 0b11111011, 0b11100000); break;}		//"ORANGE"
		case 3: {fprintf(stderr, "B%c%c", 0b01111111, 0b11100000); break;}		//"YELLOW"
		case 4: {fprintf(stderr, "B%c%c", 0b00000111, 0b11100000); break;}		//"LIGHT_GREEN"
		case 5: {fprintf(stderr, "B%c%c", 0b00000011, 0b11100000); break;}		//"DARK_GREEN"
		case 6: {fprintf(stderr, "B%c%c", 0b00000000, 0b00011111); break;}		//"LIGHT_BLUE"
		case 7: {fprintf(stderr, "B%c%c", 0b00000000, 0b00001111); break;}		//"DARK_BLUE"
		case 8: {fprintf(stderr, "B%c%c", 0b11111000, 0b00011111); break;}		//"VIOLET"
		case 9: {fprintf(stderr, "B%c%c", 0b00000000, 0b00000000); break;}		//"BLACK"
		case 10: {fprintf(stderr, "B%c%c", 0b11111111, 0b11111111); break;}		//"WHITE"
	}
}

void lcdLine(int x1, int y1, int x2, int y2, char color1, char color2)
{
	fprintf(stderr, "L%c%c%c%c%c%c%c%c%c%c", 0, x1, 0, y1, 0, x2, 0, y2, color1, color2);
}

void lcdDrawPolygon(int vertices, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7, int color1, int color2)
{
	switch(vertices)
	{
		case 3: fprintf(stderr, "g%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",3, 0, x1, 0, y1, 0, x2, 0, y2, 0, x3, 0, y3, color1, color2);
		case 4: fprintf(stderr, "g%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",4, 0, x1, 0, y1, 0, x2, 0, y2, 0, x3, 0, y3, 0, x4, 0, y4, color1, color2);
		case 5: fprintf(stderr, "g%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",5, 0, x1, 0, y1, 0, x2, 0, y2, 0, x3, 0, y3, 0, x4, 0, y4, 0, x5, 0, y5, color1, color2);
		case 6: fprintf(stderr, "g%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",6, 0, x1, 0, y1, 0, x2, 0, y2, 0, x3, 0, y3, 0, x4, 0, y4, 0, x5, 0, y5, 0, x6, 0, y6, color1, color2);
		case 7: fprintf(stderr, "g%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",7, 0, x1, 0, y1, 0, x2, 0, y2, 0, x3, 0, y3, 0, x4, 0, y4, 0, x5, 0, y5, 0, x6, 0, y6, 0, x7, 0, y7, color1, color2);
	}
}

void lcdDrawRectangle(int x1, int y1, int x2, int y2, char color1, char color2)
{
	fprintf(stderr, "r%c%c%c%c%c%c%c%c%c%c", 0, x1, 0, y1, 0, x2, 0, y2, color1, color2);
}

void lcdDrawEllipse(int x, int y, int xr, int yr, char color1, char color2)
{
	fprintf(stderr, "e%c%c%c%c%c%c%c%c%c%c", 0, x, 0, y, 0, xr, 0, yr, color1, color2);
}

void lcdDrawPixel(int x, int y, char color1, char color2)
{
	fprintf(stderr, "P%c%c%c%c%c%c", 0, x, 0, y, color1, color2);
}

void lcdSetPenSize(int i)
{
	//switch here is kinda useless;
	switch(i)
	{
		case 0: {fprintf(stderr, "p%c", i); break;}		//SOLID
		case 1: {fprintf(stderr, "p%c", i); break;}		//WIREFRAME
	}
}

//----------------------------------------------------------------------------------------------
//GRAPHICS COMMANDS

void lcdSetFont(int i)
{
	/*
	00hex : 5x7 small size font set
	01hex : 8x8 medium size font set
	02hex : 8x12 large size font set
	03hex : 12x16 largest size font set
	*/
	fprintf(stderr, "F%c", i);
}

void lcdSetOpacity(int mode)
{
	fprintf(stderr, "O%c", mode);
}

void lcdDrawASCII(char c, int x, int y, char color1, char color2)
{
	fprintf(stderr, "T%c%c%c%c%c", c, x, y, color1, color2);
}

//om een of andere vreemde reden wilt hij y = 10 niet afdrukken
void lcdDrawASCIIG(char c, int x, int y, char color1,  char color2, int w, int h)
{
	fprintf(stderr, "t%c%c%c%c%c%c%c%c%c", c, 0, x, 0, y, color1, color2, w, h);
}

void lcdDrawString(int x, int y, char size, char text[], char color1, char color2)
{
	fprintf(stderr, "s%c%c%c%c%c%s%c", x, y, size, color1, color2, text, 0x00);
}

//om een of andere reden wilt hij x = 10 niet afdrukken
void lcdDrawStringG(int x, int y, char size, int w, int h, char text[], char color1, char color2)
{
	fprintf(stderr, "S%c%c%c%c%c%c%c%c%c%s%c", 0, x, 0, y, size, color1, color2, w, h, text, 0x00);
}

/*
//16x16 BITMAP
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c
0b00000110	0b01100000
0b00001100	0b00110000
0b00011000	0b00011000
0b00011000	0b00011000
0b00011011	0b00011011
0b00111111	0b11111100
0b01111100	0b00111110
0b01111110	0b01111110
0b11011010	0b01011011
0b10011001	0b10011001
0b10011101	0b10111001
0b10001101	0b10110001
0b00000111	0b11100000
0b00000011	0b11000000
0b00111111	0b11111100
0b00011110	0b01111000
*/