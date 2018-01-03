
// draw33Dlg.h : header file
//

#pragma once
#include "Figure.h"

#include <afxtempl.h>  

// Cdraw33Dlg dialog
class Cdraw33Dlg : public CDialogEx
{
// Construction
	CArray <Figure *> figs;
	int indexarr;
	//my variable
	bool Ispress;
	CPoint start;
	CPoint end;
public:
	Cdraw33Dlg(CWnd* pParent = NULL);	// standard constructor


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
};
