
// SnopokLR_8Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"
#include "MySocket.h"


// диалоговое окно CSnopokLR_8Dlg
class CSnopokLR_8Dlg : public CDialogEx
{
// Создание
public:
	CSnopokLR_8Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SNOPOKLR_8_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
private:
	CMySocket m_sListenSocket;
	CMySocket m_sConnectSocket;
protected:
	HICON m_hIcon;
	HICON m_Equals;
	HICON m_Multiply;
	HICON m_Divide;
	HICON m_Minus;
	HICON m_Plus;
	HICON m_Percent;
	HICON m_Clear;
	HICON m_CleanAll;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_ctlConnect;
	CString m_strName;
	CEdit m_strTask;
	CString m_result;
	int m_iType;
	void AddToString(CString param);
	void OnAccept();
	void OnConnect();
	void OnReceive();
	void OnClose();
	void ShowForm(bool param, bool paramForList);
	afx_msg void OnBnClickedRClient();
	afx_msg void OnBnClickedRServer();
	afx_msg void OnBnClickedNumberZero();
	afx_msg void OnBnClickedNumberOne();
	afx_msg void OnBnClickedNumberTwo();
	afx_msg void OnBnClickedNumberThree();
	afx_msg void OnBnClickedNumberFour();
	afx_msg void OnBnClickedNumberFive();
	afx_msg void OnBnClickedNumberSix();
	afx_msg void OnBnClickedNumberSeven();
	afx_msg void OnBnClickedNumberEight();
	afx_msg void OnBnClickedNumberNine();
	CEdit m_strResult;
	afx_msg void OnBnClickedOperationPercent();
	afx_msg void OnBnClickedOperationDivide();
	afx_msg void OnBnClickedOperationMultiply();
	afx_msg void OnBnClickedOperationMinuse();
	afx_msg void OnBnClickedOperationPlus();
	int m_iPort;
	afx_msg void OnBnClickedBConnect();
	afx_msg void OnBnClickedBDisconnect();
	afx_msg void OnBnClickedOperationFraction();
	afx_msg void OnBnClickedOperationClearAll();
	afx_msg void OnBnClickedOperationReset();
	afx_msg void OnBnClickedOperationEquals();
	CButton m_bPercent;
	CButton m_bMultiply;
	CButton m_bDivide;
	CButton m_bMinus;
	CButton m_bPlus;
	CButton m_bEqual;
	CButton m_bClear;
	CButton m_bCleanAll;
	afx_msg void OnBnClickedOperationLBrackets();
	afx_msg void OnBnClickedOperationRBrackets();
	CListBox m_list;
};
