
// FTech_TimeExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_TimeEx.h"
#include "FTech_TimeExDlg.h"
#include "afxdialogex.h"
#include "TimeEx.h"

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
	ON_BN_CLICKED(IDC_BTN_INFO, &CFTech_TimeExDlg::OnBnClickedBtnInfo)
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

void CFTech_TimeExDlg::OnBnClickedBtnInfo()
{
	CString time = CTimeEx::GetCurrentTimeInfo(_T("%02d:%02d:%02d"));
	CString time2 = CTimeEx::GetCurrentTimeInfo(_T("%02d:%02d:%02d:%02d"),true);
	CString date = CTimeEx::GetCurrentDateInfo(_T("%02d-%02d-%02d"));
	CString date2 = CTimeEx::GetCurrentDateTimeInfo(_T("%02d-%02d-%02d, %02d:%02d:%02d:%02d"),true);
}
