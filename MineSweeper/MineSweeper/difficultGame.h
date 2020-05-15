#pragma once


// difficultGame 对话框

class difficultGame : public CDialogEx
{
	DECLARE_DYNAMIC(difficultGame)

public:
	difficultGame(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~difficultGame();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = DifficultGame };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
