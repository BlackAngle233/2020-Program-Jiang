using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClickItem : MonoBehaviour
{
    public int x;
    public int y;

    private void Start()
    {
        x = (int)transform.position.x;
        y = (int)transform.position.y;
    }

    public void Onclick()
    {
        Destroy(gameObject);
        GameMananger.instance.JudgeType(x,y);
    }


}
