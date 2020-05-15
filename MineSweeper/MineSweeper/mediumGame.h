#pragma once


// mediumGame 对话框

class mediumGame : public CDialogEx
{
	DECLARE_DYNAMIC(mediumGame)

public:
	mediumGame(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~mediumGame();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = MediumGame };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNewgame();
};
