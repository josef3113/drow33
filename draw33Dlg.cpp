
// draw33Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "draw33.h"
#include "draw33Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cdraw33Dlg dialog




Cdraw33Dlg::Cdraw33Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cdraw33Dlg::IDD, pParent)
	, m_red(0)
	, m_green(0)
	, m_blue(0)
{
	Ispress=false;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdraw33Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, m_red);
	DDV_MinMaxInt(pDX, m_red, 1, 100);
	DDX_Slider(pDX, IDC_SLIDER2, m_green);
	DDV_MinMaxInt(pDX, m_green, 1, 100);
	DDX_Slider(pDX, IDC_SLIDER3, m_blue);
	DDV_MinMaxInt(pDX, m_blue, 1, 100);
}

BEGIN_MESSAGE_MAP(Cdraw33Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// Cdraw33Dlg message handlers

BOOL Cdraw33Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cdraw33Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cdraw33Dlg::OnPaint()
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
HCURSOR Cdraw33Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cdraw33Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
		  Ispress=true;
		  start=point;
		  end=point;
	CDialogEx::OnLButtonDown(nFlags, point);
}



void Cdraw33Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	 if(Ispress)
	 {
		 CClientDC dc(this);
		CPen myPen1(PS_SOLID, 5, RGB(25,63,90));
		CPen *oldPen;
		oldPen=dc.SelectObject( &myPen1 ); 
		dc.SetROP2(R2_NOTXORPEN);  
		dc. MoveTo(start);
		dc.LineTo(start.x,end.y);
		dc.LineTo(end.x,end.y);
		dc.LineTo(end.x,start.y);
		dc.LineTo(start.x,start.y);
		end=point;
  	    dc. MoveTo(start);
		 dc.LineTo(start.x,end.y);
		dc.LineTo(end.x,end.y);
		dc.LineTo(end.x,start.y);
		dc.LineTo(start.x,start.y);

		dc.SelectObject( oldPen );
	 }
	CDialogEx::OnMouseMove(nFlags, point);
}


void Cdraw33Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	UpdateData(true);
	// TODO: Add your message handler code here and/or call default
	Ispress=false;
	end=point;
	 CClientDC dc(this);
	 CBrush b;
	 b.CreateSolidBrush(RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
	 dc.SelectObject(&b);
	//dc->Rectangle(x1,y1,x2,y2);
	 if(nFlags==MK_CONTROL)
	 dc.Rectangle(start.x,start.y,end.x,end.y);
	 else
		 dc.Ellipse(start.x,start.y,end.x,end.y);

	
		CPen myPen1(PS_SOLID, 5, RGB(25,63,90));
		CPen *oldPen;
		oldPen=dc.SelectObject( &myPen1 );
	    dc.SetROP2(R2_NOTXORPEN);  
		dc. MoveTo(start);
		dc.LineTo(start.x,end.y);
		dc.LineTo(end.x,end.y);
		dc.LineTo(end.x,start.y);
		dc.LineTo(start.x,start.y);

	CDialogEx::OnLButtonUp(nFlags, point);
	UpdateData(false);
}
