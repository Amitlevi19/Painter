#pragma once

#include "stdafx.h"
// StartingPage dialog

class StartingPage : public CDialogEx
{
	DECLARE_DYNAMIC(StartingPage)

public:
	StartingPage(CWnd* pParent = NULL);   // standard constructor
	virtual ~StartingPage();
	

// Dialog Data
	enum { IDD = IDD_STARTINGPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CBitmap BackGroundVar;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
//	afx_msg void OnBnClickedCancel();


};
