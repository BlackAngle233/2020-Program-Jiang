// easyGame.cpp: 实现文件
//

#include "stdafx.h"
#include"iostream"
#include "MineSweeper.h"
#include "MineSweeping.h"
#include "easyGame.h"
#include "afxdialogex.h"
#include "MineSweeperDlg.h"
#include "string.h"
using namespace std;

// easyGame 对话框
//extern DifficultyDegree diff;
MineSweeping mineGame;
easyGame easyg;

IMPLEMENT_DYNAMIC(easyGame, CDialogEx)

easyGame::easyGame(CWnd* pParent /*=nullptr*/)
	: CDialogEx(EasyGame, pParent)
{

}

easyGame::~easyGame()
{
}

void easyGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(easyGame, CDialogEx)
	
	ON_BN_CLICKED(NewGame, &easyGame::OnBnClickedNewgame)
	/*ON_CBN_SELCHANGE(DifficultyDegree, &easyGame::OnCbnSelchangeDifficultydegree)*/
//	ON_WM_LBUTTONUP()
ON_WM_LBUTTONDOWN()
//ON_WM_LBUTTONDBLCLK()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// easyGame 消息处理程序


BOOL easyGame::OnInitDialog()
{
	// TODO: 在此处添加实现代码.

	return TRUE;
}


void easyGame::createBoard(CDC *pdc) {
	//CPaintDC dc(this); // device context for painting
	//CDC *pdc;
	//pdc = GetDC();

	//绘制棋盘
	CBrush mybrush1;                             // 画刷	
	mybrush1.CreateSolidBrush(RGB(240, 240, 240)); // 灰色直刷 
	CRect myrect1(80, 80, 500, 500);                 //填充区域	
	pdc->FillRect(myrect1, &mybrush1); //客户端，灰色背景
	CPen pen(PS_SOLID, 2, RGB(255, 255, 255));
	CPen *pOldpen = pdc->SelectObject(&pen);//获取指针

	for (int i = 0; i < E; i++)
		for (int j = 0; j < E; j++) {
			pdc->MoveTo(Ox + i * 30, Oy + j * 30 + 28);
			pdc->LineTo(Ox + i * 30, Oy + j * 30);
			pdc->LineTo(Ox + i * 30 + 28, Oy + j * 30);
		}

	//阴影
	CPen pen1(PS_SOLID, 2, RGB(80, 80, 80));
	CPen *pOldpen1 = pdc->SelectObject(&pen1);//获取指针

	for (int ii = 0; ii < E; ii++)
		for (int jj = 0; jj < E; jj++)
		{
			pdc->MoveTo(Ox + ii * 30 + 28, Oy + jj * 30);
			pdc->LineTo(Ox + ii * 30 + 28, Oy + jj * 30 + 28);
			pdc->LineTo(Ox + ii * 30, Oy + jj * 30 + 28);
		}
}


void easyGame::updateBoard(CDC *pdc,CPoint point) {
	Cell **celle = mineGame.getCellsPtr();
	CPoint pcur;
	if (celle[point.x][point.y].mines == 0) {
		for (int i = 0; i < E; i++)
			for (int j = 0; j < E; j++) {
				if (celle[i][j].mines == 0 && celle[i][j].state==1) {
					easyg.updateCell(pdc,i,j);
					CBrush mybrush1;                             // 画刷	
					mybrush1.CreateSolidBrush(RGB(100, 100, 100)); // 灰色直刷 
					CRect myrect1(Ox + i * 30 + 1, Oy +j * 30 + 1, Ox + i * 30 + 26, Oy + j * 30 + 26);                 //填充区域	
					pdc->FillRect(myrect1, &mybrush1); //客户端，灰色背景
				}
				else if (celle[i][j].state == 1 && celle[i][j].mines >0) {
					pcur.x = i;
					pcur.y = j;
					easyg.addNum(pdc,pcur, celle[i][j].mines);
				}
			}
	}
	if (celle[point.x][point.y].mines == -1) {
		for (int i = 0; i < E; i++)
			for (int j = 0; j < E; j++) {
				if (celle[i][j].mines == -1 ) {
					easyg.updateCell(pdc, i,j);

					pdc->SetTextColor(RGB(0, 0, 0));
					pdc->SetBkColor(RGB(240, 240, 240));
					CFont font;
					pdc->SelectObject(&font);
					CString str;
					str.Format(_T("雷"));

					LOGFONT lf;
					CFont fontTemp, *pFontOld;
					pdc->GetCurrentFont()->GetLogFont(&lf);
					lstrcpy(lf.lfFaceName, _T("宋体"));
					lf.lfWidth = 12;
					lf.lfWeight = FW_THIN;
					lf.lfHeight = 24;
					fontTemp.CreateFontIndirect(&lf);      //创建字体
					pFontOld = pdc->SelectObject(&fontTemp);
					pdc->TextOut(Ox + i * 30+1 , Oy + j * 30+1 , str);
					//使用当前选择的字体在指定位置输出文本。 参数x指定文本起始点的x坐标；参数y指定文本起始点的y坐标；	
					//参数lpszString为要输出的文本字符串；参数nCount指定字符串中的字节个数；参数str为包含要输出的字符的CString对象	
					pdc->SelectObject(pFontOld);
				}
			}
	}
}


void easyGame::updateCellflag(CDC *pdc,CPoint point) {
	easyg.updateCell(pdc, point.x,point.y);
	pdc->SetTextColor(RGB(0, 0, 0));
	pdc->SetBkColor(RGB(240, 240, 240));
	CFont font;
	pdc->SelectObject(&font);
	CString str;
	str.Format(_T("旗"));

	LOGFONT lf;
	CFont fontTemp, *pFontOld;
	pdc->GetCurrentFont()->GetLogFont(&lf);
	lstrcpy(lf.lfFaceName, _T("宋体"));
	lf.lfWidth = 12;
	lf.lfWeight = FW_THIN;
	lf.lfHeight = 24;
	fontTemp.CreateFontIndirect(&lf);      //创建字体
	pFontOld = pdc->SelectObject(&fontTemp);
	pdc->TextOut(Ox + point.x * 30+1 , Oy + point.y * 30+1 , str);
	//使用当前选择的字体在指定位置输出文本。 参数x指定文本起始点的x坐标；参数y指定文本起始点的y坐标；	
	//参数lpszString为要输出的文本字符串；参数nCount指定字符串中的字节个数；参数str为包含要输出的字符的CString对象	
	pdc->SelectObject(pFontOld);
}


void easyGame::addNum(CDC *pdc, CPoint point, int mNum) {
	easyg.updateCell(pdc,point.x,point.y);
	pdc->SetTextColor(RGB(0, 0, 0));	
	pdc->SetBkColor(RGB(235, 235, 235));
	CFont font; 
	pdc->SelectObject(&font);
	CString str;
	str.Format(_T("%d"), mNum);	

	LOGFONT lf;
	CFont fontTemp, *pFontOld;	
	pdc->GetCurrentFont()->GetLogFont(&lf);	
	lstrcpy(lf.lfFaceName, _T("宋体"));
	lf.lfWidth = 20;	
	lf.lfWeight = FW_THIN;	
	lf.lfHeight = 20;
	fontTemp.CreateFontIndirect(&lf);      //创建字体
	pFontOld = pdc->SelectObject(&fontTemp);	
	pdc->TextOut(Ox+point.x*30+4, Oy+point.y*30+4, str);	
	//使用当前选择的字体在指定位置输出文本。 参数x指定文本起始点的x坐标；参数y指定文本起始点的y坐标；	
	//参数lpszString为要输出的文本字符串；参数nCount指定字符串中的字节个数；参数str为包含要输出的字符的CString对象	
	pdc->SelectObject(pFontOld);

}


void easyGame::updateCell(CDC *pdc, int i,int j) {
	CPen pen(PS_SOLID, 2, RGB(100, 100, 100));//画格子凹进去
	CPen *pOldpen = pdc->SelectObject(&pen);//获取指针
	pdc->MoveTo(Ox + i * 30, Oy + j * 30 + 28);
	pdc->LineTo(Ox + i * 30, Oy + j * 30);
	pdc->LineTo(Ox + i * 30 + 28, Oy + j * 30);
}


void easyGame::OnBnClickedNewgame()
{
	// TODO: 在此添加控件通知处理程序代码
	CPaintDC dc(this);
	CDC *pdc;
	pdc = GetDC();
	easyg.createBoard(pdc);
	mineGame = MineSweeping(DifficultyDegree::easy);

	//Cell** chessboard1 = mineGame.getCellsPtr();
	//CString str;
	//str.Format(_T("%s"), DifficultyDegree::easy); //将变量组装到字符串中
	//str.Format(_T("%d"), chessboard1[2][2].mines); //将变量组装到字符串中
	//MessageBox(str);
}


void easyGame::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CPaintDC dc(this); // device context for painting
	CDC *pdc;
	pdc = GetDC();
	
	if (point.x >= E * 30 + Ox || point.x < Ox)return;
	if (point.y >= E * 30 + Oy || point.y < Oy)return;

	CPoint pCurrent;
	pCurrent.x = (point.x - Ox ) / 30;
	pCurrent.y = (point.y - Ox ) / 30;
	//easyg.addNum(pdc, pCurrent, 2);
	//Cell** chessboard1 = mineGame.getCellsPtr();
	//CString str;
	//str.Format(_T("%d"), chessboard1[pCurrent.x][pCurrent.y].mines); //将变量组装到字符串中
	//MessageBox(str);

	mineGame.openCells(pCurrent.x, pCurrent.y);
	
	Cell** chessboard = mineGame.getCellsPtr();
	
	switch (chessboard[pCurrent.x][pCurrent.y].mines) {
	case -1:
		mineGame.gameOver();
		/*刷新棋盘位图函数*/
		easyg.updateBoard(pdc, pCurrent);
		/*刷新棋盘位图函数*/
		MessageBox(_T("Game Over!"));
		break;
	case 0:
		easyg.updateBoard(pdc, pCurrent);
		break;
	case 1:
		easyg.addNum(pdc, pCurrent, 1);
		break;
	case 2:
		easyg.addNum(pdc, pCurrent, 2);
		break;
	case 3:
		easyg.addNum(pdc, pCurrent, 3);
		break;
	case 4:
		easyg.addNum(pdc, pCurrent, 4);
		break;
	case 5:
		easyg.addNum(pdc, pCurrent, 5);
		break;
	case 6:
		easyg.addNum(pdc, pCurrent, 6);
		break;
	case 7:
		easyg.addNum(pdc, pCurrent, 7);
		break;
	case 8:
		easyg.addNum(pdc, pCurrent, 8);
		break;
	}
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void easyGame::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x >= E * 30 + Ox || point.x < Ox)return;
	if (point.y >= E * 30 + Oy || point.y < Oy)return;

	CPaintDC dc(this); // device context for painting
	CDC *pdc;
	pdc = GetDC();
	CPoint pCurrent;
	pCurrent.x = (point.x - Ox ) / 30;
	pCurrent.y = (point.y - Ox ) / 30;

	/*这里放更新棋子位图的函数*/
	Cell **chessb = mineGame.getCellsPtr();
	if (chessb[pCurrent.x][pCurrent.y].state == 0) {
		mineGame.flagCell(pCurrent.x, pCurrent.y);
		easyg.updateCellflag(pdc, pCurrent);
	}
	else if (chessb[pCurrent.x][pCurrent.y].state == -1) {
		mineGame.removeFlag(pCurrent.x, pCurrent.y);
		CBrush mybrush1;                             // 画刷	
		mybrush1.CreateSolidBrush(RGB(100, 100, 100)); // 灰色直刷 
		CRect myrect1(Ox+pCurrent.x*30+1, Oy + pCurrent.y * 30 + 1, Ox + pCurrent.x * 30 + 26, Oy + pCurrent.y * 30 + 26);                 //填充区域	
		pdc->FillRect(myrect1, &mybrush1); //客户端，灰色背景
	}
	/*这里放更新棋子位图的函数*/

	if (mineGame.win())
		MessageBox(_T("You win!!!"));

	CDialogEx::OnRButtonDown(nFlags, point);
}
