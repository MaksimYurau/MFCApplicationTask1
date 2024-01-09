
// MFCApplicationTask1View.cpp: реализация класса CMFCApplicationTask1View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplicationTask1.h"
#endif

#include "MFCApplicationTask1Doc.h"
#include "MFCApplicationTask1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationTask1View

IMPLEMENT_DYNCREATE(CMFCApplicationTask1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationTask1View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplicationTask1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CMFCApplicationTask1View

CMFCApplicationTask1View::CMFCApplicationTask1View() noexcept
{
	// TODO: добавьте код создания

}

CMFCApplicationTask1View::~CMFCApplicationTask1View()
{
}

BOOL CMFCApplicationTask1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CMFCApplicationTask1View

void CMFCApplicationTask1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplicationTask1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CMFCApplicationTask1View


void CMFCApplicationTask1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplicationTask1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationTask1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMFCApplicationTask1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CMFCApplicationTask1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplicationTask1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CMFCApplicationTask1View

#ifdef _DEBUG
void CMFCApplicationTask1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationTask1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationTask1Doc* CMFCApplicationTask1View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationTask1Doc)));
	return (CMFCApplicationTask1Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMFCApplicationTask1View
