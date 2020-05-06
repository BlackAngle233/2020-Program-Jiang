using System.Collections;
using System.Collections.Generic;
using System.IO.MemoryMappedFiles;
using System.Runtime.CompilerServices;
using UnityEngine;
using UnityEngine.UI;

public class BuildMap : MonoBehaviour
{
    public struct Pos
    {
        public int x;
        public int y;
        public int num;
        public bool visible;
        public bool check;
    }
    public GameObject Bomb,Bomb0, Bomb1, Bomb2, Bomb3, Bomb4, Bomb5, Bomb6, Bomb7, Bomb8;
    public static GameObject[,] Squares;
    public static int flags;
    public Image BackGround;
    public Canvas cells;
    public static int[,] map;
    public static Pos[,] Posmap;
    public List<Pos> clearPos;
    // Start is called before the first frame update
    void Start()
    {
        flags = 10;
        BackGround.GetComponent<RectTransform>().sizeDelta = new Vector2(305, 305);
        Build();
        SetPosMap();
    }

    public void SetPosMap()
    {
        Posmap = new Pos[11, 11];
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                Posmap[i, j].x = i;
                Posmap[i, j].y = j;
                Posmap[i, j].num = map[i,j];
                Posmap[i, j].visible = false;
                Posmap[i, j].check = false;
            }
        }
    }

    public static void Boom(int x,int y)
    {
        if (Posmap[x, y].num > 0)
        {
            Posmap[x, y].check = true;
            Posmap[x, y].visible = true;
        }
        else
        {
            Posmap[x, y].check = true;
            Posmap[x, y].visible = true;
            for (int i = x - 1; i <= x + 1; i++)
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (i < 1 || i > 9 || j < 1 || j > 9) continue;
                    if (Posmap[x, y].num == -1) continue;
                    if (i == x && j == y) continue;
                    if (Posmap[i, j].num > 0 && Posmap[i, j].check == false) { Posmap[i, j].check = true; Posmap[i, j].visible = true;}
                    if (Posmap[i, j].num == 0 && Posmap[i, j].check == false)
                    {
                        Posmap[i, j].check = true;
                        Posmap[i, j].visible = true;
                        Debug.Log(i + " , " + j);
                        Boom(i, j);
                    }
                }
            }
        }
    }

    public static void show()
    {
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                if (Posmap[i, j].visible == true)
                {
                    Squares[i, j].transform.Find("Hidden").gameObject.SetActive(false);
                    Squares[i, j].gameObject.GetComponent<Cell>().visible = true;
                }
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void Build()
    {
        map = new int[11, 11];
        Squares = new GameObject[11, 11];
        for (int i = 0;i<11;i++)
        {
            for (int j = 0; j < 11; j++)
            {
                map[i, j] = 0;
                Squares[i, j] = new GameObject();
            }
        }
        int count = 0;
        while(count < 10)
        {
            int rand = Random.Range(0, 81);
            if(map[rand/9 + 1,rand%9 + 1]==0)
            {
                map[rand / 9 + 1, rand % 9 + 1] = -1;
                count++;
            }
        }
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                if(map[i, j] != -1)
                {
                    map[i, j] =
                        Cul(map[i - 1, j - 1])+
                        Cul(map[i - 1, j])+
                        Cul(map[i - 1, j + 1])+
                        Cul(map[i, j - 1])+
                        Cul(map[i, j + 1])+
                        Cul(map[i + 1, j - 1])+
                        Cul(map[i + 1, j])+
                        Cul(map[i + 1, j + 1]);
                }
                Debug.Log(i +" "+ j+" " + map[i, j]);
            }
        }
        for (int i = 1;i<10;i++)
        {
            for (int j = 1;j<10;j++)
            {
                GameObject cell = new GameObject();
                switch (map[i, j])
                {
                    case 0:
                        cell = Instantiate(Bomb0, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j-1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    case 1:
                        cell = Instantiate(Bomb1, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    case 2:
                        cell = Instantiate(Bomb2, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    case 3:
                        cell = Instantiate(Bomb3, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    case 4:
                        cell = Instantiate(Bomb4, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    case 5:
                        cell = Instantiate(Bomb5, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    case 6:
                        cell = Instantiate(Bomb6, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    case 7:
                        cell = Instantiate(Bomb7, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    case 8:
                        cell = Instantiate(Bomb8, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    case -1:
                        cell = Instantiate(Bomb, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i - 1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                    default:
                        cell = Instantiate(Bomb0, new Vector3(cells.transform.position.x + 0 - 30 * 4 + (j - 1) * 30, cells.transform.position.y + 0 + 30 * 4 - (i-1) * 30, 0), Quaternion.identity, cells.transform);
                        break;
                }
                cell.GetComponent<Cell>().x = i;
                cell.GetComponent<Cell>().y = j;
                cell.transform.Find("Hidden").GetComponent<Button>().onClick.AddListener(delegate () { cell.GetComponent<Cell>().Visible(); });
                Squares[i, j] = cell;
            }
        }
    }

    int Cul(int i)
    {
        if (i == -1)
            return 1;
        else
            return 0;
    }
}
