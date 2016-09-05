
// FTech_TimeExDlg.h : header file
//

#pragma once
#include "TimeEx.h"

// CFTech_TimeExDlg dialog
class CFTech_TimeExDlg : public CDialogEx
{
// Construction
public:
	CFTech_TimeExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FTECH_TIMEEX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

public :
	CTimeEx m_SW;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnStopwatch();
	afx_msg void OnBnClickedBtnLap();
};