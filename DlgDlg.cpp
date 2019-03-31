// DlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dlg.h"
#include "DlgDlg.h"
#include "StartingPage.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg dialog

CDlgDlg::CDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDlg::IDD, pParent)
	, isThin(FALSE)
{
	//!!2
	futureFigKIND=RECTANGLE;
	isPressed=false;

	//!!8
	curColor=RGB(0,0,0);


	//{{AFX_DATA_INIT(CDlgDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_BUTTON3, BUttoN3);
	DDX_Control(pDX, IDC_BUTTON1, save);
	DDX_Control(pDX, IDCANCEL, cancel);
	DDX_Control(pDX, IDC_BUTTON2, load);
	DDX_Control(pDX, IDC_BUTTON4, redo);
	DDX_Control(pDX, IDC_RADIO1, cbrect);
	DDX_Control(pDX, IDC_RADIO2, cbelip);
	DDX_Control(pDX, IDC_RADIO5, cbsqar);
	DDX_Control(pDX, IDC_RADIO6, cbcirc);
	DDX_Control(pDX, IDC_RADIO3, cbtrai);
	DDX_Control(pDX, IDC_RADIO4, cbline);
	DDX_Control(pDX, IDC_RADIO8, move);
	DDX_Control(pDX, IDC_RADIO9, paint);
	//DDX_Control(pDX, IDC_RESIZE, resize);
}

BEGIN_MESSAGE_MAP(CDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDlgDlg::OnBnClickedRadio3)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_RADIO4, &CDlgDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CDlgDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CDlgDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_RADIO8, &CDlgDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlgDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_RADIO9, &CDlgDlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDCANCEL, &CDlgDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_RESIZE, &CDlgDlg::OnBnClickedRESIZE)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg message handlers
static int ToChange = 0;
BOOL CDlgDlg::OnInitDialog()
{
	if (ToChange == 0)
	{
		this->ShowWindow(SW_HIDE);
		StartingPage ObjectToOpen;
		ObjectToOpen.DoModal();
		this->ShowWindow(SW_SHOW);
		ToChange++;
	}
	CDialog::OnInitDialog();
	BUttoN3.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP9)));
	save.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP5)));
	cancel.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP7)));
	load.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP8)));
	redo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP10)));
	cbrect.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP11)));
	cbelip.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP12)));
	cbsqar.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP13)));
	cbcirc.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP14)));
	cbtrai.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP17)));
	cbline.SetBitmap(LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP16)));
	move.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_RADIO8)));
	paint.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_RADIO9)));
	//////
	//resize.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_RADIO8)));
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDC_CURSOR8)));


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	//!!2
	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	mode = SHAPE;
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDlgDlg::OnPaint() 
{
	CRect rect;
	GetClientRect (&rect);
	CFont font;
	font.CreatePointFont (500, _T ("Comic Sans MS"));

	//!!8 b
	CPaintDC dc (this);
	//!!8 e

	CPen myPen1(PS_SOLID, 1, RGB(0,0,0));
	CPen *oldPen;
	oldPen=dc.SelectObject( &myPen1 ); 
	dc.SetROP2(R2_NOTXORPEN);  
	CFont *oldFont= dc.SelectObject (&font);
	dc.SetBkMode (TRANSPARENT);

	dc.SelectObject (oldFont);
	//!!2
	//1st
	for(int i=0;i<figs.GetSize();i++)
	{
		figs[i]->Draw(&dc);
		undred.AddNew(figs[i]);
	}
	//if creation
	if(isPressed)
	{
		dc.MoveTo(startP.x,startP.y);
		dc.LineTo(startP.x,endP.y);
		dc.LineTo(endP.x,endP.y);
		dc.LineTo(endP.x,startP.y);
		dc.LineTo(startP.x,startP.y);
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
int inshape = 0;
int l=1;
void CDlgDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	POINT pos;
	GetCursorPos(&pos);
	int i = 0;
	inshape = 0;
	if (mode != SHAPE && figs.GetSize() >= 0)
		for (i = figs.GetSize() - 1; i >= 0; i--)
			if (!((point.x>figs[i]->x1 && point.x>figs[i]->x2) || (point.x<figs[i]->x1 && point.x<figs[i]->x2) || (point.y>figs[i]->y1 && point.y>figs[i]->y2) || (point.y<figs[i]->y1 && point.y<figs[i]->y2)))
			{
				inshape = 1;
				break;
			}
			switch (mode)
			{
			case SHAPE:
				{
					inshape = 0;
					endP = startP = point;
					CDialog::OnLButtonDown(nFlags, point);
				}
				break;
			case PAINT:
				{	
					if (inshape == 1)
						figs[i]->SetColor(curColor);
				}
				break;
			case PICK:
				{	
					if (inshape == 1)
					{
						l = i;
						endP = startP = point;
					}
				}
				break;
			case RESIZE:
				{
					if(inshape==1)
					{
						l=i;
						endP = startP = point;
						CDialog::OnLButtonDown(nFlags, point);
					}
				}break;
			default:
				{
					mode = SHAPE;
					endP = startP = point;
					CDialog::OnMouseMove(nFlags, point);
				}
				break;
			}
			isPressed = true;
}

void CDlgDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		endP = point;
		isPressed = false;
		switch (mode)
		{
		case PICK:
			{
				if (inshape == 1)
				{
					int deltax, deltay, i;
					deltax = endP.x - startP.x;
					deltay = endP.y - startP.y;
					figs[l]->x1 += deltax;
					figs[l]->x2 += deltax;
					figs[l]->y1 += deltay;
					figs[l]->y2 += deltay;
					Figure* temp = figs[l];
					for (i = l; i < figs.GetSize() - 1; i++)
						figs[i] = figs[i + 1];
					figs[i] = temp;
				}break;
			}
			
		case SHAPE:
			{

				switch (futureFigKIND)
				{
				case RECTANGLE:
					//!!6 instead of .push_back
					figs.Add(new RectangleM(startP.x, startP.y, endP.x, endP.y, curColor));
					break;
				case ELLIPSE:
					//!!6
					figs.Add(new EllipseM(startP.x, startP.y, endP.x, endP.y, curColor));
					break;
				case LINE:
					//!!6
					figs.Add(new Line(startP.x, startP.y, endP.x, endP.y, curColor));
					break;
				case TRIANGLE:
					//!!6
					figs.Add(new Triangle(startP.x, startP.y, endP.x, endP.y, curColor));
					break;
				case SQUARE:
					//!!6
					figs.Add(new Square(startP.x, startP.y, endP.x, endP.y, curColor));
					break;
				case CIRCLE:
					//!!6
					figs.Add(new Circle(startP.x, startP.y, endP.x, endP.y, curColor));
					break;
				}
			}
		//case RESIZE:
		//	{
		//		//int deltax, deltay, i;
		//		//	deltax = endP.x - startP.x;
		//		//	deltay = endP.y - startP.y;
		//		//	figs[l]->x1 += deltax;
		//		//	figs[l]->x2 += deltax;
		//		//	figs[l]->y1 += deltay;
		//		//	figs[l]->y2 += deltay;
		//		//	Figure* temp = figs[l];
		//		//	for (i = l; i < figs.GetSize() - 1; i++)
		//		//		figs[i] = figs[i + 1];
		//		//	figs[i] = temp;
		//		//break;
		//	}

		}
	}
	UpdateWindow();
	Invalidate();
	CDialog::OnLButtonUp(nFlags, point);
	UpdateWindow();
}

void CDlgDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(isPressed)
	{
		CClientDC dc(this);
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(RGB(255,255,255));
		oldBrush=dc.SelectObject( &myBrush );

		//!!8
		//!!!        //!!!		                     
		CPen myPen1(PS_SOLID, isThin?1:3, curColor);
		CPen *oldPen;
		oldPen=dc.SelectObject( &myPen1 ); 
		dc.SetROP2(R2_NOTXORPEN);  


		////!!!!
		switch (mode)
		{
		case PICK:
			{
				if (inshape == 1)
				{
					CBrush myBrush3;
					myBrush3.CreateSolidBrush(figs[l]->GetColor());
					oldBrush = dc.SelectObject(&myBrush3);
					UpdateWindow();
					figs[l]->MouseMove(startP, endP, &dc);
					endP = point;
				}
				break;
			}
		case SHAPE:
			{
				dc.SetROP2(R2_NOTXORPEN);
				switch (futureFigKIND)
				{
				case RECTANGLE:
					dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
					endP = point;
					dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
					UpdateWindow();
					break;
				case ELLIPSE:
					dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
					endP = point;
					dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
					break;
				case TRIANGLE:
					{
						CPoint T[3];
						T[0].x = startP.x;
						T[0].y = endP.y;
						T[1].x = endP.x;
						T[1].y = endP.y;
						T[2].x = (startP.x+endP.x)/2;
						T[2].y = startP.y;
						dc.Polygon(T, 3);
						endP = point;
						T[0].x = startP.x;
						T[0].y = endP.y;
						T[1].x = endP.x;
						T[1].y = endP.y;
						T[2].x = (startP.x + endP.x) / 2;
						T[2].y = startP.y;
						UpdateWindow();
						dc.Polygon(T, 3);
					}
					break;
				case LINE:
					dc.MoveTo(startP);
					dc.LineTo(endP.x, endP.y);
					endP = point;
					dc.MoveTo(startP);
					dc.LineTo(endP.x, endP.y);
					break;
				case SQUARE:
					dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
					endP = point;
					if (startP.x<endP.x)
						endP.x = startP.x + abs(startP.y - endP.y);
					else
						endP.x = startP.x - abs(startP.y - endP.y);
					dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
				case CIRCLE:
					dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
					endP = point;
					if (startP.x<endP.x)
						endP.x = startP.x + abs(startP.y - endP.y);
					else
						endP.x = startP.x - abs(startP.y - endP.y);
					dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
					break;
				}
			}
			case RESIZE:
				{
				if (inshape == 1)
				{
					figs[l]->x2 = point.x;
					figs[l]->y2 = point.y;
					Invalidate();
					//figs[l]->MouseMove(startP, point, &dc);
					endP = point;
					
				}
				break;
				}
			
		}

		dc.SelectObject(oldPen);
		dc.SetROP2(R2_COPYPEN);
		dc.SelectObject(oldBrush);
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CDlgDlg::OnBnClickedButton1()//SAVE
{
	// TODO: Add your control notification handler code here
	CFile file(_T("File.$$"), CFile::modeWrite);
	CArchive ar (&file, CArchive::store);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
}

void CDlgDlg::OnBnClickedButton2()//LOAD
{
	// TODO: Add your control notification handler code here
	CFile file(_T("File.$$"), CFile::modeRead);
	CArchive ar (&file, CArchive::load);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
	Invalidate();
}
void CDlgDlg::OnBnClickedRadio1() //rectangle
{
	futureFigKIND=RECTANGLE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR8)));
}

void CDlgDlg::OnBnClickedRadio2() //elipse
{
	futureFigKIND=ELLIPSE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR2)));
}

void CDlgDlg::OnBnClickedRadio3() //triangle
{
	futureFigKIND=TRIANGLE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR10)));
}
void CDlgDlg::OnBnClickedRadio4() //line
{
	futureFigKIND=LINE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR4)));
}
void CDlgDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//!!8 b
	CClientDC dc(this);
	curColor=dc.GetPixel(point);
	//!!8 e

	CDialog::OnRButtonDown(nFlags, point);
}

void CDlgDlg::OnBnClickedRadio5() //square
{
	futureFigKIND=SQUARE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR9)));
}


void CDlgDlg::OnBnClickedRadio6() //circle
{
	futureFigKIND=CIRCLE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR1)));
}
void CDlgDlg::OnBnClickedButton3()//UNDO-delete
{
	if(!figs.GetSize()<1)
	{
		undred.Delete();
		figs.SetSize(figs.GetSize()-1);
		Invalidate();
	}
}

void CDlgDlg::OnBnClickedButton4()//REDO
{
	// TODO: Add your control notification handler code here
	Figure* num;
	if (!undred.isEmpty())
	{
		undred.Top();
		num = undred.UNDO.Pop();
		undred.AddNew(num);
		figs.InsertAt(figs.GetSize(),num,1);
		Invalidate();
	}
}


void CDlgDlg::OnBnClickedRadio8()
{
	mode = PICK;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR5)));
}


void CDlgDlg::OnBnClickedButton5() //move
{
	mode = PICK;
}


void CDlgDlg::OnBnClickedRadio9() //paint
{
	mode = PAINT;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR6)));
}


void CDlgDlg::OnBnClickedCancel() //cancel
{
	CDialog::OnCancel();
}


void CDlgDlg::OnBnClickedRESIZE() //resize
{
	mode=RESIZE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR6)));
}
