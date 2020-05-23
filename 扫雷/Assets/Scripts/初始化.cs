using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class 初始化 : MonoBehaviour
{
    public int mine = 0;
    public int st_mine = 0;
    public int flag = 0;
    public bool over = false;
    public GameObject basicItem;
    public Text win;
    public Text sheng;
    // Use this for initialization


    // Start is called before the first frame update
    void Awake()//如果不是Awake而是start，有可能会出现一开始就胜利的情况（mine和flag和st_mine都是0，update先判断了胜利）
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                //Vector3 pos = new Vector3(0.5f * i, 0.5f * j, 0);
                Vector3 pos = new Vector3(i, j, 0);//这个位置不可以调整，否则会出错
                GameObject go = Instantiate(basicItem,pos, Quaternion.identity);
                go.transform.parent = transform;
            }
        }
        
    }
    void Update()
    {
        sheng.text = "还剩下的地雷数是：" + mine;
        if(Input.GetKeyDown(KeyCode.R))
        {
            SceneManager.LoadScene("SampleScene");
        }
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            Application.Quit();
        }
        if (mine == 0 && flag == st_mine)//地雷已经全部被排除了，且插旗的数量等于最初的地雷数，防止多插旗，以判定胜利
        {
            //Debug.Log("You Win");
            win.enabled = true;
            over = true;
        }
    }
}

// Update is called once per frame

