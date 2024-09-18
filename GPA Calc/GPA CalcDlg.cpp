
// GPA CalcDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculations.h"
#include "GPA Calc.h"
#include "GPA CalcDlg.h"
#include "afxdialogex.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CGPACalcDlg dialog



CGPACalcDlg::CGPACalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GPA_CALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGPACalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGPACalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CGPACalcDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT3, &CGPACalcDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT5, &CGPACalcDlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT7, &CGPACalcDlg::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, &CGPACalcDlg::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT9, &CGPACalcDlg::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT10, &CGPACalcDlg::OnEnChangeEdit10)
	ON_EN_CHANGE(IDC_EDIT11, &CGPACalcDlg::OnEnChangeEdit11)
	ON_EN_CHANGE(IDC_EDIT12, &CGPACalcDlg::OnEnChangeEdit12)
	ON_EN_CHANGE(IDC_EDIT13, &CGPACalcDlg::OnEnChangeEdit13)
	ON_EN_CHANGE(IDC_EDIT14, &CGPACalcDlg::OnEnChangeEdit14)
	ON_EN_CHANGE(IDC_EDIT15, &CGPACalcDlg::OnEnChangeEdit15)
	ON_EN_CHANGE(IDC_EDIT16, &CGPACalcDlg::OnEnChangeEdit16)
	ON_EN_CHANGE(IDC_EDIT17, &CGPACalcDlg::OnEnChangeEdit17)
	ON_EN_CHANGE(IDC_EDIT18, &CGPACalcDlg::OnEnChangeEdit18)
	ON_EN_CHANGE(IDC_EDIT6, &CGPACalcDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDOK, &CGPACalcDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CGPACalcDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT4, &CGPACalcDlg::OnEnChangeEdit4)
END_MESSAGE_MAP()


// CGPACalcDlg message handlers

BOOL CGPACalcDlg::OnInitDialog()
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
	CComboBox* pCombo1 = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	pCombo1->InsertString(0, _T("1"));
	pCombo1->InsertString(1, _T("2"));
	pCombo1->InsertString(2, _T("3"));
	pCombo1->InsertString(3, _T("4"));
	pCombo1->InsertString(4, _T("5"));
	pCombo1->SetCurSel(-1); // or -1 for unselected


	CStatic* pPicture1 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC2));
	pPicture1->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb1 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture1->SetBitmap(hb1);

	// Picture control setup
	CStatic* pPicture2 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC3));
	pPicture2->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb2 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture2->SetBitmap(hb2);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGPACalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGPACalcDlg::OnPaint()
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
HCURSOR CGPACalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGPACalcDlg::OnCbnSelchangeCombo1()
{
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3)); //courses #1-5
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5));
	CEdit* pEdit6 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT6));
	CEdit* pEdit7 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT7));
	CEdit* pEdit8 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT8));
	CEdit* pEdit9 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT9)); //credits #1-5
	CEdit* pEdit10 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT10));
	CEdit* pEdit11 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT11));
	CEdit* pEdit12 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT12));
	CEdit* pEdit13 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT13));
	CEdit* pEdit14 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT14)); //grades #1-5
	CEdit* pEdit15 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT15));
	CEdit* pEdit16 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT16));
	CEdit* pEdit17 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT17));
	CEdit* pEdit18 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT18));
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int n = pCombo->GetCurSel();

	switch (n) {
	case 0: //1 course taken
		pEdit3->ShowWindow(SW_SHOW);
		pEdit5->ShowWindow(SW_HIDE);
		pEdit6->ShowWindow(SW_HIDE);
		pEdit7->ShowWindow(SW_HIDE);
		pEdit8->ShowWindow(SW_HIDE);
		pEdit9->ShowWindow(SW_SHOW);
		pEdit10->ShowWindow(SW_HIDE);
		pEdit11->ShowWindow(SW_HIDE);
		pEdit12->ShowWindow(SW_HIDE);
		pEdit13->ShowWindow(SW_HIDE);
		pEdit14->ShowWindow(SW_SHOW);
		pEdit15->ShowWindow(SW_HIDE);
		pEdit16->ShowWindow(SW_HIDE);
		pEdit17->ShowWindow(SW_HIDE);
		pEdit18->ShowWindow(SW_HIDE);
		break;
	case 1: //2 courses taken
		pEdit3->ShowWindow(SW_SHOW);
		pEdit5->ShowWindow(SW_SHOW);
		pEdit6->ShowWindow(SW_HIDE);
		pEdit7->ShowWindow(SW_HIDE);
		pEdit8->ShowWindow(SW_HIDE);
		pEdit9->ShowWindow(SW_SHOW);
		pEdit10->ShowWindow(SW_SHOW);
		pEdit11->ShowWindow(SW_HIDE);
		pEdit12->ShowWindow(SW_HIDE);
		pEdit13->ShowWindow(SW_HIDE);
		pEdit14->ShowWindow(SW_SHOW);
		pEdit15->ShowWindow(SW_SHOW);
		pEdit16->ShowWindow(SW_HIDE);
		pEdit17->ShowWindow(SW_HIDE);
		pEdit18->ShowWindow(SW_HIDE);
		break;
	case 2: //3 courses taken
		pEdit3->ShowWindow(SW_SHOW);
		pEdit5->ShowWindow(SW_SHOW);
		pEdit6->ShowWindow(SW_SHOW);
		pEdit7->ShowWindow(SW_HIDE);
		pEdit8->ShowWindow(SW_HIDE);
		pEdit9->ShowWindow(SW_SHOW);
		pEdit10->ShowWindow(SW_SHOW);
		pEdit11->ShowWindow(SW_SHOW);
		pEdit12->ShowWindow(SW_HIDE);
		pEdit13->ShowWindow(SW_HIDE);
		pEdit14->ShowWindow(SW_SHOW);
		pEdit15->ShowWindow(SW_SHOW);
		pEdit16->ShowWindow(SW_SHOW);
		pEdit17->ShowWindow(SW_HIDE);
		pEdit18->ShowWindow(SW_HIDE);
		break;
	case 3: //4 courses taken
		pEdit3->ShowWindow(SW_SHOW);
		pEdit5->ShowWindow(SW_SHOW);
		pEdit6->ShowWindow(SW_SHOW);
		pEdit7->ShowWindow(SW_SHOW);
		pEdit8->ShowWindow(SW_HIDE);
		pEdit9->ShowWindow(SW_SHOW);
		pEdit10->ShowWindow(SW_SHOW);
		pEdit11->ShowWindow(SW_SHOW);
		pEdit12->ShowWindow(SW_SHOW);
		pEdit13->ShowWindow(SW_HIDE);
		pEdit14->ShowWindow(SW_SHOW);
		pEdit15->ShowWindow(SW_SHOW);
		pEdit16->ShowWindow(SW_SHOW);
		pEdit17->ShowWindow(SW_SHOW);
		pEdit18->ShowWindow(SW_HIDE);
		break;
	case 4: //5 courses taken
		pEdit3->ShowWindow(SW_SHOW);
		pEdit5->ShowWindow(SW_SHOW);
		pEdit6->ShowWindow(SW_SHOW);
		pEdit7->ShowWindow(SW_SHOW);
		pEdit8->ShowWindow(SW_SHOW);
		pEdit9->ShowWindow(SW_SHOW);
		pEdit10->ShowWindow(SW_SHOW);
		pEdit11->ShowWindow(SW_SHOW);
		pEdit12->ShowWindow(SW_SHOW);
		pEdit13->ShowWindow(SW_SHOW);
		pEdit14->ShowWindow(SW_SHOW);
		pEdit15->ShowWindow(SW_SHOW);
		pEdit16->ShowWindow(SW_SHOW);
		pEdit17->ShowWindow(SW_SHOW);
		pEdit18->ShowWindow(SW_SHOW);
		break;
	}
}


void CGPACalcDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit9()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit10()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit11()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit14()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit15()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit16()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit17()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit18()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnEnChangeEdit6()
{
	
}

void CGPACalcDlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CGPACalcDlg::OnBnClickedOk() //calcs
{
	// get values from input, 3, 5, 6, 7, 8 are course names so they're not included here, 9-13 are credit amounts, and 14-18 are grades
	Calculations calculator; //instance of class for function op
	CString mInput1;
	CEdit* pInput1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT9));
	pInput1->GetWindowText(mInput1);

	CString mInput2;
	CEdit* pInput2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT10));
	pInput2->GetWindowText(mInput2);

	CString mInput3;
	CEdit* pInput3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT11));
	pInput3->GetWindowText(mInput3);

	CString mInput4;
	CEdit* pInput4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT12));
	pInput4->GetWindowText(mInput4);

	CString mInput5;
	CEdit* pInput5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT13));
	pInput5->GetWindowText(mInput5);

	CString mInput6;
	CEdit* pInput6 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT14));
	pInput6->GetWindowText(mInput6);

	CString mInput7;
	CEdit* pInput7 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT15));
	pInput7->GetWindowText(mInput7);

	CString mInput8;
	CEdit* pInput8 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT16));
	pInput8->GetWindowText(mInput8);

	CString mInput9;
	CEdit* pInput9 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT17));
	pInput9->GetWindowText(mInput9);

	CString mInput10;
	CEdit* pInput10 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT18));
	pInput10->GetWindowText(mInput10);

	//credit 1-5 created here, takes string converted to int from mInput 1-5
	int credit1 = _wtoi(mInput1);
	int credit2 = _wtoi(mInput2);
	int credit3 = _wtoi(mInput3);
	int credit4 = _wtoi(mInput4);
	int credit5 = _wtoi(mInput5);

	//new variable is created, grade1-5 and takes the string converted to a double from mInput 6-10
	double grade1 = _wtof(mInput6);
	double grade2 = _wtof(mInput7);
	double grade3 = _wtof(mInput8);
	double grade4 = _wtof(mInput9);
	double grade5 = _wtof(mInput10);

	double gradePoint1 = calculator.numberToGradePoints(grade1);
	double gradePoint2 = calculator.numberToGradePoints(grade2);
	double gradePoint3 = calculator.numberToGradePoints(grade3);
	double gradePoint4 = calculator.numberToGradePoints(grade4);
	double gradePoint5 = calculator.numberToGradePoints(grade5);

	double totalCredits = credit1 + credit2 + credit3 + credit4 + credit5;
	double totalGradePoints = (gradePoint1 * credit1) + (gradePoint2 * credit2) + (gradePoint3 * credit3) + (gradePoint4 * credit4) + (gradePoint5 * credit5);
	


	double GPA = totalGradePoints / totalCredits;
	
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(2) << GPA; //sets output to two decimal places
	std::string gpaString = stream.str();
	
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	pEdit4->SetWindowText(CString(gpaString.c_str()));
}


void CGPACalcDlg::OnBnClickedCancel() // standard behavior
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


