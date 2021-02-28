#pragma once
#include <afxcview.h>

// CSelectedView 视图

class CSelectedView : public CTreeView {
	DECLARE_DYNCREATE(CSelectedView)

protected:
	CSelectedView();           // 动态创建所使用的受保护的构造函数
	virtual ~CSelectedView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


