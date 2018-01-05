
// draw33Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "draw33.h"
#include "draw33Dlg.h"
#include "afxdialogex.h"
#include "Rectangle.h"
#include "Ellipse.h"

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
	revers=0;
	indexarr=0;
	Ispress=false;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Cdraw33Dlg::~Cdraw33Dlg()
{
	/*for(int i=0;i<figs.GetSize();i++)
	{
		delete figs[figs.GetSize()-1-i];
	}*/
}



void Cdraw33Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, m_red);
	DDV_MinMaxInt(pDX, m_red, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER2, m_green);
	DDV_MinMaxInt(pDX, m_green, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER3, m_blue);
	DDV_MinMaxInt(pDX, m_blue, 0, 100);
}

BEGIN_MESSAGE_MAP(Cdraw33Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Cdraw33Dlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &Cdraw33Dlg::OnNMCustomdrawSlider3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &Cdraw33Dlg::OnNMCustomdrawSlider2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cdraw33Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cdraw33Dlg::OnBnClickedButton2)
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
	UpdateData(true);
		CPaintDC dc(this); // device context for painting
		
		 // b.CreateSolidBrush(RGB(2.5*R,2.5*G,2.5*B));
		dc.Rectangle(5,5,995,395);
		if(figs.GetCount()>0)
		{
			for(int i=0;i<figs.GetCount()-revers;i++)
			{
				CBrush b;
				b.CreateSolidBrush(RGB(2.5*figs[i]->R,2.5*figs[i]->G,2.5*figs[i]->B));
				dc.SelectObject(&b);
		
				figs[i]->Draw(&dc);
			}
		}

		UpdateData(false);
		
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
     CClientDC dc(this);
	end=point;
	Ispress=false;
	if(!isin())
	{
		CPen myPen1(PS_SOLID, 5, RGB(25,63,90));
		CPen *oldPen;
		oldPen=dc.SelectObject( &myPen1 );
		dc.SetROP2(R2_NOTXORPEN);  
		dc. MoveTo(start);
		dc.LineTo(start.x,end.y);
		dc.LineTo(end.x,end.y);
		dc.LineTo(end.x,start.y);
		dc.LineTo(start.x,start.y);
		end=start;
	}
	
	else
		{
		 CBrush b;
		 b.CreateSolidBrush(RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
		 dc.SelectObject(&b);
		//dc->Rectangle(x1,y1,x2,y2);
		 for(int i=0;i<revers;i++)
		 {
			 delete figs[ figs.GetSize()-1];
			 figs.RemoveAt(figs.GetSize()-1);
		
		 }
		  revers=0;
		 if(nFlags==MK_CONTROL)
		 {
			dc.Rectangle(start.x,start.y,end.x,end.y);


			figs.Add(new MYRectangle(start,end,m_red,m_green,m_blue));



			//indexarr++;

		 }
		 else
		 {
			 dc.Ellipse(start.x,start.y,end.x,end.y);


			 figs.Add(new MYEllipse(start,end,m_red,m_green,m_blue));


			//indexarr++;
		 }
	
			CPen myPen1(PS_SOLID, 5, RGB(25,63,90));
			CPen *oldPen;
			oldPen=dc.SelectObject( &myPen1 );
			dc.SetROP2(R2_NOTXORPEN);  
			dc. MoveTo(start);
			dc.LineTo(start.x,end.y);
			dc.LineTo(end.x,end.y);
			dc.LineTo(end.x,start.y);
			dc.LineTo(start.x,start.y);
	}

	CDialogEx::OnLButtonUp(nFlags, point);
	UpdateData(false);
}

bool Cdraw33Dlg::isin()
{
	if(start.x<5||start.x> 995||end.x<5||end.x> 995
		||	start.y<5||start.y> 395||end.y<5||end.y> 395)
		return false;
	else 
		return true;

	

}

void Cdraw33Dlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	UpdateData(true);
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	 CBrush b;
	 b.CreateSolidBrush(RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
	 dc.SelectObject(&b);
	 dc.Rectangle(5,400,55,450);
	 UpdateData(false);
	*pResult = 0;
}


void Cdraw33Dlg::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	UpdateData(true);
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	 CBrush b;
	 b.CreateSolidBrush(RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
	 dc.SelectObject(&b);
	 dc.Rectangle(5,400,55,450);
	 UpdateData(false);
	*pResult = 0;
}


void Cdraw33Dlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	
	UpdateData(true);
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	 CBrush b;
	 b.CreateSolidBrush(RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
	 dc.SelectObject(&b);
	 dc.Rectangle(5,400,55,450);
	 UpdateData(false);

	*pResult = 0;
}


void Cdraw33Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	if(revers<figs.GetCount())
	{
		revers++;
	Invalidate();
	}
	
}


void Cdraw33Dlg::OnBnClickedButton2()
{
	if(revers>0)
	{
		revers--;
		Invalidate();

	}
	// TODO: Add your control notification handler code here
}
