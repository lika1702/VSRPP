
// SnopokIDZ_2.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "SnopokIDZ_2.h"
#include "MainFrm.h"

#include "SnopokIDZ_2Set.h"
#include "SnopokIDZ_2Doc.h"
#include "SnopokIDZ_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSnopokIDZ_2App

BEGIN_MESSAGE_MAP(CSnopokIDZ_2App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CSnopokIDZ_2App::OnAppAbout)
	// ����������� ������� ��������� ������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// �������� CSnopokIDZ_2App

CSnopokIDZ_2App::CSnopokIDZ_2App()
{
	m_bHiColorIcons = TRUE;

	// ��������� ���������� ������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���� ���������� ��������� � ���������� ����� Common Language Runtime (/clr):
	//     1) ���� �������������� �������� ��������� ��� ���������� ��������� ������ ���������� ������������.
	//   2) � ����� ������� ��� ������ ���������� �������� ������ �� System.Windows.Forms.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: �������� ���� ������ �������������� ���������� ������� ����������� ��������������; �������������
	// ������ ��� ������: �����������.�����������.����������.���������������
	SetAppID(_T("SnopokIDZ_2.AppID.NoVersion"));

	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}

// ������������ ������ CSnopokIDZ_2App

CSnopokIDZ_2App theApp;


// ������������� CSnopokIDZ_2App

BOOL CSnopokIDZ_2App::InitInstance()
{
	// InitCommonControlsEx() ��������� ��� Windows XP, ���� ��������
	// ���������� ���������� ComCtl32.dll ������ 6 ��� ����� ������� ������ ��� ���������
	// ������ �����������.  � ��������� ������ ����� ��������� ���� ��� �������� ������ ����.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �������� ���� �������� ��� ��������� ���� ����� ������� ����������, ������� ���������� ������������
	// � ����� ����������.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// ������������� ��������� OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ��� ������������� �������� ���������� RichEdit ��������� ����� AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ����������� �������������
	// ���� ��� ����������� �� ������������ � ���������� ��������� ������
	// ��������� ������������ �����, ���������� ������� �� ����������
	// ���������� ��������� �������������, ������� �� ���������
	// �������� ������ �������, � ������� �������� ���������
	// TODO: ������� �������� ��� ������ �� ���-������ ����������,
	// �������� �� �������� �����������
	SetRegistryKey(_T("��������� ����������, ��������� � ������� ������� ����������"));
	LoadStdProfileSettings(4);  // ��������� ����������� ��������� INI-����� (������� MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ��������������� ������� ���������� ����������.  ������� ����������
	//  ��������� � ���� ���������� ����� �����������, ������ ����� � ���������������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CSnopokIDZ_2Doc),
		RUNTIME_CLASS(CMainFrame),       // �������� ���� ����� SDI
		RUNTIME_CLASS(CSnopokIDZ_2View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// ��������� ������������� ����������� �������� � ������� �������� ����
	CMFCToolBar::m_bExtCharTranslation = TRUE;

	// �������������� ������ ��������� ������ �� ����������� ������� ��������, DDE, �������� ������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ������� ���������������, ��������� � ��������� ������.  �������� FALSE ����� ����������, ����
	// ���������� ���� �������� � ���������� /RegServer, /Register, /Unregserver ��� /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// ���� � ������ ���� ���� ���� ����������������, ������� ���������� � �������� ���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CSnopokIDZ_2App::ExitInstance()
{
	//TODO: ����������� �������������� �������, ������� ����� ���� ���������
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// ����������� ��������� CSnopokIDZ_2App


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
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

// ������� ���������� ��� ������� �������
void CSnopokIDZ_2App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CSnopokIDZ_2App ��������� ������� �������� � ����������

void CSnopokIDZ_2App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CSnopokIDZ_2App::LoadCustomState()
{
}

void CSnopokIDZ_2App::SaveCustomState()
{
}

// ����������� ��������� CSnopokIDZ_2App



