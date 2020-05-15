using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using TMPro;

public class ButtonCell : MonoBehaviour,IPointerClickHandler
{
    public struct ID
    {
        public int w;
        public int h;
    }
    public ID id;
    public Sprite UIDefault;
    public Sprite UIBomb;
    public Sprite UIFlag;
    public Sprite UIGrey;

    public bool hasClicked;
    public bool isBomb;//是否是炸弹
    public bool isFlaged;//是否被插旗
    public int bombCountAround = 0;
    public Image icon;
    public TMP_Text text;
    
    public void OnPointerClick(PointerEventData eventData)
    {
        if (eventData.button == PointerEventData.InputButton.Left)
            Chessboard.singleton.ClickLeft(id);
        else if (eventData.button == PointerEventData.InputButton.Right)
            Chessboard.singleton.ClickRight(id);
    }

    public void SetDefault()
    {
        isFlaged = false;
        isBomb = false;
        hasClicked = false;
        icon.sprite = UIDefault;
    }

    public void SetRed()
    {
        GetComponent<Image>().color = Color.red;
    }
 
    public void SetFlag()
    {
        if (!hasClicked)
        {
            isFlaged = !isFlaged;
            icon.sprite = isFlaged ? UIFlag : UIDefault;
        }   
    }

    public void CloseFlag()
    {
        isFlaged = false;
        icon.sprite=UIDefault;
    }

    public void DisplayFlagOnBomb()
    {
        icon.sprite = UIFlag;
    }

    public void DisplayBomb()
    {
        icon.sprite = UIBomb;
    }

    public void DisplayBombCount()
    {
        hasClicked = true;
        icon.color = new Color32(223, 223, 223, 255);
        if (bombCountAround != 0)
            text.text = bombCountAround.ToString();
        else
        {
            icon.sprite = UIGrey;

            Chessboard.singleton.DisplayZeroCount(id);
            //这里等于0，要触发周围的0区域
        }     
    }

    public void DestroyThis()
    {
        Destroy(gameObject);
    }



}
