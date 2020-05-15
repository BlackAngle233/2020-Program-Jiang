﻿
// MineSweeperDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MineSweeper.h"
#include "MineSweeping.h"
#include "MineSweeperDlg.h"
#include "afxdialogex.h"
#include "easyGame.h"
#include "mediumGame.h"
#include "difficultGame.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//MineSweeping mineGame;

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


// CMineSweeperDlg 对话框



CMineSweeperDlg::CMineSweeperDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MINESWEEPER_DIALOG, pParent)
	, diffculty(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMineSweeperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, diffculty);
}

BEGIN_MESSAGE_MAP(CMineSweeperDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMineSweeperDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDCANCEL, &CMineSweeperDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CMineSweeperDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMineSweeperDlg 消息处理程序

BOOL CMineSweeperDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMineSweeperDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMineSweeperDlg::OnPaint()
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
		dc.DrawIcon(x, y, m_hIcon);	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMineSweeperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMineSweeperDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMineSweeperDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

}


void CMineSweeperDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString difficultyg;
	DifficultyDegree diff;
	GetDlgItem(IDC_COMBO1)->GetWindowText(difficultyg);
	if (difficultyg == "简单")diff = DifficultyDegree::easy;
	if (difficultyg == "一般")diff = DifficultyDegree::medium;
	if (difficultyg == "困难")diff = DifficultyDegree::hard;
	//mineGame = MineSweeping(diff);
	switch (diff) {
	case DifficultyDegree::easy:
	{
		CDialogEx::OnOK();
		easyGame easyg;
		easyg.DoModal();
		break;
	}
	case DifficultyDegree::medium:
	{
		CDialogEx::OnOK();
		mediumGame mediumg;
		mediumg.DoModal();
		break;
	}
	case DifficultyDegree::hard:
	{
		CDialogEx::OnOK();
		difficultGame difficultg;
		difficultg.DoModal();
		break;
	}
	}
}