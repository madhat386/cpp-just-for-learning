
// MFCEditCtrlDlg.h: 头文件
//

#pragma once


// CMFCEditCtrlDlg 对话框
class CMFCEditCtrlDlg : public CDialogEx
{
// 构造
public:
	CMFCEditCtrlDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCEDITCTRL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CEdit m_Edit1;
public:
	CEdit m_Edit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
	afx_msg void OnBnClickedButton3();
private:
	CString m_Edit3_val;
public:
	afx_msg void OnBnClickedButton4();
};
