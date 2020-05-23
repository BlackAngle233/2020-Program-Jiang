using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Element : MonoBehaviour
{
    //if this is a mine
    public bool mine;

    public Sprite[] emptyTextures;
    public Sprite mineTexture;
    public 初始化 thing;
    public Text lose;

    // Use this for initialization
    void Start()
    {
        lose = GameObject.Find("lose").GetComponent<Text>();
        thing = GameObject.Find("初始化进程").GetComponent<初始化>();
        mine = Random.value < 0.1;
        if(mine == true)
        {
            thing.mine += 1;
            thing.st_mine += 1;
        }
        int x = (int)transform.position.x;
        int y = (int)transform.position.y;
        Grid.elements[x, y] = this;
        //loadTextures(0);
    }

    public void loadTextures(int adjacentCount)
    {
        if (mine)
        {
            GetComponent<SpriteRenderer>().sprite = mineTexture;
        }
        else
            GetComponent<SpriteRenderer>().sprite = emptyTextures[adjacentCount];
    }


    public void GiveNews(int x, int y)
    {
        Debug.Log(x.ToString() + "," + y.ToString());

    }
    public bool isCovered()
    {
        return GetComponent<SpriteRenderer>().sprite.texture.name == "default";
    }

    void OnMouseOver()
    {
        if(Input.GetMouseButtonUp(0) && thing.over == false)
        {
            //it's a mine
            if (mine)//点开了一个地雷
            {
                //todo:
                Grid.uncoverMines();
                lose.enabled = true;
                thing.over = true;
            }
            else
            {
                //todo:
                int x = (int)transform.position.x;
                int y = (int)transform.position.y;
                loadTextures(Grid.adjacentMines(x, y));

                Grid.FFuncover(x, y, new bool[Grid.width, Grid.hight]);

                //if (Grid.isFinished())
                //{
                //    //print("You win");
                //    Debug.Log("You Win");
                //}
            }
        }
        else if (Input.GetMouseButtonUp(1) && thing.over == false)
        {
            //it's a mine
            if (GetComponent<SpriteRenderer>().sprite == emptyTextures[9])//如果这个地方已经是红旗标识，那么还原
            {
                //todo:
                //Grid.uncoverMines();
                Debug.Log("从红旗变为原样");
                thing.flag -= 1;
                GetComponent<SpriteRenderer>().sprite = emptyTextures[10];
                if (mine)//如果把雷还原了，那么雷的技术也要还回去
                {
                    thing.mine += 1;
                }
            }
            else if(GetComponent<SpriteRenderer>().sprite != emptyTextures[10] && GetComponent<SpriteRenderer>().sprite != emptyTextures[9])
            {
                Debug.Log("已经不是地雷，是被点开的方块，那么不动");
                return;
            }
            else
            {
                //todo:
                Debug.Log("如果是个正常的方块，给他插上旗子");
                thing.flag += 1;
                GetComponent<SpriteRenderer>().sprite = emptyTextures[9];
                if(mine)//如果这确实是个地雷，那么就降低一个地雷数
                {
                    thing.mine -= 1;
                }
                //int x = (int)transform.position.x;
                //int y = (int)transform.position.y;
                //loadTextures(Grid.adjacentMines(x, y));

                //Grid.FFuncover(x, y, new bool[Grid.width, Grid.hight]);

                //if (Grid.isFinished())
                //{
                //    //print("You win");
                //    Debug.Log("You Win");
                //}
            }
        }

    }

    //void Update()
    //{
    //    if (Input.GetMouseButtonDown(1))
    //    {
    //        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
    //        RaycastHit hit;
    //        if (Physics.Raycast(ray, out hit))
    //        {
    //            //GameObject go = hit.collider.gameObject;    //获得选中物体
                
    //            //string goName = go.name;    //获得选中物体的名字，使用hit.transform.name也可以
    //            //Debug.Log(go.transform.position);
    //        }
    //    }
    //}

}

//using System.Collections;
//using System.Collections.Generic;
//using UnityEngine;

//public class Element : MonoBehaviour
//{
//    //if this is a mine
//    public bool mine;

//    public Sprite[] emptyTextures;
//    public Sprite mineTexture;

//    // Use this for initialization
//    void Start()
//    {
//        mine = Random.value < 0.1;

//        float x = transform.position.x;
//        float y = transform.position.y;
//        Grid.elements[x, y] = this;
//        //loadTextures(0);
//    }

//    public void loadTextures(int adjacentCount)
//    {
//        if (mine)
//        {
//            GetComponent<SpriteRenderer>().sprite = mineTexture;
//        }
//        else
//            GetComponent<SpriteRenderer>().sprite = emptyTextures[adjacentCount];
//    }


//    public void GiveNews(int x, int y)
//    {
//        Debug.Log(x.ToString() + "," + y.ToString());

//    }
//    public bool isCovered()
//    {
//        return GetComponent<SpriteRenderer>().sprite.texture.name == "default";
//    }

//    void OnMouseUpAsButton()
//    {
//        //it's a mine
//        if (mine)
//        {
//            //todo:
//            Grid.uncoverMines();
//        }
//        else
//        {
//            //todo:
//            float x = transform.position.x;
//            float y = transform.position.y;
//            loadTextures(Grid.adjacentMines(x, y));

//            Grid.FFuncover(x, y, new bool[Grid.width, Grid.hight]);

//            if (Grid.isFinished())
//            {
//                //print("You win");
//                Debug.Log("You Win");
//            }
//        }
//    }
//}