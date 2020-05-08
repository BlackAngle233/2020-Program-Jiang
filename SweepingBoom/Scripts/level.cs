using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class level : MonoBehaviour
{
    public Difficulty dd;
    public CellManager cellManager;
    public void Change()
    {
        

            if (dd == Difficulty.Easy)
                CellManager.d = Difficulty.Easy;

            else if (dd == Difficulty.Medium)
                CellManager.d = Difficulty.Medium;
            else if (dd == Difficulty.Difficult)
                CellManager.d = Difficulty.Difficult;

            cellManager.Init();
        
    }
}
