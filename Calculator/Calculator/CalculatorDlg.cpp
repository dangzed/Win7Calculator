
// CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include<string>
#include<cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_HistoryText(_T(""))
	, m_Output(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HISTORY, m_HistoryText);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_Output);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CCalculatorDlg::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_C, &CCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &CCalculatorDlg::OnBnClickedButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_PERCENT, &CCalculatorDlg::OnBnClickedButtonPercent)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_INVERSE, &CCalculatorDlg::OnBnClickedButtonInverse)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_COMMA, &CCalculatorDlg::OnBnClickedButtonComma)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CCalculatorDlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_NEGATE, &CCalculatorDlg::OnBnClickedButtonNegate)
	ON_BN_CLICKED(IDC_BUTTON_MC, &CCalculatorDlg::OnBnClickedButtonMc)
	ON_BN_CLICKED(IDC_BUTTON_MR, &CCalculatorDlg::OnBnClickedButtonMr)
	ON_BN_CLICKED(IDC_BUTTON_MS, &CCalculatorDlg::OnBnClickedButtonMs)
	ON_BN_CLICKED(IDC_BUTTON_Mplus, &CCalculatorDlg::OnBnClickedButtonMplus)
	ON_BN_CLICKED(IDC_BUTTON_Mminus, &CCalculatorDlg::OnBnClickedButtonMminus)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog() 
{
	CDialogEx::OnInitDialog();
	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	valueBefore = 0;
	historyString = "";
	m_MemVar = 0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam) 
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::addCharacter(char character) {
	if (!isdigit(character) && character!='.') {	// if input is an operator
		
		if (tempOperand.empty()) {	// if tempOperand string is empty
			if (!historyString.empty()) {	// case 1: historyString is not empty => 2 operators consecutive
				historyString.back() = character; // update latest operator in historyString
				m_HistoryText = historyString.c_str();
				UpdateData(FALSE);
				return;
			}
			
			else { // case 2: historyString is empty => operators inputed when nothing on screen
				historyString = std::to_string(valueBefore); // auto add valueBefore at the first of the line
				m_HistoryText = historyString.c_str();
			}
		}
		else {
			valueAdded = stof(tempOperand); 
			if (valueAdded == 0 && getLastOp(historyString) == '/') {	
				m_Output = zeroMessage.c_str();
				historyString = "";
				m_HistoryText.Empty();
				tempOperand = "";
				UpdateData(FALSE);
				return;
			}	// this if block to handle divide by zero exception
			doOperationTwoVar(valueBefore, valueAdded, getLastOp(historyString));  
			tempOperand = "";
		}
	}
	else {	// if input is digit or comma
			
		if (historyString.empty() && valueBefore != 0) valueBefore = 0; // after equal button pressed, start new operation
		tempOperand += character;
		historyString += character;
		m_Output = tempOperand.c_str();
		UpdateData(FALSE);
		return;
	}

	historyString += character;
	m_HistoryText = historyString.c_str();
	m_Output.Format(_T("%f"), valueBefore);  // show output on screen 
	UpdateData(FALSE);
	
} 

void CCalculatorDlg::OnBnClickedButtonEqual()
{	
	// TODO: Add your control notification handler code here
	if (!tempOperand.empty()) {
		valueAdded = stof(tempOperand);

		if (valueAdded == 0 && getLastOp(historyString) == '/') {
			m_Output = zeroMessage.c_str();
			historyString = "";
			m_HistoryText.Empty();
			tempOperand = "";
			UpdateData(FALSE);
			return;
		}	// this if block handle divide by zero exception

		tempOperator = getLastOp(historyString);
		doOperationTwoVar(valueBefore, valueAdded, getLastOp(historyString));
		tempOperand = "";

		m_HistoryText = historyString.c_str(); // ==> show or not show history of operation
		historyString = "";
		m_Output.Format(_T("%f"), valueBefore);
		UpdateData(FALSE);
	}
	else if (tempOperand.empty() && historyString.empty()) {	
		// if equal button is pressed keep doing previous operation
		doOperationTwoVar(valueBefore, valueAdded, tempOperator);
		m_Output = std::to_string(valueBefore).c_str();
		UpdateData(FALSE);
	}
} 


void CCalculatorDlg::doOperationTwoVar(float &valueBefore, float valueAdded, char op) {
	if (op == '+') valueBefore += valueAdded;
	if (op == '-') valueBefore -= valueAdded;
	if (op == '*') valueBefore *= valueAdded;
	if (op == '/') valueBefore /= valueAdded;

}


char CCalculatorDlg::getLastOp(const std::string& expression) {
	for(int i=expression.length()-1; i>=0;i--){
		if (expression[i] == '+' || 
			expression[i] == '-' || 
			expression[i] == '*' || 
			expression[i] == '/') 
			return expression[i];
	}
	return '+';
}

void CCalculatorDlg::OnBnClickedButton0()
{
	// TODO: Add your control notification handler code here
	addCharacter('0');
}

void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	addCharacter('1');
}

void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	addCharacter('2');
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	addCharacter('3');
}


void CCalculatorDlg::OnBnClickedButton4() 
{
	// TODO: Add your control notification handler code here
	addCharacter('4');
}


void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	addCharacter('5');
}


void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	addCharacter('6');
}


void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	addCharacter('7');
}


void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	addCharacter('8');
}


void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	addCharacter('9');
}

void CCalculatorDlg::OnBnClickedButtonComma()
{
	// TODO: Add your control notification handler code here
	addCharacter('.');
}

void CCalculatorDlg::OnBnClickedButtonBack()	// backspace 1 position if it is digit or comma
{
	// TODO: Add your control notification handler code here
	if (!historyString.empty() && (isdigit(historyString.back()) || historyString.back()=='.')) {
		historyString = historyString.substr(0, historyString.size() - 1);
		tempOperand = tempOperand.substr(0, tempOperand.size() - 1);
		m_Output = tempOperand.c_str();
		UpdateData(FALSE); 
	}
}


void CCalculatorDlg::OnBnClickedButtonClear()	// clear whole memmory
{
	// TODO: Add your control notification handler code here
	m_Output.Empty();
	m_HistoryText.Empty();
	historyString = "";
	valueBefore = 0;
	tempOperand = ""; 
	UpdateData(FALSE); 
}


void CCalculatorDlg::OnBnClickedButtonSqrt()
{
	// TODO: Add your control notification handler code here
	if (!tempOperand.empty()) {
		float tempValue;
		std::string tempString;
		tempValue = stof(tempOperand);

		historyString = historyString.substr(0, historyString.size() - tempOperand.size());
		tempOperand = "";
		tempValue = sqrt(tempValue);
		tempString = std::to_string(tempValue); 

		for (int i = 0; i < tempString.size(); i++) {
			addCharacter(tempString.at(i));
		}
	} 
	else if (tempOperand.empty() && historyString.empty()) {	//equal button pressed

		if (valueBefore < 0) { 
			m_Output = sqrtMessage.c_str();
			historyString = "";
			m_HistoryText.Empty();
			tempOperand = "";
			UpdateData(FALSE);
			return;
		}	// this if block handle sqrt of negative number exception

		valueBefore = sqrt(valueBefore);
		m_Output = std::to_string(valueBefore).c_str();
		UpdateData(FALSE);
	}	
}


void CCalculatorDlg::OnBnClickedButtonDivide()
{
	// TODO: Add your control notification handler code here
	addCharacter('/');
}


void CCalculatorDlg::OnBnClickedButtonPercent()
{
	// TODO: Add your control notification handler code here
	if (!tempOperand.empty()) {
		float tempValue;
		std::string tempString;
		tempValue = stof(tempOperand);
		historyString = historyString.substr(0, historyString.size() - tempOperand.size());
		tempOperand = "";
		tempValue /= 100;
		tempString = std::to_string(tempValue);

		for (int i = 0; i < tempString.size(); i++) {
			addCharacter(tempString.at(i));
		}
	}
	else if (tempOperand.empty() && historyString.empty()) {	//equal button pressed
		valueBefore /= 100;
		m_Output = std::to_string(valueBefore).c_str();
		UpdateData(FALSE);
	}
}


void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: Add your control notification handler code here
	addCharacter('*');
}


void CCalculatorDlg::OnBnClickedButtonInverse() 
{
	// TODO: Add your control notification handler code here
	if (!tempOperand.empty()) {
		float tempValue;
		std::string tempString;
		tempValue = stof(tempOperand);
		historyString = historyString.substr(0, historyString.size() - tempOperand.size());
		tempOperand = "";
		tempValue = 1/tempValue;
		tempString = std::to_string(tempValue);

		for (int i = 0; i < tempString.length(); i++) {
			addCharacter(tempString.at(i));
		}
	}
	else if (tempOperand.empty() && historyString.empty()) {	//equal button pressed 
		valueBefore = 1/valueBefore;
		m_Output = std::to_string(valueBefore).c_str();
		UpdateData(FALSE);
	}
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: Add your control notification handler code here
	addCharacter('-');
}


void CCalculatorDlg::OnBnClickedButtonPlus()
{
	// TODO: Add your control notification handler code here
	addCharacter('+');
}


void CCalculatorDlg::OnBnClickedButtonCe()	// clear the current input for tempOperand
{
	// TODO: Add your control notification handler code here
	if (!historyString.empty() && isdigit(historyString.back())) {
		historyString = historyString.substr(0, historyString.size() - tempOperand.size()); 
		tempOperand = ""; 
		m_Output = tempOperand.c_str();
		UpdateData(FALSE);
	}
	
}

void CCalculatorDlg::OnBnClickedButtonNegate()
{
	// TODO: Add your control notification handler code here
	if (!tempOperand.empty()) {
		float tempValue;
		std::string tempString; 
		tempValue = stof(tempOperand);
		historyString = historyString.substr(0, historyString.size() - tempOperand.size()); 
		tempOperand = "";
		tempValue = 0 - tempValue;
		tempString = std::to_string(tempValue);
		//m_Output = tempString.c_str();	// show negate result on screen
		doOperationTwoVar(valueBefore, tempValue, getLastOp(historyString)); 
		historyString += tempString;
		m_Output = std::to_string(valueBefore).c_str();
		UpdateData(FALSE);
	}  
	else if (tempOperand.empty() && historyString.empty()) {	//equal button pressed
		valueBefore = 0-(valueBefore);
		m_Output = std::to_string(valueBefore).c_str();
		UpdateData(FALSE);
	}
}


void CCalculatorDlg::OnBnClickedButtonMc()
{
	// TODO: Add your control notification handler code here
	m_MemVar = 0;
}


void CCalculatorDlg::OnBnClickedButtonMr()
{
	// TODO: Add your control notification handler code here
	if (tempOperand.empty()) {

	std::string tempString;
	tempString = std::to_string(m_MemVar);
	for (int i = 0; i < tempString.length(); i++)
		addCharacter(tempString.at(i));
	}
}


void CCalculatorDlg::OnBnClickedButtonMs()
{
	// TODO: Add your control notification handler code here
	if (historyString.empty())	m_MemVar = valueBefore;
	else m_MemVar = std::stof(tempOperand);
}


void CCalculatorDlg::OnBnClickedButtonMplus()
{
	// TODO: Add your control notification handler code here
	if (!tempOperand.empty()) m_MemVar += std::stof(tempOperand);
}


void CCalculatorDlg::OnBnClickedButtonMminus()
{
	// TODO: Add your control notification handler code here
	if (!tempOperand.empty()) m_MemVar -= std::stof(tempOperand);
}
