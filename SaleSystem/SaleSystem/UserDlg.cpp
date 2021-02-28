// UserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "UserDlg.h"
#include "InfoFile.h"

// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(CUserDlg::IDD)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newPwd(_T(""))
	, m_surePwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newPwd);
	DDX_Text(pDX, IDC_EDIT4, m_surePwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CUserDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CUserDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CUserDlg ���

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg ��Ϣ�������


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	//��ʼ������
	m_user = TEXT("����Ա");
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	m_name = name;

	UpdateData(FALSE);


	// TODO:  �ڴ����ר�ô����/����û���
}


void CUserDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//�޸�����ȷ����ť

	UpdateData(TRUE);

	if (m_newPwd.IsEmpty() || m_surePwd.IsEmpty())
	{
		MessageBox(TEXT("��������ݲ���Ϊ��"));
		return;
	}

	//��������ȷ��Ҫһ��
	if (m_newPwd!= m_surePwd)
	{
		MessageBox(TEXT("��������ȷ������Ҫһ��"));
		return;
	}

	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);

	//��������ԭ����Ҫ��һ��
	if (m_newPwd == pwd)
	{
		MessageBox(TEXT("��������ԭ�����ظ���"));
		return;
	}

	//�޸�����
	//CString - > char * 
	CStringA tmpName;
	CStringA tmpPwd;
	tmpName = name;
	tmpPwd = m_newPwd;

	file.WritePwd(tmpName.GetBuffer(), tmpPwd.GetBuffer());
	MessageBox(TEXT("�޸ĳɹ�"));

	//�����������
	m_newPwd.Empty();
	m_surePwd.Empty();

	UpdateData(FALSE);


}


void CUserDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//ȡ����ť
	//�����������
	m_newPwd.Empty();
	m_surePwd.Empty();

	UpdateData(FALSE);
}
