// difficultGame.cpp: 实现文件
//

#include "stdafx.h"
#include "MineSweeper.h"
#include"MineSweeping.h"
#include "difficultGame.h"
#include "afxdialogex.h"

extern DifficultyDegree diff;
extern MineSweeping mineGame;

// difficultGame 对话框

IMPLEMENT_DYNAMIC(difficultGame, CDialogEx)

difficultGame::difficultGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DifficultGame, pParent)
{

}

difficultGame::~difficultGame()
{
}

void difficultGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(difficultGame, CDialogEx)
END_MESSAGE_MAP()


// difficultGame 消息处理程序
