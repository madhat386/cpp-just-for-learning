
// MFCTreeCtrlDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCTreeCtrl.h"
#include "MFCTreeCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx {
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCTreeCtrlDlg 对话框



CMFCTreeCtrlDlg::CMFCTreeCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTREECTRL_DIALOG, pParent) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTreeCtrlDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_Tree);
}

BEGIN_MESSAGE_MAP(CMFCTreeCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CMFCTreeCtrlDlg::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// CMFCTreeCtrlDlg 消息处理程序

BOOL CMFCTreeCtrlDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr) {
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty()) {
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TreeCtrl控件使用

	//1.设置资源
	//准备好图标集合
	this->list.Create(30, 30, ILC_COLOR32, 4, 4);
	//加入图片
	HICON icon[4];
	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON3);
	icon[3] = AfxGetApp()->LoadIconW(IDI_ICON4);
	for (int i = 0; i < 4; ++i) {
		list.Add(icon[i]);
	}

	m_Tree.SetImageList(&list, TVSIL_NORMAL);

	//2.设置节点
	HTREEITEM root = m_Tree.InsertItem(TEXT("根节点"), 0, 0, NULL);
	HTREEITEM parent = m_Tree.InsertItem(TEXT("父节点"), 1, 1, root);
	HTREEITEM child1 = m_Tree.InsertItem(TEXT("子节点1"), 2, 2, parent);
	m_Tree.InsertItem(TEXT("子节点2"), 3, 3, parent);

	//代码设置选中的节点（这里子节点1）
	m_Tree.SelectItem(child1);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCTreeCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam) {
	if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else {
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCTreeCtrlDlg::OnPaint() {
	if (IsIconic()) {
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);

	}
	else {
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCTreeCtrlDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTreeCtrlDlg::OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) {
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//获取到当前选中节点的内容
	HTREEITEM item = m_Tree.GetSelectedItem();
	CString str = m_Tree.GetItemText(item);
	MessageBoxW(str);
	*pResult = 0;
}
