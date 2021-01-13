
// CalculatorDlg.h : header file
//

#pragma once
#include<iostream>

// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

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
private:
	CString m_HistoryText;
	std::string historyString;
public:
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonSqrt();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonPercent();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonInverse();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonComma();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedButtonNegate();
private:
	CString m_Output;
	float valueBefore;
	float valueAdded;
	float m_MemVar;
	std::string tempOperand;
	void addCharacter(char character);
	void doOperationTwoVar(float &valueBefore, float valueAdded, char op);
	char getLastOp(const std::string& expression);
	std::string zeroMessage = "Cannot divide by zero!";
	std::string sqrtMessage = "Invalid input";
	char tempOperator =' ';
	
public:
	afx_msg void OnBnClickedButtonMc();
	afx_msg void OnBnClickedButtonMr();
	afx_msg void OnBnClickedButtonMs();
	afx_msg void OnBnClickedButtonMplus();
	afx_msg void OnBnClickedButtonMminus();
};
