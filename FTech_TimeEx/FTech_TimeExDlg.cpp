
// FTech_TimeExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_TimeEx.h"
#include "FTech_TimeExDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTech_TimeExDlg dialog




CFTech_TimeExDlg::CFTech_TimeExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFTech_TimeExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTech_TimeExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFTech_TimeExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_STOPWATCH, &CFTech_TimeExDlg::OnBnClickedBtnStopwatch)
	ON_BN_CLICKED(IDC_BTN_LAP, &CFTech_TimeExDlg::OnBnClickedBtnLap)
END_MESSAGE_MAP()


// CFTech_TimeExDlg message handlers

BOOL CFTech_TimeExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFTech_TimeExDlg::OnPaint()
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
HCURSOR CFTech_TimeExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFTech_TimeExDlg::OnBnClickedBtnStopwatch()
{
	CString caption=L"";
	GetDlgItemText(IDC_BTN_STOPWATCH, caption);

	if (caption == L"Start")
	{
		CListBox* pLb = (CListBox*)GetDlgItem(IDC_LIST1);	
		pLb->ResetContent();

		m_SW.Start();
		SetDlgItemText(IDC_BTN_STOPWATCH, L"Stop");

		GetDlgItem(IDC_BTN_LAP)->EnableWindow(TRUE);
	}
	else if (caption == L"Stop")
	{
		m_SW.Stop();

		double t = m_SW.GetTimeMs();
		CString tmp=L"";
		tmp.Format(L"%.3f ms",t);
		SetDlgItemText(IDC_LB_TIME, tmp);

		SetDlgItemText(IDC_BTN_STOPWATCH, L"Start");

		GetDlgItem(IDC_BTN_LAP)->EnableWindow(FALSE);
	}
}


void CFTech_TimeExDlg::OnBnClickedBtnLap()
{
	m_SW.Stop();
	double t = m_SW.GetTimeMs();
	CString tmp=L"";
	tmp.Format(L"%.3f ms",t);

	CListBox* pLb = (CListBox*)GetDlgItem(IDC_LIST1);
	pLb->AddString(tmp);
}
