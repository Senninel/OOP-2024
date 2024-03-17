#include "canvas.h"
#include <stdio.h>
#include <stdarg.h>

canvas::canvas(int lines, int columns)
{
	form = new char* [lines];
	for (int i = 0; i < lines; i++)
		form[i] = new char[columns];
	this->height = lines;
	this->width = columns;
	clear();
}
void canvas::clear()
{
	for (int i = 0; i < this->height;i++)
		for (int j = 0;j < this->width;j++)
			form[i][j] = ' ';
}
int canvas::ThrowError(int x, int y)
{
	if (x < 1 || x > this->width ||
		y < 1 || y> this->height)
		return 1;
	return 0;
}
void canvas::set_pixel(int x, int y, char value)
{
	if (ThrowError(x, y))
	{
		printf("Nu s-a putut pune pixelul, date incorecte");
		return;
	}
	form[x - 1][y - 1] = value;
}
void canvas::set_pixels(int count, ...)
{
	va_list v1;
	va_start(v1, count);
	for (int i = 0;i < count;i++)
	{
		int x = va_arg(v1, int);
		int y = va_arg(v1, int);
		int ch = va_arg(v1, int);
		if (!ThrowError(x, y)) form[x - 1][y - 1] = ch;
	}
	va_end(v1);
}
void canvas::print() const
{
	for (int i = 0;i < this->height;i++)
	{
		for (int j = 0;j < this->width;j++)
			printf("%c", form[i][j]);
		printf("\n");
	}
}
