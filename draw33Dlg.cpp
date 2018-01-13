
// draw33Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "draw33.h"
#include "draw33Dlg.h"
#include "afxdialogex.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include <MMSystem.h>

#define X_TOPLEFT	5		  //(5,5,995,395);
#define Y_TOPLEFT  5
#define X_DOWNRIGHT	    995
#define Y_DOWNRIGHT		395




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };;

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


//	PlaySound(Text("name.wav"),NULL,SND_ASNC|SND_FILENAME);

Cdraw33Dlg::Cdraw33Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cdraw33Dlg::IDD, pParent)
	, m_red(0)
	, m_green(0)
	, m_blue(0)
	, m_sizepen(0)
	, r_sizepen(0)
{
	// my code
	reversShap=0;
	typeShape=1;
	//indexarr=0;
	reversLine=0;
	Ispress=false;
	ToMove=false;
	Line=false;
	temp=NULL;

	//

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Cdraw33Dlg::~Cdraw33Dlg()
{
	//my code
	int size=figs.GetSize();
	for(int i=0;i<size;i++)
	{
		delete figs[figs.GetSize()-1];
		figs.RemoveAt(figs.GetSize()-1);
	}



	//
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
	DDX_Slider(pDX, IDC_SLIDER4, m_sizepen);
	DDV_MinMaxInt(pDX, m_sizepen, 0, 100);
	DDX_Text(pDX, IDC_EDIT1, r_sizepen);
	DDV_MinMaxInt(pDX, r_sizepen, 0, INT_MAX);
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
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Cdraw33Dlg::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Cdraw33Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &Cdraw33Dlg::OnBnClickedMfcbutton2)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &Cdraw33Dlg::OnBnClickedMfcbutton3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER4, &Cdraw33Dlg::OnNMCustomdrawSlider4)
	ON_BN_CLICKED(IDC_MFCBUTTON4, &Cdraw33Dlg::OnBnClickedMfcbutton4)
	ON_BN_CLICKED(IDC_MFCBUTTON5, &Cdraw33Dlg::OnBnClickedMfcbutton5)
	ON_BN_CLICKED(IDC_MFCBUTTON6, &Cdraw33Dlg::OnBnClickedMfcbutton6)
	ON_BN_CLICKED(IDC_MFCBUTTON7, &Cdraw33Dlg::OnBnClickedMfcbutton7)
	ON_BN_CLICKED(IDC_RADIO1, &Cdraw33Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Cdraw33Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &Cdraw33Dlg::OnBnClickedRadio3)
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
	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);

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
	// my code 
	    UpdateData(true);
		CPaintDC dc(this);


		dc.Rectangle(5,5,995,395);		 //to to client surface


		if(figs.GetSize()>0)
		{
			for(int i=0;i<figs.GetSize()-reversShap;i++)
			{
				CBrush b;
				b.CreateSolidBrush(RGB(2.5*figs[i]->getR(),2.5*figs[i]->getG(),2.5*figs[i]->getB()));
				dc.SelectObject(&b);
		
				figs[i]->Draw(&dc);
			}
		}

		if(lines.GetSize()>0)
		{
			for(int i=0;i<lines.GetSize()-reversLine;i++)
			{
				CPen myPen1(PS_SOLID, 0.5*lines[i]->getSizeLpen(), RGB(2.5*lines[i]->getR(),2.5*lines[i]->getG(),2.5*lines[i]->getB()));
		        CPen *oldPen;
		        oldPen=dc.SelectObject( &myPen1 );
				lines[i]->Draw(&dc);
				dc.SelectObject(oldPen);

			}
		}

		UpdateData(false);

		//
		
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
	UpdateData(true);
		  Ispress=true;
		  start=point;
		  end=point;
		  dist=point;
		  if(ToMove && ! Line)
		  {
			  for(int i=0;i<figs.GetSize();i++)
				{
					if(figs[i]->isinshap(point.x,point.y))
					{
						temp=figs[i];
						//temp->select();
					}
				
				}
		  }
		  UpdateData(false);
		 
	CDialogEx::OnLButtonDown(nFlags, point);
}
																		 


void Cdraw33Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//my code 
	 UpdateData(true);
	 if(Ispress && ! ToMove  && !Line)
	 {
		CClientDC dc(this);
		CPen myPen1(PS_SOLID, 5, RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
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
	 if(Ispress && ! ToMove  && Line)
	 {
		 CClientDC dc(this);
		 CPen myPen1(PS_SOLID, 0.5*m_sizepen, RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
		CPen *oldPen;
		oldPen=dc.SelectObject( &myPen1 ); 
		dc.SetROP2(R2_NOTXORPEN);  
		dc. MoveTo(start);
		dc.LineTo(end);
		end=point;
		dc. MoveTo(start);
		dc.LineTo(end);
		dc.SelectObject(oldPen);


	 }

	 if(temp!=NULL && Ispress && ToMove)
	 {
		int x,y;
		int xx,yy;
		xx = dist.x, yy = dist.y;
		dist = point;
		x = (dist.x - xx);
		y = (dist.y - yy);

		if(temp->getAx()+x >5 && temp->getCx()+x <995 && temp->getAy()+y >5 && temp->getCy()+y <395) // THE shape after move still in client surface
		 {	
			
		RECT r;
		r.bottom=max(temp->getAy(),temp->getCy())+7;
			r.top=min(temp->getAy(),temp->getCy())-7;
			r.left=	min(temp->getAx(),temp->getCx())-7;
			r.right=max(temp->getAx(),temp->getCx())+7;	

		 temp->setR(m_red);
		 temp->setG(m_green);
		 temp->setB(m_blue);

		 temp->setAx(temp->getAx() + x);
		 temp->setAy(temp->getAy() + y);
		 temp->setCx(temp->getCx() + x);
		 temp->setCy(temp->getCy() + y);
		

		 InvalidateRect(&r);
		 }
	 }
	 
	 UpdateData(false);
	 //
	CDialogEx::OnMouseMove(nFlags, point);
}


void Cdraw33Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(true);
	
	
     CClientDC dc(this);
	end=point;
	Ispress=false;
	if(!isin() && !Line  && !ToMove)	// you not in client surface so lines deleted and not make shape
	{
		CPen myPen1(PS_SOLID, 5, RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
		CPen *oldPen;
		oldPen=dc.SelectObject( &myPen1 );
		dc.SetROP2(R2_NOTXORPEN);  
		dc. MoveTo(start);
		dc.LineTo(start.x,end.y);
		dc.LineTo(end.x,end.y);
		dc.LineTo(end.x,start.y);
		dc.LineTo(start.x,start.y);
		end=start;
		dc.SelectObject(oldPen);

	}
	
	if( ! ToMove && !Line)	 // creat shape
		{
		 CBrush b;
		 b.CreateSolidBrush(RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
		 dc.SelectObject(&b);
		 for(int i=0;i<reversShap;i++)
		 {
			 delete figs[ figs.GetSize()-1];
			 figs.RemoveAt(figs.GetSize()-1);
		
		 }
		  reversShap=0;

		  //for square
		  
		  int minx=start.x+min( abs(end.x-start.x),abs(end.y-start.y) );
		  int miny=start.y+ min( abs(end.x-start.x),abs(end.y-start.y) );


		  switch (typeShape)
		  {
			 case 3:
			figs.Add(new MYRectangle(start.x,start.y,end.x,end.y,m_red,m_green,m_blue));
			Invalidate();
			 break;


		   case 2: if(minx>5 && minx <995 && miny>5 && miny<395)
				   {
			        figs.Add(new MYSquare(start.x,start.y,minx,miny,m_red,m_green,m_blue));
			        Invalidate();
				   }
			       break;

		 
		  case 1:
			RECT r;
			r.bottom=max(start.y,end.y)+50;
			r.top=min(start.y,end.y)-50;
			r.left=	min(start.x,end.x)-50;
			r.right=max(start.x,end.x)+50;	


			 figs.Add(new MYEllipse(start.x,start.y,end.x,end.y,m_red,m_green,m_blue));
			 InvalidateRect(&r);
			   break;

		 
		  }
	
		  //to remove "rectangle " of the shape
			CPen myPen1(PS_SOLID, 5, RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
			CPen *oldPen;
			oldPen=dc.SelectObject( &myPen1 );
			dc.SetROP2(R2_NOTXORPEN);  
			dc. MoveTo(start);
			dc.LineTo(start.x,end.y);
			dc.LineTo(end.x,end.y);
			dc.LineTo(end.x,start.y);
			dc.LineTo(start.x,start.y);
		 	dc.SelectObject(oldPen);
	}

	if(Line && !ToMove)
	{
		if(! isin())
		{
			RECT r;
			r.bottom=max(start.y,end.y)+50;
			r.top=min(start.y,end.y)-50;
			r.left=	min(start.x,end.x)-50;
			r.right=max(start.x,end.x)+50;			
		   InvalidateRect(&r);
		  

		}
		else
		{
		for(int i=0;i<reversLine;i++)
		 {
			 lines.RemoveAt(lines.GetSize()-1);
		
		 }
		reversLine=0;
		end=point;

		MYLine* temp=new MYLine (start.x,start.y,end.x,end.y,m_red,m_green,m_blue,m_sizepen);
		lines.Add(temp); 
		
			
			RECT r;
			r.bottom=max(start.y,end.y)+50;
			r.top=min(start.y,end.y)-50;
			r.left=	min(start.x,end.x)-50;
			r.right=max(start.x,end.x)+50;	
			InvalidateRect(&r);
		}
	}


	if(ToMove && temp!=NULL)
	{
		//temp->moved();
		temp=NULL;
	}
	
	UpdateData(false);


	CDialogEx::OnLButtonUp(nFlags, point);
}
// mycode
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
	
	// TODO: Add your control notification handler code here
	//my code
	UpdateData(true);
	CClientDC dc(this);
	 CBrush b;
	 CBrush * oldB;
	 b.CreateSolidBrush(RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
	 oldB=dc.SelectObject(&b);
	 dc.Rectangle(5,400,55,450);
	 dc.SelectObject(oldB);
	 UpdateData(false);;
	 //
	*pResult = 0;
}


void Cdraw33Dlg::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	
	// TODO: Add your control notification handler code here
	//my code
	UpdateData(true);
	CClientDC dc(this);
	 CBrush b;
	 CBrush * oldB;
	 b.CreateSolidBrush(RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
	 oldB=dc.SelectObject(&b);
	 dc.Rectangle(5,400,55,450);
	 dc.SelectObject(oldB);
	 UpdateData(false);
	 //
	*pResult = 0;
}


void Cdraw33Dlg::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	
	
	// TODO: Add your control notification handler code here
	//my code
	UpdateData(true);
	CClientDC dc(this);
	 CBrush b;
	 CBrush * oldB;
	 b.CreateSolidBrush(RGB(2.5*m_red,2.5*m_green,2.5*m_blue));
	 oldB=dc.SelectObject(&b);
	 dc.Rectangle(5,400,55,450);
	 dc.SelectObject(oldB);
	 UpdateData(false);
	 //
	*pResult = 0;
}


void Cdraw33Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//my code
	if(reversShap<figs.GetCount())
	{
		reversShap++;
	Invalidate();
	//PlaySound(TEXT("Undo_Shape.wav"),NULL,SND_ASYNC|SND_FILENAME);
	}
	//
	
}


void Cdraw33Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	// my code
	if(reversShap>0)
	{
		reversShap--;
		Invalidate();
		//PlaySound(TEXT("Redo_Shape.wav"),NULL,SND_ASYNC|SND_FILENAME);

	}
	//
	
}


void Cdraw33Dlg::OnBnClickedMfcbutton1()
{

	// TODO: Add your control notification handler code here
	//my code
	UpdateData(true);
	ToMove=	! ToMove;
	CButton *b=(CButton *)GetDlgItem(IDC_MFCBUTTON1);
	if(ToMove)
	{
		b->SetWindowText("Move");
	}
	else
	   b->SetWindowText("Create");

	UpdateData(false);

}


void Cdraw33Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
		//my code
	UpdateData(true);
	Line=	! Line;
	CButton *b=(CButton *)GetDlgItem(IDC_BUTTON3);
	if(Line)
	{
		b->SetWindowText("Line");
	}
	else
	   b->SetWindowText("Shapes");

	UpdateData(false);
}


void Cdraw33Dlg::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
	if(reversLine<lines.GetSize())
	{
		reversLine++;
		Invalidate();
		//PlaySound(TEXT("Undo_Line.wav"),NULL,SND_ASYNC|SND_FILENAME);
	}
}


void Cdraw33Dlg::OnBnClickedMfcbutton3()
{
	// TODO: Add your control notification handler code here
	if(reversLine>0)
	{
		reversLine--;
		Invalidate();
		//PlaySound(TEXT("Redo_Line.wav"),NULL,SND_ASYNC|SND_FILENAME);
	}
}


void Cdraw33Dlg::OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	UpdateData(true);
	r_sizepen=0.5* m_sizepen;

	UpdateData(false);
	
	*pResult = 0;
}


void Cdraw33Dlg::OnBnClickedMfcbutton4()
{
	// TODO: Add your control notification handler code here
	int size=figs.GetSize();
	for(int i=0;i<size;i++)
	{
		delete figs[figs.GetSize()-1];
		figs.RemoveAt(figs.GetSize()-1);
		
		
	}
		reversShap=0;
		Invalidate();
}


void Cdraw33Dlg::OnBnClickedMfcbutton5()
{
	// TODO: Add your control notification handler code here
	int size=lines.GetSize();
	for(int i=0;i<size;i++)
	{
		delete lines[lines.GetSize()-1];
		lines.RemoveAt(lines.GetSize()-1);
		
		
	}
	
	reversLine=0;
	Invalidate();
}




void Cdraw33Dlg::OnBnClickedMfcbutton6()	// Save
{
	// TODO: Add your control notification handler code here

	TCHAR szFilters[] = _T("Project Files(*.$$)|*.$$|All Files (*.*)|(*.*)||");
	CFileDialog fileDlg(FALSE,_T("$$"),_T(".draw33"),OFN_HIDEREADONLY, szFilters);
	if(fileDlg.DoModal() == IDOK)
	{
	CFile file(fileDlg.GetPathName(), CFile::modeCreate|CFile::modeWrite);
	CArchive ar (&file, CArchive::store);
	figs.Serialize(ar);
		lines.Serialize(ar);
	ar.Close();
	file.Close();
	}
}


void Cdraw33Dlg::OnBnClickedMfcbutton7()   // Load
{
	// TODO: Add your control notification handler code here
	TCHAR szFilters[] = _T("Project Files(*.$$)|*.$$|All Files (*.*)|(*.*)||");
	CFileDialog fileDlg(FALSE,_T("$$"),_T(".draw33"),OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);
	if(fileDlg.DoModal() == IDOK)
	{
		CFile file(fileDlg.GetPathName(), CFile::modeRead);
		CArchive ar (&file, CArchive::load);
		figs.Serialize(ar);
		lines.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}

}


void Cdraw33Dlg::OnBnClickedRadio1()	   //circle
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	typeShape=1;
	UpdateData(false);
}


void Cdraw33Dlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	typeShape=2;
	UpdateData(false);
}


void Cdraw33Dlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	typeShape=3;
	UpdateData(false);
}