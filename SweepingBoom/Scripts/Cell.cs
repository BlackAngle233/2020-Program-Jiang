using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cell : MonoBehaviour
{
    public bool IsBomb;//是否是雷
    public bool isFlaged;//是否标记了flag
    public  CellManager cellManager;

    public void loadSprite(int aroundCells)//加载Sprite
    {
        if (IsBomb)
            GetComponent<SpriteRenderer>().sprite = cellManager.bombSprite;
        else if (isFlaged)
             GetComponent<SpriteRenderer>().sprite = cellManager.flagSprite;
        else
            GetComponent<SpriteRenderer>().sprite = cellManager.openSprites[aroundCells];
    }
    public bool isCovered()//打开状态false 未打开true
    {
        return GetComponent<SpriteRenderer>().sprite.name == "close_default";
    }

    public void OnMouseOver()//Click操作
    {
        if (CellManager.isInited)
        {
                if (Input.GetMouseButtonDown(0))//鼠标左键打开cell
                {

                    if (IsBomb && !isFlaged)//打开的是炸弹就gameover（flag不可打开）
                    {
                        //显示所有炸弹
                        cellManager.UnCoverBombs();

                        //游戏结束
                        Debug.Log("GAME OVER!");
                    }
                    else if (isCovered() && !isFlaged)//打开的是未被打开的cell，加载Sprite,显示无雷区域
                    {
                    print("x:" + transform.position.x + "y:" + transform.position.y);
                        int x = (int)transform.position.x-1;//在数组中位置x-1,y-1
                        int y = (int)transform.position.y-1;
                        loadSprite(cellManager.aroundCells(x, y, 0));
                    //显示无雷区域
                    cellManager.Uncover(x, y, new bool[CellManager.width, CellManager.height]);
                    //判断是否胜利
                    if (cellManager.isFinished())
                        print("You win!");
                }
                else if (!isCovered() && !isFlaged)//打开的是已打开的cell,计算附近雷数，判断是否一次性标记或打开周围的cells
                {
                    Debug.Log("1");
                    int x = (int)transform.position.x-1;
                    int y = (int)transform.position.y-1;
                    //如果附近雷数等于没打开的cell数，打开没打开的cell
                    if (cellManager.aroundCells(x, y, 0) == cellManager.aroundCells(x, y, 1))
                        cellManager.OpAroundCells(x, y, 0);
                    //如果附近的雷数等于没被打开的cell数+flag数
                    if (cellManager.aroundCells(x, y, 0) == cellManager.aroundCells(x, y, 1) + cellManager.aroundCells(x, y, 2))
                        cellManager.OpAroundCells(x, y, 1);

                    if (cellManager.isFinished())
                        print("You win!");
                }

            }
                if (Input.GetMouseButtonDown(1))//鼠标右键插flag
                {
                    if (!isFlaged && isCovered())
                    {
                    print("Flag x:" + transform.position.x + "y:" + transform.position.y);

                    int x = (int)transform.position.x-1;
                        int y = (int)transform.position.y-1;
                        GetComponent<SpriteRenderer>().sprite = cellManager.flagSprite;
                        isFlaged = true;
                        if (CellManager.curr_bombs > 0)
                            CellManager.curr_bombs--;

                    if (cellManager.isFinished())
                        print("You win!");
                }
                    else if (isFlaged)//去除flag
                    {
                        GetComponent<SpriteRenderer>().sprite = cellManager.defaultSprite;
                        isFlaged = false;
                        if (CellManager.curr_bombs < CellManager.bombs)
                            CellManager.curr_bombs++;
                    }
                }

            }
            
        }
    }

