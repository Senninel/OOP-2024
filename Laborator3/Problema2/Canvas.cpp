#include "Canvas.h"
#include <stdio.h>
#include <iostream>


Canvas::Canvas(int width, int height)
{
	form = new char* [height];
	for (int i = 0; i < height; i++)
	{
		form[i] = new char[width];
		for (int j = 0; j < width; j++)
			form[i][j] = ' ';
	}
	this->width = width;
	this->height = height;
}

void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0;j < this->width; j++)
			form[i][j] = ' ';
}
void Canvas::Print()
{
	for (int i = 0;i < this->height;i++)
	{
		for (int j = 0;j < this->width;j++)
			printf("%c ", form[i][j]);
		printf("\n");
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left > right || left > width || left < 1 || right < 1 || right > width
		|| top > bottom || top < 1 || top > height || bottom < 1 || bottom > height)
	{
		printf("Date incorecte\n");
		return;
	}
	for (int i = left - 1;i < right;i++)
	{
		form[top - 1][i] = ch;
		form[bottom - 1][i] = ch;
	}
	for (int i = top - 1;i < bottom;i++)
	{
		form[i][left - 1] = ch;
		form[i][right - 1] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left > right || left > width || left < 1 || right < 1 || right > width
		|| top > bottom || top < 1 || top > height || bottom < 1 || bottom > height)
	{
		printf("Date incorecte\n");
		return;
	}
	for (int i = top - 1; i < bottom ; i++)
		for (int j = left - 1;j < right; j++)
			form[i][j] = ch;
}
void Canvas:: SetPoint(int x, int y, char ch)
{
	if (x >= this->width || x < 1 || y < 1 || y >= this->height)
	{
		printf("Date incorecte\n");
		return;
	}
	form[x - 1][y - 1] = ch;
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if (x < 1 || x >= this->height || y < 1 || y >= this->width)
	{
		printf("Cercul nu contine date corecte");
		return;
	}

	for(int i=0;i<this->height;i++)
		for(int j=0;j < this->width;j++)
	if(((i - (x-1))*(i - (x - 1))) + ((j - (y-1)) * (j - (y-1))) >= ray *(ray - 1)
		&& ((i - (x-1))* (i - (x-1))) + ((j - (y-1))* (j - (y-1))) <= ray*(ray + 1))
		form[i][j] = ch;
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	if (x < 1 || x >= this->height || y < 1 || y >= this->width)
	{
		printf("Cercul nu contine date corecte");
		return;
	}
	for (int i = 0;i < this->height;i++)
		for (int j = 0;j < this->width;j++)
			if (((i - (x-1)) * (i - (x-1)) + (j - (y-1)) * (j - (y-1)) <= ray * ray))
				form[i][j] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	if (x1 < 1 || x1 > this->width || x2 < 1 || x2 > this->width
		|| y1 < 1 || y1 > this->height || y2 < 1 || y2 > this->height)
	{
		printf("Nu se poate desena linia, date incorecte");
		return;
	}
	if (x1 > x2)
	{
		int aux = x1;
		x1 = x2;
		x2 = aux;
	}
	if (y1 > y2)
	{
		int aux = y1;
		y1 = y2;
		y2 = aux;
	}
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2 * dy - dx;
	int y = y1;
	for (int x = x1; x <= x2; x++)
	{
		form[x - 1][y - 1] = ch;
		if (D > 0)
		{
			y = y + 1;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}

