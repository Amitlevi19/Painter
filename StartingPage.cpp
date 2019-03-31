// StartingPage.cpp : implementation file
//

#include "StdAfx.h"
#include "Dlg.h"
#include "StartingPage.h"
#include "afxdialogex.h"


// StartingPage dialog

IMPLEMENT_DYNAMIC(StartingPage, CDialogEx)

StartingPage::StartingPage(CWnd* pParent /*=NULL*/)
	: CDialogEx(StartingPage::IDD, pParent)
{
}

StartingPage::~StartingPage()
{
}

void StartingPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StartingPage, CDialogEx)
	ON_WM_PAINT()
//	ON_BN_CLICKED(IDCANCEL, &StartingPage::OnBnClickedCancel)
/////////////////ON_BN_CLICKED(IDCANCEL, &StartingPage::OnBnClickedCancel) **cancel button has been removed
END_MESSAGE_MAP()


// StartingPage message handlers


BOOL StartingPage::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	BackGroundVar.LoadBitmap(IDB_BITMAP20);
	return TRUE;
}


void StartingPage::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CDC meme;
	meme.CreateCompatibleDC(&dc);
	meme.SelectObject(&BackGroundVar);
	dc.BitBlt(0,0,rect.Width(), rect.Height(), &meme, 0,0,SRCCOPY);
}


//void StartingPage::OnBnClickedCancel()
//{
//	// TODO: Add your control notification handler code here
//	CDialogEx::OnCancel();
//}


