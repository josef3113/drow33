
// draw33Dlg.h : header file
//

#pragma once
#include"Shape.h"
#include "Line.h"
//#include "Figure.h"

#include <afxtempl.h>  

// Cdraw33Dlg dialog
class Cdraw33Dlg : public CDialogEx
{
// Construction
	CArray <Shape* > figs;
	CArray <MYLine> lines;
	int revers;
	int reversLine;
	int indexarr;
	//my variable
	bool Ispress;
	CPoint start;
	CPoint end;
	CPoint dist;
	bool ToMove;
	bool Line;
	Shape * temp;
public:
	Cdraw33Dlg(CWnd* pParent = NULL);	// standard constructor
	 ~Cdraw33Dlg();

// Dialog Data
	enum { IDD = IDD_DRAW33_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	int m_red;
	int m_green;
	int m_blue;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	bool isin();
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedButton3();
	int m_sizepen;
	afx_msg void OnBnClickedMfcbutton2();
	afx_msg void OnBnClickedMfcbutton3();
	afx_msg void OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedMfcbutton4();
	afx_msg void OnBnClickedMfcbutton5();
	int r_sizepen;
};
