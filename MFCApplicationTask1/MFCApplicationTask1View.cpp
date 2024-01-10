
// MFCApplicationTask1View.cpp: реализация класса CMFCApplicationTask1View
//

// MFCApplicationTask1View.cpp

#include "pch.h"
#include <vector>

// #include "stdafx.h"
#include "MFCApplicationTask1.h"
#include "MFCApplicationTask1Doc.h"
#include "MFCApplicationTask1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCApplicationTask1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationTask1View, CView)
    ON_WM_LBUTTONDOWN()
    ON_WM_RBUTTONDOWN()
    ON_COMMAND(ID_CLEAR_LINES, &CMFCApplicationTask1View::OnClearLines)
    ON_UPDATE_COMMAND_UI(ID_CLEAR_LINES, &CMFCApplicationTask1View::OnUpdateClearLines)
    ON_COMMAND(ID_CLEAR_LAST_LINE, &CMFCApplicationTask1View::OnClearLastLine)
    ON_UPDATE_COMMAND_UI(ID_CLEAR_LAST_LINE, &CMFCApplicationTask1View::OnUpdateClearLastLine)
    ON_WM_KEYDOWN()
END_MESSAGE_MAP()

CMFCApplicationTask1View::CMFCApplicationTask1View() noexcept
{
}

CMFCApplicationTask1View::~CMFCApplicationTask1View()
{
}

BOOL CMFCApplicationTask1View::PreCreateWindow(CREATESTRUCT& cs)
{
    return CView::PreCreateWindow(cs);
}

void CMFCApplicationTask1View::OnDraw(CDC* pDC)
{
    CMFCApplicationTask1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // Получаем список линий из документа
    const std::vector<CPoint>& lines = pDoc->GetLines();

    // Рисуем каждую линию случайным цветом
    for (size_t i = 0; i < lines.size(); i += 2)
    {
        COLORREF randomColor = RGB(rand() % 256, rand() % 256, rand() % 256);
        CPen pen(PS_SOLID, 2, randomColor);
        CPen* pOldPen = pDC->SelectObject(&pen);

        pDC->MoveTo(lines[i]);
        pDC->LineTo(lines[i + 1]);

        pDC->SelectObject(pOldPen);
    }
}


#ifdef _DEBUG
void CMFCApplicationTask1View::AssertValid() const
{
    CView::AssertValid();
}

void CMFCApplicationTask1View::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

CMFCApplicationTask1Doc* CMFCApplicationTask1View::GetDocument() const // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationTask1Doc)));
    return (CMFCApplicationTask1Doc*)m_pDocument;
}
#endif //_DEBUG

void CMFCApplicationTask1View::OnLButtonDown(UINT nFlags, CPoint point)
{
    CMFCApplicationTask1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (pDoc)
    {
        // Добавляем случайные линии в список в документе
      
        CPoint endPoint(point.x + rand() % 50, point.y + rand() % 50);
        pDoc->AddLine(point, endPoint);
        

        // Обновляем представление
        Invalidate();
    }

    CView::OnLButtonDown(nFlags, point);
}


void CMFCApplicationTask1View::OnRButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here
    CView::OnRButtonDown(nFlags, point);
}

void CMFCApplicationTask1View::OnClearLines()
{
    CMFCApplicationTask1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (pDoc)
    {
        // Очищаем список линий в документе
        pDoc->ClearLines();

        // Обновляем представление
        Invalidate();
    }
}


void CMFCApplicationTask1View::OnUpdateClearLines(CCmdUI* pCmdUI)
{
    // TODO: Add your command update UI handler code here
}

void CMFCApplicationTask1View::OnClearLastLine()
{
    CMFCApplicationTask1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (pDoc)
    {
        // Удаляем последнюю линию из списка в документе
        pDoc->RemoveLastLine();

        // Обновляем представление
        Invalidate();
    }
}


void CMFCApplicationTask1View::OnUpdateClearLastLine(CCmdUI* pCmdUI)
{
    // TODO: Add your command update UI handler code here
}

void CMFCApplicationTask1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    if (nChar == VK_BACK)
    {
        // Удаляем последнюю линию при нажатии клавиши Backspace
        CMFCApplicationTask1Doc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);
        if (pDoc)
        {
            pDoc->RemoveLastLine();
            Invalidate();
        }
    }

    else if (nChar == VK_DELETE)
    {
        // Удаляем все линии при нажатии клавиши Delete
        CMFCApplicationTask1Doc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);
        if (pDoc)
        {
            pDoc->ClearLines();
            Invalidate();
        }
    }

    CView::OnKeyDown(nChar, nRepCnt, nFlags);
}