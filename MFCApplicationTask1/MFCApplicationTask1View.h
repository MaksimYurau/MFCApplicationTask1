
// MFCApplicationTask1View.h: интерфейс класса CMFCApplicationTask1View
//

#pragma once


class CMFCApplicationTask1View : public CView
{
protected: // создать только из сериализации
	CMFCApplicationTask1View() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationTask1View)

// Атрибуты
public:
	CMFCApplicationTask1Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMFCApplicationTask1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в MFCApplicationTask1View.cpp
inline CMFCApplicationTask1Doc* CMFCApplicationTask1View::GetDocument() const
   { return reinterpret_cast<CMFCApplicationTask1Doc*>(m_pDocument); }
#endif

