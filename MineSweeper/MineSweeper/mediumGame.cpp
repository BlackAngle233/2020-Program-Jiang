// mediumGame.cpp: 实现文件
//

#include "stdafx.h"
#include "MineSweeper.h"
#include"MineSweeping.h"
#include "mediumGame.h"
#include "afxdialogex.h"

extern DifficultyDegree diff;
extern MineSweeping mineGame;

// mediumGame 对话框

IMPLEMENT_DYNAMIC(mediumGame, CDialogEx)

mediumGame::mediumGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(MediumGame, pParent)
{

}

mediumGame::~mediumGame()
{
}

void mediumGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mediumGame, CDialogEx)
	ON_BN_CLICKED(NewGame, &mediumGame::OnBnClickedNewgame)
END_MESSAGE_MAP()


// mediumGame 消息处理程序


void mediumGame::OnBnClickedNewgame()
{
	// TODO: 在此添加控件通知处理程序代码
	CPaintDC dc(this); // device context for painting

	CDC *pdc;
	pdc = GetDC();

	//绘制棋盘
	CPen pen(PS_SOLID, 2, RGB(255, 255, 255));
	CPen *pOldpen = pdc->SelectObject(&pen);//获取指针
	//int Ox = 100;
	//int Oy = 100;
	//int numx = 16;//行数
	//int numy = 16;//列数


	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++) {
			pdc->MoveTo(Ox + i * 30, Oy + j * 30 + 28);
			pdc->LineTo(Ox + i * 30, Oy + j * 30);
			pdc->LineTo(Ox + i * 30 + 28, Oy + j * 30);
		}

	//阴影
	CPen pen1(PS_SOLID, 2, RGB(80, 80, 80));
	CPen *pOldpen1 = pdc->SelectObject(&pen1);//获取指针

	for (int ii = 0; ii < M; ii++)
		for (int jj = 0; jj < M; jj++)
		{
			pdc->MoveTo(Ox + ii * 30 + 28, Oy + jj * 30);
			pdc->LineTo(Ox + ii * 30 + 28, Oy + jj * 30 + 28);
			pdc->LineTo(Ox + ii * 30, Oy + jj * 30 + 28);
		}
}


