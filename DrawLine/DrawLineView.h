
// DrawLineView.h : interface of the CDrawLineView class
//

#pragma once


class CDrawLineView : public CView
{
protected: // create from serialization only
	CDrawLineView() noexcept;
	DECLARE_DYNCREATE(CDrawLineView)

// Attributes
public:
	CDrawLineDoc* GetDocument() const;
	CPoint start;
	CPoint end;
// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in DrawLineView.cpp
inline CDrawLineDoc* CDrawLineView::GetDocument() const
   { return reinterpret_cast<CDrawLineDoc*>(m_pDocument); }
#endif

