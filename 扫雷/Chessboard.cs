using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public enum Difficulty
{
    Easy,
    Medium,
    Difficult,
    Custom//自定义
}

public class Chessboard:MonoBehaviour
{
    public static Chessboard singleton;//单例

    public Dropdown dropdownDifferency;
    public GameObject cellPrefab;
    public Difficulty difficulty = Difficulty.Easy;//初始难度
    public TMP_InputField inputW;
    public TMP_InputField inputH;
    public TMP_InputField inputBombCount;
    public GameObject buttonCreateCell;
    public Text resultDisplay;
    public Image shade;
    public Timer timer;
    public List<ButtonCell> cells = new List<ButtonCell>();
    int clickCount = 0;
    bool isFirst = true;
    bool IsWinning = false;
    int height=9;//纵向数量
    int width=9;//横向数量 
    private int bombCount;//总炸弹数
    RectTransform chessboardDisplay;//棋盘显示

    private void Awake()
    {
        singleton = this;//单例
        chessboardDisplay = GetComponent<RectTransform>();
        shade.gameObject.SetActive(false);
        SetDifficulty(difficulty);
        if (difficulty != Difficulty.Custom)
        {
            inputW.text = "32";
            inputH.text = "16";
            inputBombCount.text = "99";
            inputW.gameObject.SetActive(false);
            inputH.gameObject.SetActive(false);
            inputBombCount.gameObject.SetActive(false);
            buttonCreateCell.gameObject.SetActive(false);
        }
    }

    public void SetDifficulty(Difficulty difficulty)
    {  
        if (difficulty == Difficulty.Easy)
        {
            height = width = 9;
            bombCount = 10;
        }
        else if (difficulty == Difficulty.Medium)
        {
            height = width = 16;
            bombCount = 40;
        }
        else if (difficulty == Difficulty.Difficult)
        {
            height = 16;
            width = 32;
            bombCount = 99;
        }


        if (difficulty == Difficulty.Custom)
        {
            inputW.gameObject.SetActive(true);
            inputH.gameObject.SetActive(true);
            inputBombCount.gameObject.SetActive(true);
            buttonCreateCell.gameObject.SetActive(true);

        }
        else buttonCreateCell.gameObject.SetActive(false);
        this.difficulty = difficulty;
        SetCells();
        SetChessBoardSize();
        CreateBomb();
        SetBombCount();
        
    }

    void SetCells()
    {
        ClearCells();
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                GameObject newCell= GameObject.Instantiate(cellPrefab,chessboardDisplay);
                ButtonCell cell= newCell.GetComponent<ButtonCell>();
                cell.SetDefault();
                cell.id.w = i+1;
                cell.id.h = j+1;
                newCell.GetComponent<RectTransform>().anchoredPosition = new Vector2(-30 * (width - 1) + 60 * i, 30 * (height - 1) - 60 * j);//设置位置
                cells.Add(cell);
            }
        }

        Debug.Log(cells.Count);
    }

    void ClearCells()
    {
        if (cells != null)
        {
            foreach (var cell in cells)
            {
                //DestroyImmediate(cell);
                cell.DestroyThis();
                
            }
        }
        cells = new List<ButtonCell>();
        Debug.Log("clear");
    }

    ButtonCell FindCell(int w,int h)
    {
        foreach(var cell in cells)
        {
            if (cell.id.h == h && cell.id.w == w)
            {
                return cell;
            }
        }
        return null;
    }

    ButtonCell FindCell(ButtonCell.ID id)
    {
        return FindCell(id.w, id.h);
    }


    void SetChessBoardSize()
    {
        chessboardDisplay.SetSizeWithCurrentAnchors(RectTransform.Axis.Horizontal, width * 60);
        chessboardDisplay.SetSizeWithCurrentAnchors(RectTransform.Axis.Vertical, height * 60);
    }

    //生成炸弹
    void CreateBomb()
    {
        
        for (int i = 0; i < bombCount; i++)
        {
            int h = Random.Range(1, height+1);
            int w = Random.Range(1, width+1);
            ButtonCell cell = FindCell(w, h);
            if (cell != null)
            {
                if (!cell.isBomb)
                {
                    cell.isBomb = true;
                    //test
                    //cell.SetIcon(UIBomb);
                    //

                }
                else i--;
            }          
            else i--;
        }
    }

    public void ChangeDifferency()
    {
        Difficulty d = (Difficulty)System.Enum.Parse(typeof(Difficulty), dropdownDifferency.options[dropdownDifferency.value].text);//转换为枚举
        SetDifficulty(d);
    }



    public void SetBombCount()
    {
        for (int w = 1; w <= width; w++)
        {
            for(int h = 1; h <= height; h++)
            {
                int count = 0;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        ButtonCell c = FindCell(w - 1 + i, h - 1 + j);
                        if (c != null)
                        {
                            if (c.isBomb)
                            {
                                count++;
                            }
                        }
                    }
                }
                FindCell(w, h).bombCountAround = count;
            }
        }  
    }

    public void DisplayZeroCount(ButtonCell.ID id)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ButtonCell c = FindCell(id.w + i - 1, id.h + j - 1);
                if (c != null) 
                {
                    if (!c.isBomb )
                    {
                        ClickLeft(c.id);
                    }
                }
            }
        }
    }

    public void ClickLeft(ButtonCell.ID id)
    {
        
        Debug.Log($"{ id.w},{ id.h}");
        ButtonCell cell = FindCell(id);
        if (!cell.hasClicked)
        {
            if (cell.isFlaged)
            {
                cell.SetFlag();
            }
            else
            {
                if (!cell.isBomb)
                {
                    cell.DisplayBombCount();
                    if (isFirst)
                    {
                        timer.StartTiming();
                        isFirst = false;
                    }

                    clickCount++;
                    if (clickCount == width * height - bombCount)
                    {
                        Win();
                    }
                }
                else
                {
                    if (isFirst)
                    {
                        ResetGame();
                        ClickLeft(id);
                    }
                    else
                    {
                        cell.SetRed();
                        Fail();
                    }

                }
            }
            
        }
    }

    public void ClickRight(ButtonCell.ID id)
    {
        ButtonCell cell = FindCell(id);
        cell.SetFlag();
    }

    void DisplayAllCells()
    {
        foreach(var cell in cells)
        {
            if (cell.isBomb)
            {
                if (!IsWinning)
                    cell.DisplayBomb();
                else cell.DisplayFlagOnBomb();
            }
            else
            {
                cell.CloseFlag();
                cell.DisplayBombCount();
                
            }          
        }   
        shade.gameObject.SetActive(true);
        shade.rectTransform.SetSizeWithCurrentAnchors(RectTransform.Axis.Horizontal, width * 60);
        shade.rectTransform.SetSizeWithCurrentAnchors(RectTransform.Axis.Vertical, height * 60);
    }

    public void Win()
    {
        timer.StopTiming();
        IsWinning = true;
        resultDisplay.text = "获胜";
        DisplayAllCells();
    }

    public void Fail()
    {
        timer.StopTiming();
        resultDisplay.text = "失败";
        DisplayAllCells();
    }

    public void ResetGame()
    {
        if (difficulty == Difficulty.Custom)
        {
            if (!int.TryParse(inputH.text, out height)||height>16)
            {
                resultDisplay.text = "高请输入1-16的数字";
                throw new System.Exception("You should type in num");
            }
            if (!int.TryParse(inputW.text, out width)||width>32)
            {
                resultDisplay.text = "宽请输入1-32的数字";
                throw new System.Exception("You should type in num");
            }
            if (!int.TryParse(inputBombCount.text, out bombCount))
            {
                resultDisplay.text = "请输入数字";
                throw new System.Exception("You should type in num");
            }          
        }
        if (bombCount >= width * height)
        {
            resultDisplay.text = "炸弹数太多";
            throw new System.Exception("炸弹数超出范围");
        }
        timer.Reset();
        SetDifficulty(difficulty);
        resultDisplay.text = "";
        isFirst = true;
        IsWinning = false;
        clickCount = 0;
        shade.gameObject.SetActive(false);
    }
}
