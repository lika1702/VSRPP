// ListDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "SnopokIDZ_2.h"
#include "ListDlg.h"
#include "afxdialogex.h"
#include <vector>
#include <algorithm>


// диалоговое окно CListDlg

IMPLEMENT_DYNAMIC(CListDlg, CDialogEx)

CListDlg::CListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MANAGE_LIST, pParent)
{
	is_selected_even = false;
	is_selected_odd = false;
}

CListDlg::~CListDlg()
{
}

void CListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_SOURCE_LIST, m_source_list);
	DDX_Control(pDX, IDC_RESULT_LIST, m_result_list);
	DDX_Control(pDX, IDC_EVEN_STRING, m_even);
	DDX_Control(pDX, IDC_ODD_STRING, m_odd);
	DDX_Control(pDX, IDC_SOURCE_LIST, m_source_list);
}


BEGIN_MESSAGE_MAP(CListDlg, CDialogEx)
	ON_STN_CLICKED(IDC_ARROW, &CListDlg::OnStnClickedArrow)
	ON_BN_CLICKED(IDC_RESET_RESULT, &CListDlg::OnBnClickedResetResult)
	ON_BN_CLICKED(IDC_EVEN_STRING, &CListDlg::OnBnClickedEvenString)
	ON_BN_CLICKED(IDC_ODD_STRING, &CListDlg::OnBnClickedOddString)
	ON_STN_CLICKED(IDC_RESET_SELECTION, &CListDlg::OnStnClickedResetSelection)
END_MESSAGE_MAP()


// обработчики сообщений CListDlg

BOOL CListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Добавить дополнительную инициализацию

	int mas[20];
	for (int i = 0; i < 20; i++) {
		do {
			int number = rand()%1000 + 1;
			if (check(mas, i, number)) {
				mas[i] = number; break;
			}
		} while (true);
	}

	for (int i = 0; i < 20; i++) {
		char buf[255];
		_itoa_s(mas[i], buf, 10);
		m_source_list.AddString(CString(buf));
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}

bool CListDlg::check(int* mas, int size, int number) {
	for (int i = 0; i < size; i++)
		if (mas[i] == number) return false;
	return true;
}

void CListDlg::OnBnClickedResetResult() {
	m_result_list.ResetContent();
}

bool comp(int a, int b) {
	return a > b;
}

void CListDlg::OnStnClickedArrow() {
	CString selected_number;
	for (int i = 0; i < m_source_list.GetCount(); i++) {
		if (m_source_list.GetSel(i) != 0) {
			CString str;
			m_source_list.GetText(i, str);
			selected_number += str + _T(", ");
			m_selected.Add(str);
		}
	}
	if (m_selected.GetCount() == 0) selected_number = _T("Числа не выбраны");
	CEdit* pCtrl_1 = (CEdit*)GetDlgItem(IDC_STATIC_number);
	pCtrl_1->SetWindowTextW(selected_number);

	std::vector<int> mas = transformToInt();
	std::vector<int> mas_max = OnlyEven(mas, true);
	std::vector<int> mas_min = OnlyEven(mas, false);

	std::sort(mas_max.begin(), mas_max.end(), comp);
	std::sort(mas_min.begin(), mas_min.end());

	CString sum_even, sum_odd, str;
	sum_even += _T("Четные ");
	sum_odd += _T("Нечетные ");

	int sum = 0;

	for (int i = 0; i < 3 && i < mas_max.size(); i++) {
		char buf[255];
		_itoa_s(mas_max[i], buf, 10);
		sum_even += buf; sum_even += (CString)"   ";
		sum += mas_max.at(i);
	}
	str.Format(_T(": %d"), sum); sum = 0;
	sum_even += str;

	for (int i = 0; i < 3 && i < mas_min.size(); i++) {
		char buf[255];
		_itoa_s(mas_min[i], buf, 10);
		sum_odd += buf; sum_odd += (CString)"   ";
		sum += mas_min[i];
	}
	str.Format(_T(": %d"), sum);
	sum_odd += str;

	m_result_list.AddString(sum_even);
	m_result_list.AddString(sum_odd);

	m_selected.RemoveAll();
}


void CListDlg::OnBnClickedEvenString() {
	if (!is_selected_even) {
		for (int i = 0; i < m_source_list.GetCount(); i++)
			if (i % 2 == 0) m_source_list.SetSel(i + 1, 1);
		is_selected_even = true;
	}
	else {
		for (int i = 0; i < m_source_list.GetCount(); i++)
			if (i % 2 == 0) m_source_list.SetSel(i + 1, 0);
		is_selected_even = false;
	}
}
void CListDlg::OnBnClickedOddString() {
	if (!is_selected_odd) {
		for (int i = 1; i < m_source_list.GetCount(); i++)
			if (i % 2 == 1) m_source_list.SetSel(i - 1, 1);
		is_selected_odd = true;
	}
	else {
		for (int i = 1; i < m_source_list.GetCount(); i++)
			if (i % 2 == 1) m_source_list.SetSel(i - 1, 0);
		is_selected_odd = false;
	}
}

std::vector<int> CListDlg::transformToInt() {
	std::vector<int> mas;
	for (int i = 0; i < m_selected.GetCount(); i++)
		mas.push_back(_ttoi(m_selected.GetAt(i)));
	return mas;
}

std::vector<int> CListDlg::OnlyEven(std::vector<int> mas, bool even) {
	std::vector<int> mas_even, mas_odd;

	for (int i = 0; i < mas.size(); i++) {
		if (mas[i] % 2 == 0) mas_even.push_back(mas[i]);
		else mas_odd.push_back(mas[i]);
	}
		
	if(even) return mas_even;
	else return mas_odd;
}

void CListDlg::OnStnClickedResetSelection() {
	m_source_list.SetSel(-1, 0);
	m_even.SetCheck(false);
	m_odd.SetCheck(false);
	is_selected_even = false;
	is_selected_odd = false;
}
