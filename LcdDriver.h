#ifndef LCDDRIVER_H_
#define LCDDRIVER_H_

//GENERAL COMMANDS
/**
@brief Sends the autoboaud command

This must be the very first command sent to the PICASO-SGC (at 9600 baud) after powerup
or reset.
*/
void lcdAutoBaud(void);
/**
@brief Set a new baud rate

Set a new baud rate
@verbatim
00hex : 110 Baud
01hex : 300 Baud
02hex : 600 Baud
03hex : 1200 Baud
04hex : 2400 Baud
05hex : 4800 Baud
06hex : 9600 Baud
07hex : 14400 Baud
08hex : 19200 Baud
09hex : 31250 Baud
0Ahex : 38400 Baud
0Bhex : 56000 Baud
0Chex : 57600 Baud
0Dhex : 115200 Baud
0Ehex : 128000 Baud
0Fhex : 256000 Baud
@endverbatim
@param int range 0-15
*/
void lcdSetBaud(int);
/**
@brief Sets a new background color

Sets a new background color
@verbatim
case 0:	"LIGHT_RED"
case 1:	"DARK_RED"
case 2: "ORANGE"
case 3:	"YELLOW"
case 4:	"LIGHT_GREEN"
case 5: "DARK_GREEN"
case 6: "LIGHT_BLUE"
case 7: "DARK_BLUE"
case 8: "VIOLET"
case 9:	"BLACK"
case 10: "WHITE"
@endverbatim
@param int range 0-8
*/
void lcdReplaceBackground(int);
/**
@brief clears the screen using the background color

clears the screen using the background color
*/
void lcdClear(void);
/**
@brief Control modes for the lcd

Control modes for the lcd
@verbatim
case 0: Backlight control (0-1)
case 1: Display on-off (0-1)
case 2: Display contrast adjust (0-15)
case 3: Display powerUp-shutdown (0-1)
case 4: Display Orientation (1-4)
@endverbatim
@param int range 0-8
*/
void lcdControlMode(int i, int j);
//GRAPHICS COMMANS
/**
@brief Draws a circle

Draws a circle
@verbatim
This command will draw a colored circle centered at (x, y) with a radius determined by
the value set in the 'radius' byte. The circle can be either solid or wire frame (empty)
depending on the value of the Pen Size (see Set Pen Size command).
when Pen Size = 0 : circle is solid
when Pen Size = 1 : circle is wire frame
@endverbatim
@param x int range 0-240
@param y int range 0-320
@param radius
@param color1
@param color2
*/
void lcdCircle(int , int , int , char , char);
/**
@brief Draws a triangle

draws a triangle
@verbatim
This command draws a Solid/Wire-Frame triangle. The vertices must be specified in an
anti-clock wise manner, i.e.
x2 < x1 : x3 > x2 : y2 > y1 : y3 > y1
A solid or a wire frame triangle is determined by the value of the Pen Size setting.
when Pen Size = 0 : triangle is solid
when Pen Size = 1 : triangle is wire frame
@endverbatim
@param x1 int range 0-240
@param y1 int range 0-320
@param x2 int range 0-240
@param y2 int range 0-320
@param x3 int range 0-240
@param y3 int range 0-320
@param color1
@param color2
*/
void lcdTriangle(int, int, int, int, int, int, char, char);
/**
@brief Sets a new background color

Sets a new background color
@verbatim
case 0:	"LIGHT_RED"
case 1:	"DARK_RED"
case 2: "ORANGE"
case 3:	"YELLOW"
case 4:	"LIGHT_GREEN"
case 5: "DARK_GREEN"
case 6: "LIGHT_BLUE"
case 7: "DARK_BLUE"
case 8: "VIOLET"
case 9:	"BLACK"
case 10: "WHITE"
@endverbatim
@param int range 0-8
*/
void lcdSetBackground(int color);
/**
@brief Draw a line

This command will draw a colored line from point (x1, y1) to point (x2, y2) on the
screen.
@param x1 int range 0-240
@param y1 int range 0-320
@param x2 int range 0-240
@param y2 int range 0-320
@param color1
@param color2
*/
void lcdLine(int, int, int ,int, char, char);
/**
@brief Draw a polygon

This command draws an Empty/Wire-Frame polygon. Up to 7 vertices can be specified in
any manner.
@verbatim
LEAVE ALL THE UNUSED VERTICES TO 0.
A solid or a wire frame Polygon is determined by the value of the Pen Size setting.
when Pen Size = 0 : Polygon is solid
when Pen Size = 1 : Polygon is wire frame
@endverbatim
@param vertices int number of vertices (3-7)
@param x1 int range 0-240
@param y1 int range 0-320
@param x2 int range 0-240
@param y2 int range 0-320
@param x3 int range 0-240
@param y3 int range 0-320
@param x4 int range 0-240
@param y4 int range 0-320
@param x5 int range 0-240
@param y5 int range 0-320
@param x6 int range 0-240
@param y6 int range 0-320
@param x7 int range 0-240
@param y7 int range 0-320
@param color1
@param color2
*/
void lcdDrawPolygon(int vertices, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7, int color1, int color2);
/**
@brief Draw a rectangle

This command will draw a coloured rectangle from point (x1, y1) to point (x2, y2) on the
screen. If colour is chosen to be that of the background then the effect will be erasure. If
Pen Size value was previously set to 0, the rectangle will be solid, otherwise it will be wireframe
if value was 1.
@param x1 int range 0-240
@param y1 int range 0-320
@param x2 int range 0-240
@param y2 int range 0-320
@param color1
@param color2
*/
void lcdDrawRectangle(int, int, int ,int, char, char);
/**
@brief Draws an ellipse

This command will draw a coloured ellipse centred at (x, y) with its shape determined by
the values of rx (the x radius) and ry (the y radius). The ellipse can be either solid or wire
frame (empty) depending on the value of the Pen Size (see Set Pen Size command).
@verbatim
Pen Size = 0 : ellipse is solid
Pen Size = 1 : ellipse is wire frame.
@endverbatim
@param x int range 0-240
@param y int range 0-320
@param radius x
@param radius y
@param color1
@param color2
*/
void lcdDrawEllipse(int , int , int, int , char , char);
/**
@brief Draws a circle

Description This command will draw a coloured pixel at location (x, y) on the screen.
@param x int range 0-240
@param y int range 0-320
@param color1
@param color2
*/
void lcdDrawPixel(int, int, char, char);
/**
@brief Pen size

This command determines if certain graphics objects are drawn in solid or wire frame
fashion.
@param int 0:solid - 1:wireframe
*/
void lcdSetPenSize(int);

//TEXT COMMANDS
/**
@brief Set Font

This command selects one of the available internal fonts. Changes take place after the
command is sent. Any character on the screen with the previous font set will remain as it
was.
@verbatim
The supplied 3 fonts are:
00hex : 5x7 small size font set
01hex : 8x8 medium size font set
02hex : 8x12 large size font set
03hex : 12x16 largest size font set
@endverbatim
@param int 0-3
*/
void lcdSetFont(int);
/**
@brief Set Opacity

This command will change the attribute of the text so that an object behind the text can
either be blocked or transparent. Changes take place after the command is sent.
@verbatim
Select one of the following options for text appearance:
00hex : Transparent, objects behind text are visible.
01hex : Opaque, objects behind text blocked by background.
@endverbatim
@param int 0-1
*/
void lcdSetOpacity(int);
/**
@brief Draw ASCII character

This command will draw/display an ASCII character anywhere on the screen in character
unit coordinates. The horizontal position of the character is specified by the column and
the vertical position is specified by the row parameters.
Use the ”Set Font - 46hex” command to select the desired font.
@param char ascii character
@param column int character units
@param row int character units
@param color1
@param color2
*/
void lcdDrawASCII(char, int, int, char, char);
/**
@brief Draw ASCII character graphically

This command will draw/display an ASCII character anywhere on the screen in pixel
coordinates specified by x and y parameters. Unlike the ‘Draw ASCII Character (text
format)’ command, this option allows text of any size (determined by width and height) to
be placed at any position. The font of the character is determined by the ‘Set Font’
command.
@param char ascii character
@param x int range 0-240
@param y int range 0-320
@param color1
@param color2
@param width horizontal size multiplier
@param height vertical size multiplier
*/
void lcdDrawASCIIG(char, int, int, char, char, int, int);
/**
@brief Draw String of ASCII

This command will draw/display a string of
ASCII text anywhere on the screen in
character unit coordinates. The horizontal
start position of the string is specified by the
column and the vertical position is specified
by the row parameters. The string must be
terminated with 00hex. If the length of the
string is longer than the maximum number
of characters per line, a wrap around will
occur on to the next line. Maximum string
length is 256 bytes.
@verbatim
The supplied fonts are:
0 : 5x7 internal font
1 : 8x8 internal font
2 : 8x12 internal font
3 : 12x16 internal font
@endverbatim
@param column Horizontal start position of the string (character units).
@param row Vertical start position of the string (character units).
@param font
@param string char[]
@param color1
@param color2
*/
void lcdDrawString(int , int, char ,char* , char, char);
/**
@brief Draw String of ASCII Graphically

This command will draw/display a string of ASCII text anywhere on the screen in pixel
coordinates specified by x and y parameters. The horizontal start position of the string is
specified by x and the vertical position is specified by y. The string must be terminated with
00hex. The size of the characters are determined by the width and height parameters. If the
length of the string is longer than the maximum number of characters per line, a wrap
around will occur on to the next line. Maximum string length is 512 bytes.
@verbatim
The supplied fonts are:
0 : 5x7 internal font
1 : 8x8 internal font
2 : 8x12 internal font
3 : 12x16 internal font
@endverbatim
@param x Top left horizontal start position of the string (pixel units). range 0-240
@param y Top left vertical start position of the string (pixel units). range 0-320
@param font
@param width
@param heigth
@param string char[]
@param color1
@param color2
*/
void lcdDrawStringG(int, int, char, int, int, char*, char, char);
//void lcdAddUserBitmap();
//void lcdDrawUserBitmap(int, int, char , char );

#endif /* LCDDRIVER_H_ */