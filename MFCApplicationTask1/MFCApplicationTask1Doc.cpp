
// MFCApplicationTask1Doc.cpp: реализация класса CMFCApplicationTask1Doc 
//

#include "pch.h"
// MFCApplicationTask1Doc.cpp

// #include "stdafx.h"
#include <vector>
#include "MFCApplicationTask1.h"
#include "MFCApplicationTask1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCApplicationTask1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplicationTask1Doc, CDocument)
END_MESSAGE_MAP()

CMFCApplicationTask1Doc::CMFCApplicationTask1Doc() noexcept
{
}

CMFCApplicationTask1Doc::~CMFCApplicationTask1Doc()
{
}

BOOL CMFCApplicationTask1Doc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    // TODO: Add your specialized code here and/or call the base class

    return TRUE;
}

void CMFCApplicationTask1Doc::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        // TODO: Add your storing code here
    }
    else
    {
        // TODO: Add your loading code here
    }
}
#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCApplicationTask1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
    // Modify this code to draw the document's data
    dc.FillRect(lprcBounds, &CBrush(RGB(255, 255, 255)));

    CString strText = _T("TODO: implement thumbnail drawing here");
    dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
}

// Support for Search Handlers
void CMFCApplicationTask1Doc::InitializeSearchContent()
{
    CString strSearchContent;
    // Set search contents from document's data. 
    // The content parts should be separated by ";"

    // For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
    SetSearchContent(strSearchContent);
}

void CMFCApplicationTask1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
    // Modify this code to draw the document's data
    dc.FillRect(lprcBounds, &CBrush(RGB(255, 255, 255)));

    CString strText = _T("TODO: implement thumbnail drawing here");
    dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
}

#endif // SHARED_HANDLERS

// Diagnostics
#ifdef _DEBUG
void CMFCApplicationTask1Doc::AssertValid() const
{
    CDocument::AssertValid();
}

void CMFCApplicationTask1Doc::Dump(CDumpContext& dc) const
{
    CDocument::Dump(dc);
}

void CMFCApplicationTask1Doc::AddLine(const CPoint& startPoint, const CPoint& endPoint)
{
    // Добавляем линию в список
    lines.push_back(startPoint);
    lines.push_back(endPoint);
}

const std::vector<CPoint>& CMFCApplicationTask1Doc::GetLines() const
{
    // Возвращаем список линий
    return lines;
}

void CMFCApplicationTask1Doc::ClearLines()
{
    // Очищаем список линий
    lines.clear();
}

void CMFCApplicationTask1Doc::RemoveLastLine()
{
    // Удаляем последнюю линию
    if (!lines.empty())
    {
        lines.pop_back();
        lines.pop_back();
    }
}
#endif //_DEBUG

