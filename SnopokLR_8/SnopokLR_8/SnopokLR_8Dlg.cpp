
// SnopokLR_8Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "SnopokLR_8.h"
#include "SnopokLR_8Dlg.h"
#include "afxdialogex.h"
#include "parser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CSnopokLR_8Dlg



CSnopokLR_8Dlg::CSnopokLR_8Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SNOPOKLR_8_DIALOG, pParent)
	, m_strName(_T(""))
	, m_iType(0)
	, m_iPort(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Equals = AfxGetApp()->LoadIconW(IDI_EQUALS);
	m_Multiply = AfxGetApp()->LoadIcon(IDI_MULTIPLY);
	m_Divide = AfxGetApp()->LoadIconW(IDI_DIVIDE);
	m_Minus = AfxGetApp()->LoadIconW(IDI_MINUS);
	m_Plus = AfxGetApp()->LoadIconW(IDI_PLUS);
	m_Percent = AfxGetApp()->LoadIconW(IDI_PERCENT);
	m_Clear = AfxGetApp()->LoadIconW(IDI_CLEAN_ONE);
	m_CleanAll = AfxGetApp()->LoadIconW(IDI_CLEAN_ALL);
}

void CSnopokLR_8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_B_CONNECT, m_ctlConnect);
	DDX_Text(pDX, IDC_E_SERVER_NAME, m_strName);
	DDX_Radio(pDX, IDC_R_CLIENT, m_iType);
	DDX_Control(pDX, IDC_TASK, m_strTask);
	DDX_Control(pDX, IDC_RESULT, m_strResult);
	DDX_Text(pDX, IDC_E_SERVER_PORT, m_iPort);
	DDX_Control(pDX, IDC_OPERATION_PERCENT, m_bPercent);
	DDX_Control(pDX, IDC_OPERATION_MULTIPLY, m_bMultiply);
	DDX_Control(pDX, IDC_OPERATION_DIVIDE, m_bDivide);
	DDX_Control(pDX, IDC_OPERATION_MINUSE, m_bMinus);
	DDX_Control(pDX, IDC_OPERATION_PLUS, m_bPlus);
	DDX_Control(pDX, IDC_OPERATION_EQUALS, m_bEqual);
	DDX_Control(pDX, IDC_OPERATION_RESET, m_bClear);
	DDX_Control(pDX, IDC_OPERATION_CLEAR_ALL, m_bCleanAll);
	DDX_Control(pDX, IDC_LIST_TASK, m_list);
}

BEGIN_MESSAGE_MAP(CSnopokLR_8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_R_CLIENT, &CSnopokLR_8Dlg::OnBnClickedRClient)
	ON_BN_CLICKED(IDC_R_SERVER, &CSnopokLR_8Dlg::OnBnClickedRServer)
	ON_BN_CLICKED(IDC_NUMBER_ZERO, &CSnopokLR_8Dlg::OnBnClickedNumberZero)
	ON_BN_CLICKED(IDC_NUMBER_ONE, &CSnopokLR_8Dlg::OnBnClickedNumberOne)
	ON_BN_CLICKED(IDC_NUMBER_TWO, &CSnopokLR_8Dlg::OnBnClickedNumberTwo)
	ON_BN_CLICKED(IDC_NUMBER_THREE, &CSnopokLR_8Dlg::OnBnClickedNumberThree)
	ON_BN_CLICKED(IDC_NUMBER_FOUR, &CSnopokLR_8Dlg::OnBnClickedNumberFour)
	ON_BN_CLICKED(IDC_NUMBER_FIVE, &CSnopokLR_8Dlg::OnBnClickedNumberFive)
	ON_BN_CLICKED(IDC_NUMBER_SIX, &CSnopokLR_8Dlg::OnBnClickedNumberSix)
	ON_BN_CLICKED(IDC_NUMBER_SEVEN, &CSnopokLR_8Dlg::OnBnClickedNumberSeven)
	ON_BN_CLICKED(IDC_NUMBER_EIGHT, &CSnopokLR_8Dlg::OnBnClickedNumberEight)
	ON_BN_CLICKED(IDC_NUMBER_NINE, &CSnopokLR_8Dlg::OnBnClickedNumberNine)
	ON_BN_CLICKED(IDC_OPERATION_PERCENT, &CSnopokLR_8Dlg::OnBnClickedOperationPercent)
	ON_BN_CLICKED(IDC_OPERATION_DIVIDE, &CSnopokLR_8Dlg::OnBnClickedOperationDivide)
	ON_BN_CLICKED(IDC_OPERATION_MULTIPLY, &CSnopokLR_8Dlg::OnBnClickedOperationMultiply)
	ON_BN_CLICKED(IDC_OPERATION_MINUSE, &CSnopokLR_8Dlg::OnBnClickedOperationMinuse)
	ON_BN_CLICKED(IDC_OPERATION_PLUS, &CSnopokLR_8Dlg::OnBnClickedOperationPlus)
	ON_BN_CLICKED(IDC_B_CONNECT, &CSnopokLR_8Dlg::OnBnClickedBConnect)
	ON_BN_CLICKED(IDC_B_DISCONNECT, &CSnopokLR_8Dlg::OnBnClickedBDisconnect)
	ON_BN_CLICKED(IDC_OPERATION_FRACTION, &CSnopokLR_8Dlg::OnBnClickedOperationFraction)
	ON_BN_CLICKED(IDC_OPERATION_CLEAR_ALL, &CSnopokLR_8Dlg::OnBnClickedOperationClearAll)
	ON_BN_CLICKED(IDC_OPERATION_RESET, &CSnopokLR_8Dlg::OnBnClickedOperationReset)
	ON_BN_CLICKED(IDC_OPERATION_EQUALS, &CSnopokLR_8Dlg::OnBnClickedOperationEquals)
	ON_BN_CLICKED(IDC_OPERATION_L_BRACKETS, &CSnopokLR_8Dlg::OnBnClickedOperationLBrackets)
	ON_BN_CLICKED(IDC_OPERATION_R_BRACKETS, &CSnopokLR_8Dlg::OnBnClickedOperationRBrackets)
END_MESSAGE_MAP()

// обработчики сообщений CSnopokLR_8Dlg
BOOL CSnopokLR_8Dlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL) {
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty()) {
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	m_bPercent.SetIcon(m_Percent);
	m_bMultiply.SetIcon(m_Multiply);
	m_bDivide.SetIcon(m_Divide);
	m_bMinus.SetIcon(m_Minus);
	m_bPlus.SetIcon(m_Plus);
	m_bEqual.SetIcon(m_Equals);
	m_bClear.SetIcon(m_Clear);
	m_bCleanAll.SetIcon(m_CleanAll);

	// TODO: добавьте дополнительную инициализацию
	m_iType = 0;
	m_strName = "loopback";
	m_iPort = 4000;

	UpdateData(FALSE);

	m_sConnectSocket.SetParent(this);
	m_sListenSocket.SetParent(this);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CSnopokLR_8Dlg::OnSysCommand(UINT nID, LPARAM lParam) {
	if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else { CDialogEx::OnSysCommand(nID, lParam); }
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSnopokLR_8Dlg::OnPaint() {
	if (IsIconic()) {
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else { CDialogEx::OnPaint(); }
}

// Система вызывает эту функцию для получения отображения курсора при перемещении свернутого окна.
HCURSOR CSnopokLR_8Dlg::OnQueryDragIcon() { return static_cast<HCURSOR>(m_hIcon); }

void CSnopokLR_8Dlg::OnBnClickedRClient() {
	UpdateData(TRUE);
	GetDlgItem(IDC_STATIC_NEW)->SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW);
	ShowForm(SW_SHOW, SW_HIDE);

	m_ctlConnect.SetWindowText(TEXT("Подключить"));
}
void CSnopokLR_8Dlg::OnBnClickedRServer() {
	UpdateData(TRUE);
	WINDOWPLACEMENT point;
	CRect rect;
	GetDlgItem(IDC_STATIC_CALCULATOR)->GetWindowPlacement(&point); GetDlgItem(IDC_STATIC_CALCULATOR)->GetClientRect(rect);
	GetDlgItem(IDC_STATIC_NEW)->SetWindowPos(NULL, point.rcNormalPosition.left, point.rcNormalPosition.top, rect.Width() + 3, rect.Height() + 3, SWP_SHOWWINDOW);
	ShowForm(SW_HIDE, SW_SHOW);

	m_ctlConnect.SetWindowText(TEXT("Прослушивать"));
}
void CSnopokLR_8Dlg::ShowForm(bool param, bool paramForList) {
	GetDlgItem(IDC_STATIC_CALCULATOR)->ShowWindow(param); GetDlgItem(IDC_RESULT)->ShowWindow(param); GetDlgItem(IDC_TASK)->ShowWindow(param);
	GetDlgItem(IDC_NUMBER_ZERO)->ShowWindow(param); GetDlgItem(IDC_NUMBER_ONE)->ShowWindow(param); GetDlgItem(IDC_NUMBER_TWO)->ShowWindow(param);
	GetDlgItem(IDC_NUMBER_THREE)->ShowWindow(param); GetDlgItem(IDC_NUMBER_FOUR)->ShowWindow(param); GetDlgItem(IDC_NUMBER_FIVE)->ShowWindow(param);
	GetDlgItem(IDC_NUMBER_SIX)->ShowWindow(param); GetDlgItem(IDC_NUMBER_SEVEN)->ShowWindow(param); GetDlgItem(IDC_NUMBER_EIGHT)->ShowWindow(param);
	GetDlgItem(IDC_NUMBER_NINE)->ShowWindow(param); GetDlgItem(IDC_OPERATION_PERCENT)->ShowWindow(param); GetDlgItem(IDC_OPERATION_DIVIDE)->ShowWindow(param);
	GetDlgItem(IDC_OPERATION_MULTIPLY)->ShowWindow(param); GetDlgItem(IDC_OPERATION_MINUSE)->ShowWindow(param); GetDlgItem(IDC_OPERATION_PLUS)->ShowWindow(param);
	GetDlgItem(IDC_OPERATION_EQUALS)->ShowWindow(param); GetDlgItem(IDC_OPERATION_L_BRACKETS)->ShowWindow(param); GetDlgItem(IDC_OPERATION_R_BRACKETS)->ShowWindow(param);
	GetDlgItem(IDC_OPERATION_FRACTION)->ShowWindow(param); GetDlgItem(IDC_OPERATION_CLEAR_ALL)->ShowWindow(param); GetDlgItem(IDC_OPERATION_RESET)->ShowWindow(param);
	GetDlgItem(IDC_LIST_TASK)->ShowWindow(paramForList); GetDlgItem(IDC_LIST_TASK)->EnableWindow(paramForList);
}
void CSnopokLR_8Dlg::AddToString(CString param) {
	CString str;
	m_strTask.GetWindowText(str);
	if (param == "%" || param == "/" || param == "*" || param == "-" || param == "+") 
		str += _T(" ") + param + _T(" ");
	else str += param;
	m_strTask.SetWindowText(str);
}

void CSnopokLR_8Dlg::OnBnClickedNumberZero() { AddToString(_T("0")); }
void CSnopokLR_8Dlg::OnBnClickedNumberOne() { AddToString(_T("1")); }
void CSnopokLR_8Dlg::OnBnClickedNumberTwo() { AddToString(_T("2")); }
void CSnopokLR_8Dlg::OnBnClickedNumberThree() { AddToString(_T("3")); }
void CSnopokLR_8Dlg::OnBnClickedNumberFour() { AddToString(_T("4")); }
void CSnopokLR_8Dlg::OnBnClickedNumberFive() { AddToString(_T("5")); }
void CSnopokLR_8Dlg::OnBnClickedNumberSix() { AddToString(_T("6")); }
void CSnopokLR_8Dlg::OnBnClickedNumberSeven() { AddToString(_T("7")); }
void CSnopokLR_8Dlg::OnBnClickedNumberEight() { AddToString(_T("8")); }
void CSnopokLR_8Dlg::OnBnClickedNumberNine() { AddToString(_T("9")); }

char* fromStringToChar(CString str) {
	int length = str.GetLength();
	char *mas = new char[length];
	for (int i = 0; i < length; i++)
		mas[i] = str[i];
	return mas;
}

void CSnopokLR_8Dlg::OnBnClickedOperationEquals() {
	if (m_iType == 0) {
		CString strTask;
		m_strTask.GetWindowTextW(strTask);
		char * sendTask = fromStringToChar(strTask);
		int q_send = m_sConnectSocket.Send(sendTask, strTask.GetLength(), 0);
		if (q_send == SOCKET_ERROR) return;
	}
	if (m_iType == 1) {
		char *sendResult = fromStringToChar(m_result);
		int q_send = m_sConnectSocket.Send(sendResult, m_result.GetLength(), 0);
		if (q_send == SOCKET_ERROR) return;
	}
}

void CSnopokLR_8Dlg::OnBnClickedOperationPercent() { AddToString(_T("%")); }
void CSnopokLR_8Dlg::OnBnClickedOperationDivide() { AddToString(_T("/")); }
void CSnopokLR_8Dlg::OnBnClickedOperationMultiply() { AddToString(_T("*")); }
void CSnopokLR_8Dlg::OnBnClickedOperationMinuse() { AddToString(_T("-")); }
void CSnopokLR_8Dlg::OnBnClickedOperationPlus() { AddToString(_T("+")); }
void CSnopokLR_8Dlg::OnBnClickedOperationFraction() { AddToString(_T(".")); }
void CSnopokLR_8Dlg::OnBnClickedOperationLBrackets() { AddToString(_T("(")); }
void CSnopokLR_8Dlg::OnBnClickedOperationRBrackets() { AddToString(_T(")")); }

void CSnopokLR_8Dlg::OnBnClickedOperationClearAll() {
	m_strTask.SetWindowTextW(_T(""));
	m_strResult.SetWindowTextW(_T(""));
}
void CSnopokLR_8Dlg::OnBnClickedOperationReset() {
	CString str;
	m_strTask.GetWindowTextW(str);
	char *mas = fromStringToChar(str);
	if (mas[str.GetLength() - 2] == ' ') mas[str.GetLength() - 2] = '\0';
	else mas[str.GetLength() - 1] = '\0';
	str = mas;
	m_strTask.SetWindowTextW(str);
	m_strResult.SetWindowTextW(_T(""));
}

void CSnopokLR_8Dlg::OnBnClickedBConnect() {
	UpdateData(TRUE);

	GetDlgItem(IDC_B_CONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_E_SERVER_NAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_E_SERVER_PORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_NAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_PORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_R_CLIENT)->EnableWindow(FALSE);
	GetDlgItem(IDC_R_SERVER)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_SOKET_TYPE)->EnableWindow(FALSE);

	if (m_iType == 0) {
		m_sConnectSocket.Create();
		m_sConnectSocket.Connect(m_strName, m_iPort);
	}
	else {
		m_sListenSocket.Create(m_iPort);
		m_sListenSocket.Listen();
	}
}

void CSnopokLR_8Dlg::OnAccept() {
	m_sListenSocket.Accept(m_sConnectSocket);
	GetDlgItem(IDC_OPERATION_EQUALS)->EnableWindow(TRUE);
}
void CSnopokLR_8Dlg::OnConnect() {
	GetDlgItem(IDC_OPERATION_EQUALS)->EnableWindow(TRUE);
	GetDlgItem(IDC_B_DISCONNECT)->EnableWindow(TRUE);
}
void CSnopokLR_8Dlg::OnReceive() {
	char *recievedResult = new char[1025];
	int q_recv = m_sConnectSocket.Receive(recievedResult, 1024);
	if (q_recv == SOCKET_ERROR) return;
	else {
		recievedResult[q_recv] = NULL;
		if (m_iType == 0) {
			CString str;
			str = recievedResult;
			m_strResult.SetWindowTextW(str);
			UpdateData(FALSE);
		}
		if (m_iType == 1) {
			CString expr(recievedResult, q_recv);
			TParser *parser = new TParser;
			parser->Compile(recievedResult);
			parser->Evaluate();
			m_result.Format(_T("%lf"), parser->GetResult());

			m_list.AddString(expr);
			OnBnClickedOperationEquals();
			UpdateData(FALSE);
		}
	}
}
void CSnopokLR_8Dlg::OnClose() {
	m_sConnectSocket.Close();
	GetDlgItem(IDC_OPERATION_EQUALS)->EnableWindow(FALSE);
	GetDlgItem(IDC_B_DISCONNECT)->EnableWindow(FALSE);
	if (m_iType == 0) {
		GetDlgItem(IDC_B_CONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_E_SERVER_NAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_E_SERVER_PORT)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_NAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_PORT)->EnableWindow(TRUE);
		GetDlgItem(IDC_R_CLIENT)->EnableWindow(TRUE);
		GetDlgItem(IDC_R_SERVER)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_SOKET_TYPE)->EnableWindow(TRUE);
		m_strTask.SetWindowTextW(_T(""));
		m_strResult.SetWindowTextW(_T(""));
		UpdateData(FALSE);
	}
}

void CSnopokLR_8Dlg::OnBnClickedBDisconnect() { OnClose(); }