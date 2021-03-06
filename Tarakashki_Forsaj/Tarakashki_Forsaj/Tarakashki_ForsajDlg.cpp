
// Tarakashki_ForsajDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Tarakashki_Forsaj.h"
#include "Tarakashki_ForsajDlg.h"
#include "afxdialogex.h"
#include <random>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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


// Диалоговое окно CTarakashkiForsajDlg



CTarakashkiForsajDlg::CTarakashkiForsajDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TARAKASHKI_FORSAJ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTarakashkiForsajDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, pr1);
	DDX_Control(pDX, IDC_PROGRESS2, pr2);
	DDX_Control(pDX, IDC_PROGRESS3, pr3);
	DDX_Control(pDX, IDC_PROGRESS4, pr4);

	pr1.SetRange(0, 100);
	pr2.SetRange(0, 100);
	pr3.SetRange(0, 100);
	pr4.SetRange(0, 100);

	
}

BEGIN_MESSAGE_MAP(CTarakashkiForsajDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CTarakashkiForsajDlg::StartGame)
	ON_BN_CLICKED(IDC_BUTTON2, &CTarakashkiForsajDlg::x1)
	ON_BN_CLICKED(IDC_BUTTON3, &CTarakashkiForsajDlg::x2)
	ON_BN_CLICKED(IDC_BUTTON4, &CTarakashkiForsajDlg::x3)
END_MESSAGE_MAP()


// Обработчики сообщений CTarakashkiForsajDlg

BOOL CTarakashkiForsajDlg::OnInitDialog()
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

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CTarakashkiForsajDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTarakashkiForsajDlg::OnPaint()
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
HCURSOR CTarakashkiForsajDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTarakashkiForsajDlg::OnTimer(UINT_PTR nIDEvent)
{
	UpdateData();
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CDialogEx::OnTimer(nIDEvent);

	if (nIDEvent == 1)
	{
		int pr1_pos = pr1.GetPos();
		int pr2_pos = pr2.GetPos();
		int pr3_pos = pr3.GetPos();
		int pr4_pos = pr4.GetPos();

		if ((pr1_pos < 100) && (pr2_pos < 100) && (pr3_pos < 100) && (pr4_pos < 100)) {
			int R = rand() % 4;
			
			if (R == 1) {
				pr1_pos += 1; 
				pr1.SetPos(pr1_pos);
			}
			else if (R == 2) {
				pr2_pos += 1;
				pr2.SetPos(pr2_pos);
			}
			else if (R == 3) {
				pr3_pos += 1;
				pr3.SetPos(pr3_pos);
			}
			else {
				pr4_pos += 1;
				pr4.SetPos(pr2_pos);
			}
		}
		else {
			KillTimer(1);
			
			if (pr1.GetPos() >= 100) {
				pr1.SetPos(100);

				MessageBox(L"1 won!", L"Yeaaa!!!", NULL);
			}

			if (pr2.GetPos() >= 100) {
				pr2.SetPos(100);

				MessageBox(L"2 won!", L"Yeaaa!!!", NULL);
			}

			if (pr3.GetPos() >= 100) {
				pr3.SetPos(100);

				MessageBox(L"3 won!", L"Yeaaa!!!", NULL);
			}

			if (pr4.GetPos() >= 100) {
				pr4.SetPos(100);

				MessageBox(L"4 won!", L"Yeaaa!!!", NULL);
			}
		}
	}

	UpdateData(FALSE);
}


void CTarakashkiForsajDlg::StartGame()
{
	UpdateData();

	pr1.SetPos(0);
	pr2.SetPos(0);
	pr3.SetPos(0);
	pr4.SetPos(0);

	KillTimer(1);

	UpdateData(FALSE);

	// TODO: добавьте свой код обработчика уведомлений
}


void CTarakashkiForsajDlg::x1()
{

	SetTimer(1, 100, NULL);

	// TODO: добавьте свой код обработчика уведомлений
}


void CTarakashkiForsajDlg::x2()
{

	SetTimer(1, 50, NULL);

	// TODO: добавьте свой код обработчика уведомлений
}


void CTarakashkiForsajDlg::x3()
{

	SetTimer(1, 1, NULL);

	// TODO: добавьте свой код обработчика уведомлений
}
