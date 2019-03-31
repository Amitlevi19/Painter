// DlgDlg.h : header file
//

#if !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
#define AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg dialog
// added s
#include <vector>
#include "Figure.h"
#include "Sclass.cpp"
#include "Uclass.cpp"
#include "afxwin.h"
using namespace std;
// added e


class CDlgDlg : public CDialog
{

	enum FIGURES{RECTANGLE,ELLIPSE,LINE,TRIANGLE,SQUARE,CIRCLE};
	enum MODE{ SHAPE, PAINT, PICK,RESIZE };
	FIGURES futureFigKIND;
	MODE mode;

    COLORREF curColor;
	Figure* Temp;
	// added s

	CTypedPtrArray< CObArray, Figure*> figs; //all our shapes- save in a Array
	UNDOREDO <Figure*> undred;
	//!!6 e

	bool isPressed;
	CPoint startP;
	CPoint endP;
	// added e
	// Construction
public:
	CDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDlg)
	enum { IDD = IDD_DLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	//{{AFX_MSG(CDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//if the first page closed
	
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	BOOL isThin;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedRadio7();
	CButton BUttoN3;
	CButton save;
	CButton ok;
	CButton cancel;
	CButton load;
	CButton redo;
	CButton move;
	CButton paint;
	CButton cbrect;
	CButton cbelip;
	CButton cbsqar;
	CButton cbcirc;
	CButton cbtrai;
	CButton cbline;
	CButton resize;
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedRESIZE();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
