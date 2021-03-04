#include "Canvas.h"
#include<iostream>
#include<cmath>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->Clear();
}

void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			canv[i][j] = ' ';
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
			std::cout << canv[i][j] <<' ';
		std::cout << '\n' ;
	}
	this->Clear();
}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->canv[y][x] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			if ((pow(j - x, 2)) + (pow(i - y, 2)) <= pow(ray, 2))
				this->canv[i][j] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	this->FillCircle(x, y, ray, ch);
	this->FillCircle(x, y, ray - 1, ' ');
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			this->canv[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	int i;
	for (i = left; i <= right; i++)
	{
		this->canv[top][i] = ch;
		this->canv[bottom][i] = ch;
	}

	for (i = top; i <= bottom; i++)
	{
		this->canv[i][left] = ch;
		this->canv[i][right] = ch;
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, p, x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	x = x1;
	y = y1;

	p = 2 * dy - dx;

	while (x < x2)
	{
		if (p >= 0)
		{
			this->canv[y][x] = ch;
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			this->canv[y][x] = ch;
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}