
// MFCApplication4Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication4Dlg 对话框



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
	, suma(0)
	, sumb(0)
	, result(0)
	, minusa(0)
	, minusb(0)
	, result2(0)
	, multiplya(0)
	, multiplyb(0)
	, result3(0)
	, dividea(0)
	, divideb(0)
	, result4(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, suma);
	DDV_MinMaxFloat(pDX, suma, -65536, 65536);
	DDX_Text(pDX, IDC_EDIT2, sumb);
	DDV_MinMaxFloat(pDX, sumb, -65536, 65536);
	DDX_Text(pDX, IDC_EDIT3, result);
	DDV_MinMaxFloat(pDX, result, -200000, 200000);
	DDX_Text(pDX, IDC_EDIT4, minusa);
	DDV_MinMaxFloat(pDX, minusa, -100000, 100000);
	DDX_Text(pDX, IDC_EDIT7, minusb);
	DDX_Text(pDX, IDC_EDIT10, result2);
	DDV_MinMaxFloat(pDX, result2, -200000, 200000);
	DDX_Text(pDX, IDC_EDIT5, multiplya);
	DDV_MinMaxFloat(pDX, multiplya, -100000, 100000);
	DDX_Text(pDX, IDC_EDIT8, multiplyb);
	DDV_MinMaxFloat(pDX, multiplyb, -100000, 100000);
	DDX_Text(pDX, IDC_EDIT11, result3);
	DDV_MinMaxFloat(pDX, result3, -100000000, 100000000);
	DDX_Text(pDX, IDC_EDIT6, dividea);
	DDV_MinMaxFloat(pDX, dividea, -100000, 100000);
	DDX_Text(pDX, IDC_EDIT9, divideb);
	DDV_MinMaxFloat(pDX, divideb, -100000, 100000);
	DDX_Text(pDX, IDC_EDIT12, result3);
	DDX_Text(pDX, IDC_EDIT12, result4);
	DDV_MinMaxFloat(pDX, result4, -100000000, 100000000);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication4Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication4Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication4Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication4Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication4Dlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT11, &CMFCApplication4Dlg::OnEnChangeEdit11)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 消息处理程序

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
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
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		
	return TRUE; 
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication4Dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication4Dlg::OnBnClickedButton1()
{
	UpdateData(true);
	result = suma + sumb;
	UpdateData(false);
}


void CMFCApplication4Dlg::OnBnClickedButton3()
{
	UpdateData(true);
	result2 = minusa-minusb;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication4Dlg::OnBnClickedButton2()
{
	UpdateData(true);
	result3 = multiplya*multiplyb;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication4Dlg::OnBnClickedButton4()
{
	UpdateData(true);
	result4 = dividea / divideb;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication4Dlg::OnEnChangeEdit11()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
