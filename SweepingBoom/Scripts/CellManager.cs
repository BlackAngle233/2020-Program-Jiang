using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public enum  Difficulty
{
    Easy,//9*9  炸弹10
    Medium,//16*16 炸弹30
    Difficult//16*30 炸弹99
}
public class CellManager :MonoBehaviour
{
    //cells的大小
    public static int height ;
    public static int width ;
    //地雷总数
    public static int bombs ;
    //剩余地雷数
    public static int curr_bombs ;
    //cells存储整个数据
    public static Cell[,] cells ;
    //判断是否初始化了
    public static bool isInited;
    public static bool firstInited;
    //Sprites
    public Sprite defaultSprite;
    public Sprite[] openSprites;
    public Sprite bombSprite;
    public Sprite flagSprite;
    //UI Button
    public Canvas resetButton;
    public Canvas difficulty;
    public Canvas BombsNums;
    public GameObject defaultCell;

    public static Difficulty d;
    public  void Init()//初始化难度
    {
        if(cells!=null)
            for(int i = 0; i < cells.GetLength(0);++i)
                for(int j = 0; j < cells.GetLength(1);++j)
                {
                    Destroy(cells[i, j].gameObject);
                    cells[i, j] = null;
                }

        if(d == Difficulty.Easy)
        {
            height = width = 9;
            curr_bombs = bombs = 10;
            isInited = false;
            firstInited = false;
        }
        else if(d == Difficulty.Medium)
        {
            height = width = 16;
            curr_bombs = bombs = 30;
            isInited = false;
            firstInited = false;
        }
        else if(d == Difficulty.Difficult)
        {
            width = 16;
            height = 30;
            curr_bombs = bombs = 99;
            isInited = false;
            firstInited = false;
        }

        cells = new Cell[width, height];

        for (int i = 0; i < cells.GetLength(0); ++i)
            for(int j = 0; j < cells.GetLength(1); ++j)
            {
                Cell newGameObject =Instantiate(defaultCell, transform).GetComponent<Cell>();
                cells[i, j] = newGameObject;
                cells[i, j].cellManager = this;
                newGameObject.gameObject.GetComponent<Transform>().position = new Vector2(i + 1, j + 1);
                newGameObject.gameObject.name = "Cell(" + i + "," + j + ")";
            }
        difficulty.GetComponent<CanvasGroup>().alpha = 0;
        difficulty.GetComponent<CanvasGroup>().interactable = false;
        difficulty.GetComponent<CanvasGroup>().blocksRaycasts = false;

        PutBombs();
    }
    private void Update()
    {
        //更新UI
        BombsNums.GetComponentInChildren<Text>().text = string.Format("<size=80>CurrentBombs: {0}</size>",curr_bombs);
        if(isInited)
        if (isFinished())
            Debug.Log("You win!");
    }
    //重置关卡
    public void reset()//重置关卡
    {
        if (isInited)
        {
            //打开难度选择UI
            difficulty.GetComponent<CanvasGroup>().alpha = 1;
            difficulty.GetComponent<CanvasGroup>().interactable = true;
            difficulty.GetComponent<CanvasGroup>().blocksRaycasts = true;
            curr_bombs = bombs;

            for (int i = 0; i < CellManager.height; ++i)
            {
                for (int j = 0; j < CellManager.width; ++j)
                {
                    cells[i, j].GetComponent<SpriteRenderer>().sprite = defaultSprite;
                    cells[i, j].IsBomb = false;
                    cells[i, j].isFlaged = false;
                    isInited = false;
                    firstInited = false;
                }
            }
        }
    }
    
    public void PutBombs()//放置炸弹
    {

        if (!isInited)
        {
            isInited = true;
            CellManager.firstInited = true;

            int t = 0;
            for (int i = 0; i <= CellManager.bombs / CellManager.width; ++i)//先将雷排到前几排，再从最后遍历交换，保证每个位置出现雷概率一样
            {
                for (int j = 0; j < CellManager.width; ++j)
                {
                    cells[i, j].IsBomb = true;
                    t++;
                    if (t == CellManager.bombs)
                        break;
                }
                if (t == CellManager.bombs)
                    break;
            }

            //knuth-shuffle来保证真随机
            for (int i = CellManager.height * CellManager.width - 1; i >= 0; --i)
            {
                int ix = (int)(i / CellManager.width);
                int iy = i % CellManager.width;

                int rand = Random.Range(0, i + 1);
                int randx = rand / CellManager.width;
                int randy = rand % CellManager.width;

                var temp = CellManager.cells[ix, iy].IsBomb;
                CellManager.cells[ix, iy].IsBomb = CellManager.cells[randx, randy].IsBomb;
                CellManager.cells[randx, randy].IsBomb = temp;
            }
        }
    }

    //展示所有炸弹
        public  void UnCoverBombs()
    {
        foreach(var cell in cells)
        {
            if (cell.IsBomb)
                cell.loadSprite(0);
        }
    }
    //计算相邻8格的状态数 , n为标志位，0-->雷  1-->旗帜  2-->被覆盖
    public int aroundCells(int x, int y , int n)
    {
        int count = 0;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int ix = x + i, iy = y + j;
                    if (i == 0 && j == 0) continue;
                    if (ix < 0 || ix >= width || iy < 0 || iy >= height) continue;
                    switch (n)
                    {
                        case 0:
                            if (cells[ix, iy].IsBomb)
                                count++; break;
                        case 1:
                            if (cells[ix, iy].isFlaged)
                                count++; break;
                        case 2:
                            if (cells[ix, iy].isCovered())
                                count++; break;
                    }
                }
            }
        return count;
    }
    public void OpAroundCells(int x, int y, int n)//n 标记 0-->打开周围各子 ， 1标记周围格子
    {      
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int ix = x + i, iy = y + j;
                if (i == 0 && j == 0) continue;
                if (ix < 0 || ix >= width || iy < 0 || iy >= height) continue;
                switch (n)
                {
                    case 0:
                        if(cells[ix,iy].isCovered())
                        cells[ix, iy].loadSprite(aroundCells(ix, iy, 0));
                        break;
                    case 1:
                        if (cells[ix, iy].isCovered())
                        {
                            cells[ix, iy].GetComponent<SpriteRenderer>().sprite = flagSprite;
                            cells[ix, iy].isFlaged = true;
                            if(curr_bombs>0)
                            curr_bombs--;
                        }
                        break;

                }
            }
        }

    }
    //判断cells中某个位置是不是炸弹
    public  bool BombAt(int x, int y)
    {
        if (x >= 0 && y >= 0 && x < width && y < height)
            return cells[x, y].IsBomb;
        return false;
    }


    //flood fill 展示非炸弹的cell
    public  void  Uncover(int x , int y , bool[,] visited)
    {
        if (x >= 0 && y >= 0 && x < width && y < height)
        {
            if (visited[x, y])
                return;


            cells[x, y].loadSprite(aroundCells(x, y,0));
            print("Uncover x:" + x + "y:" + y);
            if (aroundCells(x, y,0) > 0)
                return;

            visited[x, y] = true;

            Uncover(x - 1, y, visited);
            Uncover(x + 1, y, visited);
            Uncover(x , y -1, visited);
            Uncover(x , y + 1, visited);


        }
    }
    //判断游戏是否结束
    public bool isFinished()
    {
        foreach (var cell in cells)
        {
            if (cell.isCovered() && !cell.IsBomb || cell.IsBomb == cell.isFlaged)
                return false;
        }
        return true;
    }
}
