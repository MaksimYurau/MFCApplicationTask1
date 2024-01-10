
// MFCApplicationTask1Doc.h: интерфейс класса CMFCApplicationTask1Doc 
//


#pragma once

#include <vector>

class CMFCApplicationTask1Doc : public CDocument
{
protected: // создать только из сериализации
	CMFCApplicationTask1Doc() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationTask1Doc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

	void AddLine(const CPoint& startPoint, const CPoint& endPoint);
	const std::vector<CPoint>& GetLines() const;
	void ClearLines();
	void RemoveLastLine();

#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMFCApplicationTask1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	std::vector<CPoint> lines; // Список линий
// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
