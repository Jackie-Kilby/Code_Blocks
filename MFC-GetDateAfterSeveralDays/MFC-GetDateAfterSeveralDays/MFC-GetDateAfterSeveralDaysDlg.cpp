/***************************************************

Project Name:   GetDateAfterSeveralDays
Developer: 		Jack Kilby
First Breed: 	2018-10-14
Update:			2018-10-14
Description:	Get the date after special days after a special day.

***************************************************/

// MFC-GetDateAfterSeveralDaysDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC-GetDateAfterSeveralDays.h"
#include "MFC-GetDateAfterSeveralDaysDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int iGetDaysOfMonth(int MonthNum, int YearNum);
BOOL bJudgeLeapYear(int Year);
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCGetDateAfterSeveralDaysDlg dialog

CMFCGetDateAfterSeveralDaysDlg::CMFCGetDateAfterSeveralDaysDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCGETDATEAFTERSEVERALDAYS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCGetDateAfterSeveralDaysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER, m_cDateTime);
}

BEGIN_MESSAGE_MAP(CMFCGetDateAfterSeveralDaysDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CMFCGetDateAfterSeveralDaysDlg::OnBnClickedButtonCalculate)
END_MESSAGE_MAP()

// CMFCGetDateAfterSeveralDaysDlg message handlers

BOOL CMFCGetDateAfterSeveralDaysDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//
	// Get CurrentTime


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCGetDateAfterSeveralDaysDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCGetDateAfterSeveralDaysDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCGetDateAfterSeveralDaysDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCGetDateAfterSeveralDaysDlg::OnBnClickedButtonCalculate()
{
	// TODO: Add your control notification handler code here
	// Get Year,Month,Day,AfterDays of the chosen time
	CTime ctCurrentTime;
	m_cDateTime.GetTime(ctCurrentTime);
	int iYear = ctCurrentTime.GetYear();
	int iMonth = ctCurrentTime.GetMonth();
	int iDate = ctCurrentTime.GetDay();
	int iAfterDays = 0;
	iAfterDays = GetDlgItemInt(IDC_EDIT_AFTERDAYS);
	// Calculate the date after special days
	int iDaysOfMonth = iGetDaysOfMonth(iMonth, iYear);
	int iRemainingDays = iDaysOfMonth - iDate;
	while (iRemainingDays < iAfterDays)
	{
		iMonth++;
		iAfterDays -= iRemainingDays;
		iDate = 1;
		if (iMonth > 12)
		{
			iYear++;
			iMonth = 1;
		}
		iRemainingDays = iGetDaysOfMonth(iMonth, iYear);
	}
	iDate += iAfterDays;

	CString strResultDate;
	strResultDate.Format(_T("%d年%d月%d日"), iYear, iMonth, iDate);
	SetDlgItemText(IDC_EDIT_RESULT, strResultDate);
}

/***************************************************

Function Name:  bJudgeLeapYear
Developer: 		Jack Kilby
First Breed: 	2018-06-06
Update:			2018-06-07
Description:	Judge whether a special year is a leap year.
Return:			TRUE  or 1		//means the year is a leap year
				False or 0		//means the year is not a leap year
Parametric:		int Year, the year num, used to decide if the year is a leap year.

***************************************************/
BOOL bJudgeLeapYear(int Year)
{
	if (0 != (Year % 4))
	{
		return FALSE;
	}
	else if (0 == (Year % 100))
	{
		if (0 == (Year % 400))
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return TRUE;
	}
}

/***************************************************

Function Name:  iGetDaysofMonth
Developer: 		Jack Kilby
First Breed: 	2018-06-06
Update:			2018-06-07
Description:	Get the num of days in a special month in a special year.
Return:			int iDaysOfMonth, The days of a special month in a special year.
Parametric:			int iMonth, spec in 1~12
				int iYear, the year num, used to decide if the February is in leap year.

***************************************************/
int iGetDaysOfMonth(int MonthNum, int YearNum)
{
	int iDaysOfMonth;

	switch (MonthNum)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		iDaysOfMonth = 31;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		iDaysOfMonth = 30;
		break;

	case 2:
		if (bJudgeLeapYear(YearNum))
		{
			iDaysOfMonth = 29;
		}
		else
		{
			iDaysOfMonth = 28;
		}

		break;

	default:
		iDaysOfMonth = 0;
		break;
	}

	if (iDaysOfMonth == 0)
	{
		printf("You have input an wrong month number.\n");
	}

	return iDaysOfMonth;
}
