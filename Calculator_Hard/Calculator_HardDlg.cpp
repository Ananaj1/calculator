
// Calculator_HardDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Calculator_Hard.h"
#include "Calculator_HardDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString Vvod, Vvod_memory;
bool point = false;
double number1 = 0;
double number2 = 0;
double number3 = 0;
int action = 0;
double memory = 0;

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CCalculatorHardDlg



CCalculatorHardDlg::CCalculatorHardDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_HARD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorHardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Pole);
}

BEGIN_MESSAGE_MAP(CCalculatorHardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorHardDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorHardDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorHardDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorHardDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorHardDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorHardDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorHardDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorHardDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorHardDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorHardDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorHardDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorHardDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorHardDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorHardDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorHardDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorHardDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorHardDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorHardDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculatorHardDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalculatorHardDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculatorHardDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalculatorHardDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalculatorHardDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CCalculatorHardDlg::OnBnClickedButton24)
END_MESSAGE_MAP()


// Обработчики сообщений CCalculatorHardDlg

BOOL CCalculatorHardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	Pole.SetWindowTextW(L"0");

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCalculatorHardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCalculatorHardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCalculatorHardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorHardDlg::OnBnClickedButton7()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod == L"0") {
		Vvod = L"1";
	}
	else {
		Vvod.Append(L"1");
	}
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton8()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod == L"0") {
		Vvod = L"2";
	}
	else {
		Vvod.Append(L"2");
	}
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton9()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod == L"0") {
		Vvod = L"3";
	}
	else {
		Vvod.Append(L"3");
	}
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton4()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod == L"0") {
		Vvod = L"4";
	}
	else {
		Vvod.Append(L"4");
	}
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton5()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod == L"0") {
		Vvod = L"5";
	}
	else {
		Vvod.Append(L"5");
	}
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton6()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod == L"0") {
		Vvod = L"6";
	}
	else {
		Vvod.Append(L"6");
	}
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod == L"0") {
		Vvod = L"7";
	}
	else {
		Vvod.Append(L"7");
	}
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod == L"0") {
		Vvod = L"8";
	}
	else {
		Vvod.Append(L"8");
	}
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton3()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod == L"0") {
		Vvod = L"9";
	}
	else {
		Vvod.Append(L"9");
	}
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton10()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Vvod != L"0") {
		Vvod.Append(L"0");
		Pole.SetWindowTextW(Vvod);
	}
}


void CCalculatorHardDlg::OnBnClickedButton11()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (point == false && Vvod !=L"") {
		point = true;
		Vvod.Append(L".");
		Pole.SetWindowTextW(Vvod);
	}
}


void CCalculatorHardDlg::OnBnClickedButton12()
{
	// TODO: добавьте свой код обработчика уведомлений
	number1 = _wtof(Vvod);														//Функция _wtof преобразует строку в число
	number1 = number1 * (-1);
	Vvod.Format(L"%g", number1);												//Функция Format преобразует число в строку
	Pole.SetWindowTextW(Vvod);
}


void CCalculatorHardDlg::OnBnClickedButton16()
{
	// TODO: добавьте свой код обработчика уведомлений
	number1 = _wtof(Vvod);
	action = 1;
	Vvod = L"";
	point = false;
}


void CCalculatorHardDlg::OnBnClickedButton15()
{
	// TODO: добавьте свой код обработчика уведомлений
	number1 = _wtof(Vvod);
	action = 2;
	Vvod = L"";
	point = false;
}


void CCalculatorHardDlg::OnBnClickedButton14()
{
	// TODO: добавьте свой код обработчика уведомлений
	number1 = _wtof(Vvod);
	action = 3;
	Vvod = L"";
	point = false;
}


void CCalculatorHardDlg::OnBnClickedButton13()
{
	// TODO: добавьте свой код обработчика уведомлений
	number1 = _wtof(Vvod);
	action = 4;
	Vvod = L"";
	point = false;
}


void CCalculatorHardDlg::OnBnClickedButton17()
{
	// TODO: добавьте свой код обработчика уведомлений
	number2 = _wtof(Vvod);
	switch (action)
	{
	case 1:
		number1 = number1 + number2;
		break;
	case 2:
		number1 = number1 - number2;
		break;
	case 3:
		number1 = number1 * number2;
		break;
	case 4:
		if (number2 == 0) MessageBoxW(L"На ноль делить нельзя!", L"ОШИБКА!!!", NULL);
		else number1 = number1 / number2;
		break;
	case 5:
		number1 = pow(number1, number2);
		break; 
	}
	Vvod.Format(L"%g", number1);
	Pole.SetWindowTextW(Vvod);
	Vvod = L"";
}


void CCalculatorHardDlg::OnBnClickedButton18()
{
	// TODO: добавьте свой код обработчика уведомлений
	number1 = _wtof(Vvod);
	action = 5;
	Vvod = L"";
	point = false;
}


void CCalculatorHardDlg::OnBnClickedButton19()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (number1 < 0) {
		MessageBoxW(L"Нельзя взять корень из отрицательного числа", L"Ошибка", NULL);
	}
	else {
		number1 = _wtof(Vvod);
		number1 = sqrt(number1);
		Vvod.Format(L"%g", number1);
		Pole.SetWindowTextW(Vvod);
	}
}


void CCalculatorHardDlg::OnBnClickedButton20()
{
	// TODO: добавьте свой код обработчика уведомлений
	Vvod = L"0";
	Pole.SetWindowTextW(Vvod);
	point = false;
}


void CCalculatorHardDlg::OnBnClickedButton21()
{
	// TODO: добавьте свой код обработчика уведомлений
	number1 = _wtof(Vvod);
	memory = memory + number1;
	Vvod = L"";
	point = false;
}


void CCalculatorHardDlg::OnBnClickedButton22()
{
	// TODO: добавьте свой код обработчика уведомлений
	number1 = _wtof(Vvod);
	memory = memory - number1;
	Vvod = L"";
	point = false;
}


void CCalculatorHardDlg::OnBnClickedButton23()
{
	// TODO: добавьте свой код обработчика уведомлений
	Vvod_memory.Format(L"%g", memory);
	Pole.SetWindowTextW(Vvod_memory);
}


void CCalculatorHardDlg::OnBnClickedButton24()
{
	// TODO: добавьте свой код обработчика уведомлений
	memory = 0;
}
