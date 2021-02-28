// SellDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "SellDlg.h"
#include "InfoFile.h"


// CSellDlg

IMPLEMENT_DYNCREATE(CSellDlg, CFormView)

CSellDlg::CSellDlg()
	: CFormView(CSellDlg::IDD)
	, m_left(0)
	, m_price(0)
	, m_num(0)
	, m_sellInfo(_T(""))
{

}

CSellDlg::~CSellDlg()
{
}

void CSellDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_left);
	DDX_Text(pDX, IDC_EDIT2, m_price);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_sellInfo);
}

BEGIN_MESSAGE_MAP(CSellDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSellDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSellDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CSellDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CSellDlg ���

#ifdef _DEBUG
void CSellDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSellDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSellDlg ��Ϣ�������


void CSellDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	//��ʼ�����۹������
	//��ʼ��������
	CInfoFile file;
	file.ReadDocline();

	 // file.ls �����������������Ʒ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{

		m_combo.AddString( CString(it->name.c_str()));
	}

	//����Ĭ��ֵ
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
	

	// TODO:  �ڴ����ר�ô����/����û���
}


void CSellDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��Ʒ�л� �����¼�

	//��ȡ��ǰ����ֵ
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
			m_left = it->num;
			m_price = it->price;
			UpdateData(FALSE);
		}		
	}


}


void CSellDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//������Ʒ ��ť���

	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(TEXT("�����������0"));
		return;
	}

	//���ܴ��ڿ����
	if (m_left < m_num)
	{
		MessageBox(TEXT("����������ܴ��ڿ����"));
		return;
	}

	//������
	int index = m_combo.GetCurSel();
	CString str;
	m_combo.GetLBText(index, str);
	//str�ǹ������Ʒ����

	CInfoFile file;
	file.ReadDocline();
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (CString(it->name.c_str()) == str)
		{
			it->num -= m_num;
			m_left = it->num;
			//�Ҳ���Ϣ��ʾ TEXT ==== _T
			CString info;
			info.Format(TEXT("��Ʒ��%s \r\n���ۣ�%d \r\n������%d \r\n�ܼۣ�%d"), str, m_price, m_num, m_price*m_num);
			m_sellInfo = info;
			//�´����� ��0��ʼ
			m_num = 0;

			UpdateData(FALSE);
			MessageBox(TEXT("����ɹ�"));
		}
	}

	//��ʾ�������
	m_sellInfo.Empty();

	//������д���ļ���
	file.WirteDocline();

	UpdateData(FALSE);

}


void CSellDlg::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//ȡ����ť
	m_num = 0;
	UpdateData(FALSE);

	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();

}
