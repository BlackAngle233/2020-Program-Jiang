using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cell : MonoBehaviour
{
    public enum CELLTYPE {SAFE,BOMB};
    public int num;
    public int x;
    public int y;
    public bool visible;
    //public int bombsAround;
    public bool flagged;
    public CELLTYPE cELLTYPE;

    void Start()
    {
        num = 0;
        visible = false;
        flagged = false;
    }

    public void Visible()
    {
        BuildMap.Boom(x,y);
        BuildMap.show();
    }

    public void SetFlag()
    {
        if (!visible)
        {
            flagged = !flagged;
        }
    }
}
