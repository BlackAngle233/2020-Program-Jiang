#pragma once

//#define Ox 100
//#define Oy 100
//#define numx 8
//#define numy 8
//#define mineNum 10

// easyGame 对话框
class easyGame : public CDialogEx
{
	DECLARE_DYNAMIC(easyGame)

public:
	easyGame(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~easyGame();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = EasyGame };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedNewgame();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void createBoard(CDC *pdc);
	void updateCell(CDC *pdc, int i,int j);
	void updateCellflag(CDC *pdc, CPoint point);
	void updateBoard(CDC *pdc,CPoint point);
	void addNum(CDC *pdc, CPoint point,int mNum);

};
