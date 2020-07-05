using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameMananger : MonoBehaviour
{
    public static GameMananger instance = null;

    class Cell
    {
        public int x;
        public int y;

        // 0: 表示空白  1: 表示数字   2: 表示炸弹
        public int type;

        // 表示周围炸弹的数量
        public int mineCount;

        // 表示对应的gameobject
        public GameObject UnitGB = null;

        // 表示对应的Cover
        public GameObject Cover = null;

        public Cell(int x, int y, int type,GameObject UnitGB,GameObject Cover)
        {
            this.x = x;
            this.y = y;
            this.type = type;
            this.UnitGB = UnitGB;
            this.Cover = Cover;
            mineCount = 0;
        }
    }

    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
        else if (instance != this)
        {
            Destroy(gameObject);
        }
    }

    private void Update()
    {
        Click();
        Timer();
    }

    //0: none 9: bomb 10: normal 11: boom
    public GameObject[] Units;

    // winCanvas
    public GameObject WinPanel;
    // lossCanvas
    public GameObject LossPanel;

    // 表示当前地雷的数量
    public Text count;

    // 表示当前消耗的时间
    public Text time;

    //挂在所有生成的units
    public Transform RootForUnits; 
    public Transform RootForCovers;

    private Cell[,] Cells; // 总共的格子数量
    int columns;  // 行数
    int rows;     // 列数
    int totalMine;// 地雷总数

    float currentTimeSpent = 0f;  //当前花费的时间
    bool isStarted = false;

    public void Timer()
    {
        if (isStarted)
        {
            currentTimeSpent += Time.deltaTime;
            time.text = ((int)currentTimeSpent).ToString();
        }
    }

    //鼠标点击
    public void Click()
    {
        RaycastHit2D hit;

        if (Input.GetMouseButtonDown(0))
        {
            hit = Physics2D.Raycast(Camera.main.ScreenToWorldPoint(Input.mousePosition),
                Vector2.zero);

            if (hit.collider != null && hit.collider.GetComponent<ClickItem>() != null)
            {
                hit.collider.GetComponent<ClickItem>().Onclick();
            }
        }
    }

    // 初始化
    public void Init()
    {
        currentTimeSpent = 0f;
        count.text = "0";
        time.text = "0";
        LossPanel.SetActive(false);
        WinPanel.SetActive(false);
        totalMine = 0;
        Cells = new Cell[columns, rows];
        ClearAllChildren();
    }

    // 销毁所有在Root下的子物体
    public void ClearAllChildren()
    {
        int childCount1 = RootForUnits.childCount;
        for (int i = 0; i < childCount1; i++)
        {
            DestroyImmediate(RootForUnits.GetChild(0).gameObject);
        }

        int childCount2 = RootForCovers.childCount;
        for (int i = 0; i < childCount2; i++)
        {
            DestroyImmediate(RootForCovers.GetChild(0).gameObject);
        }
    }

    //改变摄像头的属性
    public void changeCameraSize(int whichOne)
    {
        switch (whichOne)
        {
            case 0:
                Camera.main.orthographicSize = 6f;
                Camera.main.transform.position = new Vector3(-0.5f,4f,-10f);
                break;
            case 1:
                Camera.main.orthographicSize = 9f;
                Camera.main.transform.position = new Vector3(0.5f, 7.5f, -10f);
                break;
            case 2:
                Camera.main.orthographicSize = 10f;
                Camera.main.transform.position = new Vector3(4.5f, 8.5f, -10f);
                break;
            default:
                break;
        }
    }

    //简单 9*9   普通 16*16  困难 24*18
    public void InstantiateUnits()
    {
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                // 20% 是雷
                if (Random.value < 0.2f)
                {
                    GameObject toInstantiate = Instantiate(Units[9], new Vector3(i, j, 0), Quaternion.identity) as GameObject;
                    GameObject Cover = Instantiate(Units[10], new Vector3(i, j, 0), Quaternion.identity) as GameObject;

                    Cell newCell = new Cell(i, j, 2,toInstantiate,Cover);
                    Cells[i, j] = newCell;
                    totalMine++;

                    toInstantiate.transform.SetParent(RootForUnits);
                    Cover.transform.SetParent(RootForCovers);
                }
                else
                {
                    GameObject toInstantiate = Instantiate(Units[0], new Vector3(i, j, 0), Quaternion.identity) as GameObject;
                    GameObject Cover = Instantiate(Units[10], new Vector3(i, j, 0), Quaternion.identity) as GameObject;

                    Cover.transform.SetParent(RootForCovers);
                    Cell newCell = new Cell(i, j, 0,toInstantiate,Cover);

                    Cells[i, j] = newCell;
                    toInstantiate.transform.SetParent(RootForUnits);
                }
                
            }
        }
        count.text = totalMine.ToString();
    }

    // 设置表示地雷数量的unit
    public void SetMineNum()
    {
        //设置周围地雷的数量
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                if (Cells[i,j].type == 2)
                {
                    if (i!= 0)
                    {
                        Cells[i - 1, j].mineCount++;
                        if (j!= rows - 1)
                        {
                            Cells[i - 1, j + 1].mineCount++;
                        }
                        if (j!= 0)
                        {
                            Cells[i - 1, j - 1].mineCount++;
                        }
                    }

                    if (i!= columns - 1)
                    {
                        Cells[i + 1, j].mineCount++;
                        if (j != rows - 1)
                        {
                            Cells[i + 1, j + 1].mineCount++;
                        }
                        if (j != 0)
                        {
                            Cells[i + 1, j - 1].mineCount++;
                        }
                    }

                    if (j!= rows - 1)
                    {
                        Cells[i, j + 1].mineCount++;
                    }

                    if (j!= 0)
                    {
                        Cells[i, j - 1].mineCount++;
                    }

                }
            }
        }

        //更新units图片
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                if (Cells[i, j].type == 0 && Cells[i,j].mineCount >0)
                {
                    Cells[i, j].UnitGB.GetComponent<SpriteRenderer>().sprite = SetNumPic(Cells[i, j].mineCount);
                    Cells[i, j].type = 1;
                }
            }
        }
    }

    // 根据数量 返回对应的数字图片
    public Sprite SetNumPic(int num)
    {
        return Units[num].GetComponent<SpriteRenderer>().sprite;
    }

    // 设置场景中的元素
    public void SetUpBoard()
    {
        Init();
        InstantiateUnits();
        SetMineNum();
    }

    // 判断点击的位置是什么类型
    public void JudgeType(int x,int y)
    {
        Cells[x, y].Cover = null;

        if (Cells[x,y].type == 2)
        {
            //所有炸弹变红
            for (int i = 0; i < columns; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    if (Cells[i,j].type == 2)
                    {
                        Cells[i, j].UnitGB.GetComponent<SpriteRenderer>().sprite = SetNumPic(11);
                    }
                }
            }

            //显示整个地图
            int childCount = RootForCovers.childCount;
            for (int i = 0; i < childCount; i++)
            {
                DestroyImmediate(RootForCovers.GetChild(0).gameObject);
            }
            LossPanel.SetActive(true);
            return;
        }
        else if (Cells[x,y].type == 0)
        {
            //泛洪填充
            for (int i = x - 1; i <= x + 1; i++)
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (i >= 0 && j >= 0 && i <= columns - 1 && j<=rows-1 && Cells[i,j].Cover!= null && Cells[i,j].type != 2)
                    {
                        Cells[i, j].Cover.GetComponent<ClickItem>().Onclick();
                    }
                }
            }
        }

        //游戏是否胜利
        int currentNum = RootForCovers.childCount;
        if (currentNum - 1 <= totalMine)
        {
            //显示整个地图
            for (int i = 0; i < currentNum; i++)
            {
                DestroyImmediate(RootForCovers.GetChild(0).gameObject);
            }
            WinPanel.SetActive(true);
        }

    }

    #region 按钮

    //简单模式按钮
    public void ButtonForEasyMode()
    {
        changeCameraSize(0);
        isStarted = true;
        columns = 9;
        rows = 9;
        SetUpBoard();
    }

    //普通模式按钮
    public void ButtonForNormalMode()
    {
        changeCameraSize(1);
        isStarted = true;
        columns = 16;
        rows = 16;
        SetUpBoard();
    }

    //困难模式按钮
    public void ButtonForToughMode()
    {
        changeCameraSize(2);
        isStarted = true;
        columns = 24;
        rows = 18;
        SetUpBoard();
    }

    #endregion
}
