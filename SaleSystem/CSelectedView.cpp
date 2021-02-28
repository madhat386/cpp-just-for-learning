// CSelectedView.cpp: 实现文件
//

#include "pch.h"
#include "SaleSystem.h"
#include "CSelectedView.h"


// CSelectedView

IMPLEMENT_DYNCREATE(CSelectedView, CTreeView)

CSelectedView::CSelectedView() {

}

CSelectedView::~CSelectedView() {
}

BEGIN_MESSAGE_MAP(CSelectedView, CTreeView)
END_MESSAGE_MAP()


// CSelectedView 诊断

#ifdef _DEBUG
void CSelectedView::AssertValid() const {
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectedView::Dump(CDumpContext& dc) const {
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectedView 消息处理程序
