// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "AddDlg.h"
#include "InfoFile.h"


// CAddDlg

IMPLEMENT_DYNCREATE(CAddDlg, CFormView)

CAddDlg::CAddDlg()
	: CFormView(CAddDlg::IDD)
	, m_price1(0)
	, m_num1(0)
	, m_name2(_T(""))
	, m_price2(0)
	, m_num2(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price1);
	DDX_Text(pDX, IDC_EDIT2, m_num1);
	DDX_Text(pDX, IDC_EDIT6, m_name2);
	DDX_Text(pDX, IDC_EDIT5, m_price2);
	DDX_Text(pDX, IDC_EDIT4, m_num2);
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAddDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CAddDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CAddDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CAddDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CAddDlg ���

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDlg ��Ϣ�������


void CAddDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();


	CInfoFile file;
	file.ReadDocline();

	// file.ls �����������������Ʒ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{

		m_combo.AddString(CString(it->name.c_str()));
	}

	//����Ĭ��ֵ
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
	// TODO:  �ڴ����ר�ô����/����û���
}


void CAddDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	int index = m_combo.GetCurSel();
	CString str;
	m_combo.GetLBText(index, str);

	//������Ʒ���� ��ȡ�����Ʒ�Ŀ��͵��ۣ���ʾ��������
	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == str)
		{
			m_price1 = it->price;
			UpdateData(FALSE);
		}
	}
}


void CAddDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�����Ʒ������ť����¼�

	UpdateData(TRUE);

	//��֤����

	if (m_num1 <= 0)
	{
		MessageBox(TEXT("�����������С�ڵ���0"));
		return;
	}

	//��ȡ��ӵ���Ʒ����
	int index = m_combo.GetCurSel();
	CString str;
	m_combo.GetLBText(index, str);

	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == str)
		{
			//���ӿ����
			it->num += m_num1;
			m_num1 = 0;
			UpdateData(FALSE);
			MessageBox(TEXT("��ӳɹ���"));
		}
	}

	//����Ʒͬ�����ļ���
	file.WirteDocline();

}


void CAddDlg::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_num1 = 0;
	UpdateData(FALSE);

	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
}


void CAddDlg::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�������Ʒ��ť�¼�

	UpdateData(TRUE);

	if (m_name2.IsEmpty() || m_price2<= 0 || m_num2 <= 0 )
	{
		MessageBox(TEXT("������Ϣ����"));
		return;
	}

	CInfoFile file;
	file.ReadDocline(); //��ȡ��������
	file.Addline(m_name2, m_num2, m_price2);

	//������ͬ�����ļ���
	file.WirteDocline();
	MessageBox(TEXT("�������Ʒ�ɹ�"));

	m_combo.InsertString(0, m_name2);

	m_combo.SetCurSel(0);

	OnCbnSelchangeCombo1();

	//���
	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);

}


void CAddDlg::OnBnClickedButton8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//���
	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);
}
