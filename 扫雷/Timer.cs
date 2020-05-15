using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class Timer : MonoBehaviour
{
    public TMP_Text text;
    [SerializeField]
    float time = 0;

    bool isWorking = false;
    private void Awake()
    {
        if (text == null)
        {
            text = GetComponent<TMP_Text>();
        }
    }

    private void Update()
    {
        if (isWorking)
        {
            time += Time.deltaTime;
        }
        text.text = Math.Round(time).ToString()+"s";
    }

    public void StartTiming()
    {
        isWorking = true;
    }

    public void StopTiming()
    {
        isWorking = false;
    }

    public void Reset()
    {
        time = 0;
        isWorking = false;
    }

}
