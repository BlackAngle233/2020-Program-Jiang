using System;
using System.Collections;
using System.Collections.Generic;
using UnityEditorInternal;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.EventSystems;

public class Click : MonoBehaviour, IPointerClickHandler
{
    public UnityEvent rightClick;
    // Start is called before the first frame update
    void Start()
    {
        rightClick.AddListener(new UnityAction(ButtonRightClick));
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        if (eventData.button == PointerEventData.InputButton.Right)
        {
            ButtonRightClick();
        }
    }

    public void ButtonRightClick()
    {
        Debug.Log(1);
        if (BuildMap.flags <= 0 && !gameObject.transform.parent.GetComponent<Cell>().flagged)
        {
            Debug.Log("No flag");
        }
        else if (!gameObject.transform.parent.GetComponent<Cell>().visible)
        {
            if (gameObject.transform.parent.GetComponent<Cell>().flagged)
            {
                BuildMap.flags++;
                gameObject.transform.parent.GetComponent<Cell>().flagged = !gameObject.transform.parent.GetComponent<Cell>().flagged;
                gameObject.transform.parent.Find("Flag").gameObject.SetActive(false);
                Debug.Log(BuildMap.flags);
            }
            else
            {
                BuildMap.flags--;
                gameObject.transform.parent.GetComponent<Cell>().flagged = !gameObject.transform.parent.GetComponent<Cell>().flagged;
                gameObject.transform.parent.Find("Flag").gameObject.SetActive(true);
                Debug.Log(BuildMap.flags);
            }
        }
    }

}
