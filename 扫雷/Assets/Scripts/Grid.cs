using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Grid
{
    public static int width = 20;
    public static int hight = 10;
    public static Element[,] elements = new Element[width, hight];

    public static void uncoverMines()
    {
        foreach (var item in elements)
        {
            if (item.mine)
            {
                item.loadTextures(0);//把所有地雷打开
            }
        }
    }

    public static bool mineAt(int x, int y)
    {
        if (x >= 0 && y >= 0 && x < width && y < hight)
            return elements[x, y].mine;
        return false;
    }

    public static int adjacentMines(int x, int y)//得到毗邻的地雷数，来判断这个格子应该数字是几
    {
        int count = 0;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (mineAt(x + i, y + j))
                    ++count;
            }
        }
        return count;
    }

    // Flood Fill empty elements
    public static void FFuncover(int x, int y, bool[,] visited)
    {
        // Coordinates in Range?
        if (x >= 0 && y >= 0 && x < width && y < hight)
        {
            // visited already?
            if (visited[x, y])//这个格子已经揭露过了就不用再管了
                return;

            // uncover element首先揭露这个方格，要知道他旁边有多少个地雷
            elements[x, y].loadTextures(adjacentMines(x, y));
            elements[x, y].GiveNews(x, y);

            // close to a mine? then no more work needed here
            if (adjacentMines(x, y) > 0)//如果周围是有地雷的，那么就可以不用继续揭露下去了
                return;

            // set visited flag
            visited[x, y] = true;

            // recursion这里被我缩小了,但是被证实失败了，用其他方式代替
            //FFuncover(x - 1, y, visited);
            //FFuncover(x + 1, y, visited);
            //FFuncover(x, y - 1, visited);
            //FFuncover(x, y + 1, visited);
            //如果这个格子周围没有地雷，那么揭露周围的所有格子
            FFuncover(x - 1, y, visited);
            FFuncover(x + 1, y, visited);
            FFuncover(x, y - 1, visited);
            FFuncover(x, y + 1, visited);
        }
    }

    public static bool isFinished()
    {
        ////尝试找到一个盖住的元素，且这个元素不是地雷
        //foreach (Element elem in elements)
        //    if (elem.isCovered() && !elem.mine)
        //        return false;
        ////
        //// There are none => all are mines => game won.
        //return true;
        return false;
    }
}


//using System.Collections;
//using System.Collections.Generic;
//using UnityEngine;

//public class Grid
//{
//    public static float width = 20;
//    public static float hight = 10;
//    public static Element[,] elements = new Element[width, hight];

//    public static void uncoverMines()
//    {
//        foreach (var item in elements)
//        {
//            if (item.mine)
//            {
//                item.loadTextures(0);//把所有地雷打开
//            }
//        }
//    }

//    public static bool mineAt(float x, float y)
//    {
//        if (x >= 0 && y >= 0 && x < width && y < hight)
//            return elements[x, y].mine;
//        return false;
//    }

//    public static int adjacentMines(float x, float y)//得到毗邻的地雷数，来判断这个格子应该数字是几
//    {
//        int count = 0;
//        for (int i = -1; i < 2; i++)
//        {
//            for (int j = -1; j < 2; j++)
//            {
//                if (mineAt(x + i, y + j))
//                    ++count;
//            }
//        }
//        return count;
//    }

//    // Flood Fill empty elements
//    public static void FFuncover(float x, float y, bool[,] visited)
//    {
//        // Coordinates in Range?
//        if (x >= 0 && y >= 0 && x < width && y < hight)
//        {
//            // visited already?
//            if (visited[x, y])
//                return;

//            // uncover element首先揭露这个方格，要知道他旁边有多少个地雷
//            elements[x, y].loadTextures(adjacentMines(x, y));
//            elements[x, y].GiveNews(x, y);

//            // close to a mine? then no more work needed here
//            if (adjacentMines(x, y) > 0)
//                return;

//            // set visited flag
//            visited[x, y] = true;

//            // recursion这里被我缩小了
//            //FFuncover(x - 1, y, visited);
//            //FFuncover(x + 1, y, visited);
//            //FFuncover(x, y - 1, visited);
//            //FFuncover(x, y + 1, visited);
//            FFuncover(x - 1, y, visited);
//            FFuncover(x + 1, y, visited);
//            FFuncover(x, y - 1, visited);
//            FFuncover(x, y + 1, visited);
//        }
//    }

//    public static bool isFinished()
//    {
//        // Try to find a covered element that is no mine
//        foreach (Element elem in elements)
//            if (elem.isCovered() && !elem.mine)
//                return false;
//        // There are none => all are mines => game won.
//        return true;
//    }
//}
