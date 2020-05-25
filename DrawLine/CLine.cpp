#include "pch.h"
#include "CLine.h"
#define Round(x) (int) (x+0.5)

void CLine::LineDDA(CDC* pDC, CPoint A, CPoint B, COLORREF color)
{
	LineDDA(pDC, A.x, A.y, B.x, B.y, color);
}

void CLine::LineDDA(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	if (x1 == x2 && y1 == y2)
	{
		pDC->SetPixel(x1, y1, color);
		return;
	}
	// 2 điểm khác nhau
	//kiểm tra tăng chậm giảm chậm/ tăng nhanh giảm nhanh
	//kiểm tra điểm đầu bên trái
	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		if (x2 >= x1)
			LineDDA1(pDC, x1, y1, x2, y2, color);
		else
			LineDDA1(pDC, x2, y2, x1, y1, color);
	}
	else
	{
		if (y2 >= y1) //khác
			LineDDA2(pDC, x1, y1, x2, y2, color);
		else
			LineDDA2(pDC, x2, y2, x1, y1, color);
	}
}

void CLine::LineBresenham(CDC* pDC, CPoint A, CPoint B, COLORREF color)
{
	LineBresenham(pDC, A.x, A.y, B.x, B.y, color);
}

void CLine::LineBresenham(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	if (x1 == x2 && y1 == y2)
	{
		pDC->SetPixel(x1, y1, color);
		return;
	}
	// 2 điểm khác nhau
	//kiểm tra tăng chậm giảm chậm/ tăng nhanh giảm nhanh
	//kiểm tra điểm đầu bên trái
	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		if (x2 >= x1)
			LineDDA1(pDC, x1, y1, x2, y2, color);
		else
			LineDDA1(pDC, x2, y2, x1, y1, color);
	}
	else
	{
		if (y2 >= y1) //khác
			LineDDA2(pDC, x1, y1, x2, y2, color);
		else
			LineDDA2(pDC, x2, y2, x1, y1, color);
	}
}

void CLine::LineDDA1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	float m=(float)(y2-y1)/(x2-x1);
	float y = y1;
	//xác định điểm đầu tiên - Vẽ điểm đầu tiên
	pDC->SetPixel(x1, y1, color);
	//xác định điểm tiếp theo 
	while (x1 < x2)
	{
		x1 = x1 + 1;
		y = y + m;
		pDC->SetPixel(x1, Round(y), color);
	}
}

void CLine::LineDDA2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	float k = (float)(x2 - x1) / (y2 - y1);
	float x = x1;
	//xác định điểm đầu - vễ điểm đầu
	pDC->SetPixel(x1, y1, color);
	//vể các điểm tiếp theo
	while (y1 < y2)
	{
		y1 = y1 + 1;
		x = x + k;
		pDC->SetPixel(Round(x), y1, color);
	}
}

void CLine::LineBresenham1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	//Đoạn thẳng tăng chậm giảm chậm
	int dx = x2 - x1;
	int dy = y2 - y1;

	int x = x1;
	int y = y1;
	//xác định điễm đầu tiên
	pDC->SetPixel(x1, y1, color);
	
	//tính p
	int p = 2 * dy - dx;
	int const1 = 2 * dy;
	int const2 = 2 * dy - 2 * dx;
	
	//xác định những điểm tiếp theo
	while (x<x2)
	{
		if (p < 0)
		{
			p = p + const1;
			x = x + 1;
			y = y;
		}
		else
		{
			p = p + const2;
			x = x + 1;
			y = y + 1;
		}
		pDC->SetPixel(x, y, color);
	}
}

void CLine::LineBresenham2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	//Đoạn thẳng tăng nhanh giảm nhanh
	int dx = x2 - x1;
	int dy = y2 - y1;
	//Xác định điểm đầu
	int x = x1;
	int y = y1;
	pDC->SetPixel(x, y, color);
	//tính p
	int p = 2 * dx - dy;
	int const1 = 2 * dx;
	int const2 = 2 * dx - 2 * dy;
	//xác định những điểm tiếp theo
	while (y < y2)
	{
		if (p < 0)
		{
			p = p + const1;
			x = x;
			y = y + 1;
		}
		else
		{
			p = p + const2;
			x = x + 1;
			y = y + 1;
		}
	}
	pDC->SetPixel(x, y, color);
}
