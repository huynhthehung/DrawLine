#pragma once
class CLine
{
public:
	//DDA
	static void LineDDA(CDC* pDC, CPoint A, CPoint B, COLORREF color);
	static void LineDDA(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	//Bresenham
	static void LineBresenham(CDC* pDC, CPoint A, CPoint B, COLORREF color);
	static void LineBresenham(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
private:
	//DDA
	//Xử lý đường thẳng tăng chậm, giảm chậm - lập theo x
	static void LineDDA1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	//xử lý đường thẳng tăng nhanh, giảm nhanh - lập theo y
	static void LineDDA2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);

	//Bresenham
	//Xử lý đường thẳng tăng chậm, giảm chậm - lặp theo x
	static void LineBresenham1(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	//xử lý đường thẳng tăng nhanh, giảm nhanh - lặp theo y
	static void LineBresenham2(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
};

