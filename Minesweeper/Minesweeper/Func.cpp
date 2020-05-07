#include "Func.h"
#define random(x) (rand()%(x))+1

MinesWeeper::MinesWeeper(int n, int &rows, int &cols)
{
    MS_num = 10;
    MS_coordinate = 0;
    Sign_num = 0;
    flag = true;
    flag2 = true;
    flag3 = true;
    flag4 = true;
    IsLose = false;
    IsWin = false;
    isFirst = true;
    if (n == 1)
    {
        rows = 9;
        cols = 9;
        mode = Difficulty::Easy;
        MS_num = rows * cols * 0.13;
    }
    else if (n == 2)
    {
        rows = 16;
        cols = 16;
        mode = Difficulty::Medium;
        MS_num = rows * cols * 0.16;
    }
    else if (n == 3)
    {
        rows = 16;
        cols = 30;
        mode = Difficulty::Difficult;
        MS_num = rows * cols * 0.21;
    }
    MS_coordinate_List = new int[MS_num];  //����ֵ�б�
    for (int i = 0; i < MS_num; i++)
        MS_coordinate_List[i] = 0;
    Show = new ShowMap * [rows];
    for (int i = 0; i < rows; ++i)
    {
        Show[i] = new ShowMap[cols];
    }
    maxRow = rows-1;
    maxCol = cols-1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Show[i][j].showValue = "*";
        }
    }
}

//Difficulty MinesWeeper::SelectMode(int n, int &rows, int &cols)
//{
//    if (n==1)
//    {
//        rows = 9;
//        cols = 9;
//        return Difficulty::Easy;
//    }
//    else if (n==2)
//    {
//        rows = 16;
//        cols = 16;
//        return Difficulty::Medium;
//    }
//    else if (n==3)
//    {
//        rows = 16;
//        cols = 30;
//        return Difficulty::Difficult;
//    }
//}

void MinesWeeper::EnumPrint(string **map, int rows, int cols)
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "{  ";
        for (int j = 0; j < cols; j++)
        {
            cout << map[i][j] << "  ";
        }
        cout << "}," << endl;
    }
    cout << endl;
}

void MinesWeeper::EnumInitMap(string **map, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        map[i] = new string[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            map[i][j] = "0";
        }
    }
}

void MinesWeeper::EnumMsCreate(string **map, int rows, int cols)
{
    int row = 0;
    int col = 0;
    int num = rows * cols;

    for (int i = 0; i < MS_num; )
    {
        MS_coordinate = random(num);
        row = MS_coordinate / cols;
        col = MS_coordinate % cols;
        for (int j = 0; j < MS_num; j++)
        {
            if (MS_coordinate == MS_coordinate_List[j])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            MS_coordinate_List[i] = MS_coordinate;
            if (col != 0)
            {
                col--;
            }
            else
            {
                row--;
                col = cols - 1;
            }
            map[row][col] = "x";
            i++;
        }
        flag = true;
    }

    for (int i = 0; i < MS_num; i++)
    {

        row = MS_coordinate_List[i] / cols;
        col = MS_coordinate_List[i] % cols;
        if (col != 0)
        {
            col--;
        }
        else
        {
            row--;
            col = cols - 1;
        }
        if (MS_coordinate_List[i] % cols == 0)  //�жϵ�ǰ�����Ƿ�λ��������
        {
            if ((MS_coordinate_List[i] - cols) > 0)  //�жϵ����Ϸ��Ƿ����һ��
            {
                for (int j = 0; j < MS_num; j++)
                {
                    if ((MS_coordinate_List[i] -cols -1) == MS_coordinate_List[j])  //�Ź�������Ϸ�
                        flag = false; 
                    if ((MS_coordinate_List[i] - cols) == MS_coordinate_List[j])  //�Ź�������Ϸ�
                        flag2 = false;
                }
                if (flag)
                    map[row - 1][col - 1] = to_string(atoi(map[row - 1][col - 1].c_str()) + 1);
                if (flag2)
                    map[row - 1][col] = to_string(atoi(map[row - 1][col].c_str()) + 1);
                flag = true;
                flag2 = true;
            }
            for (int j = 0; j < MS_num; j++)
            {
                if ((MS_coordinate_List[i] - 1) == MS_coordinate_List[j])  //�Ź��������
                    flag = false;
            }
            if (flag)
                map[row][col - 1] = to_string(atoi(map[row][col - 1].c_str()) + 1);
            flag = true;
            if ((MS_coordinate_List[i] + cols) <= num)  //�жϵ����·��Ƿ����һ��
            {
                for (int j = 0; j < MS_num; j++)
                {
                    if ((MS_coordinate_List[i] + cols - 1) == MS_coordinate_List[j])  //�Ź�������½��Ƿ���ڵ��ף���������м��㣬��������
                        flag = false;
                    if ((MS_coordinate_List[i] + cols) == MS_coordinate_List[j])  //�Ź�������·�
                        flag2 = false;
                }
                if (flag)
                    map[row + 1][col - 1] = to_string(atoi(map[row + 1][col - 1].c_str()) + 1);
                if (flag2)
                    map[row+1][col] = to_string(atoi(map[row+1][col].c_str()) + 1);
                flag = true;
                flag2 = true;
            }
        }
        else if (MS_coordinate_List[i] % cols == 1)  //�жϵ����Ƿ�λ��������
        {
            if ((MS_coordinate_List[i] - cols) > 0)
            {
                for (int j = 0; j < MS_num; j++)
                {
                    if ((MS_coordinate_List[i] - cols) == MS_coordinate_List[j])
                        flag2 = false;
                    if ((MS_coordinate_List[i] - cols + 1) == MS_coordinate_List[j])
                        flag3 = false;
                }
                if (flag2)
                    map[row - 1][col] = to_string(atoi(map[row - 1][col].c_str()) + 1);
                if (flag3)
                    map[row - 1][col + 1] = to_string(atoi(map[row - 1][col + 1].c_str()) + 1);
                flag2 = true;
                flag3 = true;
            }
            for (int j = 0; j < MS_num; j++)
            {
                if ((MS_coordinate_List[i] + 1) == MS_coordinate_List[j])
                    flag3 = false;
            }
            if (flag3)
                map[row][col+1] = to_string(atoi(map[row][col+1].c_str()) + 1);
            flag3 = true;
            if ((MS_coordinate_List[i] + cols) < num)
            {
                for (int j = 0; j < MS_num; j++)
                {
                    if ((MS_coordinate_List[i] + cols) == MS_coordinate_List[j])  //�Ź�������½��Ƿ���ڵ��ף���������м��㣬��������
                        flag2 = false;
                    if ((MS_coordinate_List[i] + cols + 1) == MS_coordinate_List[j])
                        flag3 = false;
                }
                if (flag2)
                    map[row + 1][col] = to_string(atoi(map[row + 1][col].c_str()) + 1);
                if (flag3)
                    map[row + 1][col + 1] = to_string(atoi(map[row + 1][col + 1].c_str()) + 1);
                flag2 = true;
                flag3 = true;
            }
        }
        else  //���������жϿ�ȷ������λ���м���
        {
            if ((MS_coordinate_List[i] - cols) > 0) //��ǰ�׵��Ϸ��Ƿ����һ��
            {
                for (int j = 0; j < MS_num; j++)
                {
                    if ((MS_coordinate_List[i] - cols - 1) == MS_coordinate_List[j])  //�Ź�������Ͻ��Ƿ���ڵ��ף���������м��㣬��������
                        flag = false;
                    if ((MS_coordinate_List[i] - cols) == MS_coordinate_List[j])  //�Ź�����Ϸ��Ƿ���ڵ��ף���������м��㣬��������
                        flag2 = false;
                    if ((MS_coordinate_List[i] - cols + 1) == MS_coordinate_List[j])  //�Ź�������Ϸ��Ƿ���ڵ��ף���������м��㣬��������
                        flag3 = false;
                }
                if (flag)
                    map[row-1][col-1] = to_string(atoi(map[row-1][col-1].c_str()) + 1);
                if (flag2)
                    map[row-1][col] = to_string(atoi(map[row-1][col].c_str()) + 1);
                if (flag3)
                    map[row-1][col+1] = to_string(atoi(map[row-1][col+1].c_str()) + 1);
                flag = true;
                flag2 = true;
                flag3 = true;
            }
            for (int j = 0; j < MS_num; j++)
            {
                if ((MS_coordinate_List[i] - 1) == MS_coordinate_List[j])  //�Ź�������Ƿ���ڵ��ף���������м��㣬��������
                    flag = false;
                if ((MS_coordinate_List[i] + 1) == MS_coordinate_List[j])  //�Ź�����ҷ��Ƿ���ڵ��ף���������м��㣬��������
                    flag3 = false;
            }
            if (flag)
                map[row][col-1] = to_string(atoi(map[row][col-1].c_str())+ 1);
            if (flag3)
                map[row][col+1] = to_string(atoi(map[row][col+1].c_str()) + 1);
            flag = true;
            flag3 = true;
            if ((MS_coordinate_List[i] + cols) < num) //��ǰ�׵��·��Ƿ����һ��
            {
                for (int j = 0; j < MS_num; j++)
                {
                    if ((MS_coordinate_List[i] + cols - 1) == MS_coordinate_List[j])  //�Ź�������½��Ƿ���ڵ��ף���������м��㣬��������
                        flag = false;
                    if ((MS_coordinate_List[i] + cols) == MS_coordinate_List[j])  //�Ź�����·��Ƿ���ڵ��ף���������м��㣬��������
                        flag2 = false;
                    if ((MS_coordinate_List[i] + cols + 1) == MS_coordinate_List[j])  //�Ź�������½��Ƿ���ڵ��ף���������м��㣬��������
                        flag3 = false;
                }
                if (flag)
                    map[row+1][col-1] = to_string(atoi(map[row + 1][col - 1].c_str()) + 1);
                if (flag2)
                    map[row+1][col] = to_string(atoi(map[row + 1][col].c_str()) + 1);
                if (flag3)
                    map[row+1][col+1] = to_string(atoi(map[row + 1][col + 1].c_str()) + 1);
                flag = true;
                flag2 = true;
                flag3 = true;
            }
        }
    }
}
void MinesWeeper::OpenMap(string** map, int row, int col)
{
    if (row < 0 || col < 0 || row > maxRow || col > maxCol) // �Ƿ񳬽�
    {
        return;
    }
    if (Show[row][col].isRecur)  //�Ƿ�ݹ��
        return;
    Show[row][col].showValue = map[row][col];  //�򿪵�ǰ����
    if (Show[row][col].showValue == "x")  //�Ƿ����
    {
        IsLose = true;
        return;
    }
    if (atoi(Show[row][col].showValue.c_str()) == 0)  //��0����������ݹ鿪������
    {
        isFirst = false;
        Show[row][col].isRecur = true;
        OpenMap(map, row-1, col-1);
        OpenMap(map, row - 1, col);
        OpenMap(map, row - 1, col+1);
        OpenMap(map, row, col - 1);
        OpenMap(map, row, col + 1);
        OpenMap(map, row+1, col - 1);
        OpenMap(map, row + 1, col);
        OpenMap(map, row + 1, col+1);
        return;
    }
    Show[row][col].isRecur = true;
    return;
}
void MinesWeeper::UpdateMap(string **map, int rows, int cols)
{
    if (!IsLose)
    {
        if (!IsWin)
        {
            if (Sign_num == MS_num)
            {
                for (int i = 0; i < maxRow+1; i++)
                {
                    for (int j = 0; j < maxCol+1; j++)
                    {
                        IsWin = (Show[i][j].isFlagInsert && map[i][j] == "x")? true:false;
                    }
                }
                if (IsWin)
                {
                    cout << "���ҳ������еĵ��ף������ʤ����" << endl;
                }
                else
                {
                    IsLose = true;
                    UpdateMap(map, rows, cols);
                    return;
                }
            }
        }
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << "{  ";
            for (int j = 0; j < cols; j++)
            {
                if (Show[i][j].isFlagInsert)
                    cout << Show[i][j].Sign << "  ";
                else
                    cout << Show[i][j].showValue << "  ";
            }
            cout << "}," << endl;
        }
        cout << endl;
        return;
    }
    cout << "�����ˣ�" << endl;
    EnumPrint(map, rows, cols);
    return;
}

void MinesWeeper::SignMs(int row, int col)
{
    if (row < 0 || col < 0 || row > maxRow || col > maxCol) // �Ƿ񳬽�
        return;
    if (Show[row][col].showValue == "*")
    {
        Show[row][col].isFlagInsert = true;
        Sign_num++;
    }
    return;
}

void MinesWeeper::SignMsVoke(int row, int col)
{
    if (row < 0 || col < 0 || row > maxRow || col > maxCol) // �Ƿ񳬽�
        return;
    if (Show[row][col].isFlagInsert)
    {
        Show[row][col].isFlagInsert = false;
        Sign_num--;
    }
    return;
}

void MinesWeeper::MsJudge(string **map, int row, int col)
{
    if (row < 0 || col < 0 || row > maxRow || col > maxCol) // �Ƿ񳬽�
        return;
    if (Show[row][col].showValue != "0" && Show[row][col].showValue != "*")
    {
        int msnum = atoi(map[row][col].c_str());
        int flagnum = 0;
        if (row - 1 < 0)  // ��
            flag = false;
        if (col - 1 < 0)  //��
            flag2 = false;
        if (row + 1 > maxRow)  //��
            flag3 = false;
        if (col + 1 > maxCol)  //��
            flag4 = false;

        if (flag)
        {
            msnum -= (Show[row - 1][col].isFlagInsert && map[row - 1][col] == "x") ? 1 : 0;
            flagnum += Show[row - 1][col].isFlagInsert ? 1 : 0;
        }
        if (flag2)
        {
            msnum -= (Show[row][col - 1].isFlagInsert && map[row][col - 1] == "x") ? 1 : 0;
            flagnum += Show[row][col - 1].isFlagInsert ? 1 : 0;
        }
        if (flag && flag2)
        {
            msnum -= (Show[row - 1][col - 1].isFlagInsert && map[row - 1][col - 1] == "x") ? 1 : 0;
            flagnum += Show[row - 1][col - 1].isFlagInsert ? 1 : 0;
        }
        if (flag3)
        {
            msnum -= (Show[row + 1][col].isFlagInsert && map[row + 1][col] == "x") ? 1 : 0;
            flagnum += Show[row + 1][col].isFlagInsert ? 1 : 0;
        }
        if (flag2 && flag3)
        {
            msnum -= (Show[row + 1][col - 1].isFlagInsert && map[row + 1][col - 1] == "x") ? 1 : 0;
            flagnum += Show[row + 1][col - 1].isFlagInsert ? 1 : 0;
        }
        if (flag4)
        {
            msnum -= (Show[row][col + 1].isFlagInsert && map[row][col + 1] == "x") ? 1 : 0;
            flagnum += Show[row][col + 1].isFlagInsert ? 1 : 0;
        }
        if (flag && flag4)
        {
            msnum -= (Show[row - 1][col + 1].isFlagInsert && map[row - 1][col + 1] == "x") ? 1 : 0;;
            flagnum += Show[row - 1][col + 1].isFlagInsert ? 1 : 0;
        }
        if (flag3 && flag4)
        {
            msnum -= (Show[row + 1][col + 1].isFlagInsert && map[row + 1][col + 1] == "x") ? 1 : 0;
            flagnum += Show[row + 1][col + 1].isFlagInsert ? 1 : 0;
        }
        if (flagnum > atoi(map[row][col].c_str()))
        {
            IsLose = true;
            return;
        }
        else if (flagnum < atoi(map[row][col].c_str()))
        {
            flag = true;
            flag2 = true;
            flag3 = true;
            flag4 = true;
            return;
        }
        else
        {
            if (msnum == 0)
            {
                if (flag)
                {
                    if(!Show[row - 1][col].isFlagInsert)
                        OpenMap(map, row - 1, col);
                }
                if (flag2)
                {
                    if (!Show[row][col - 1].isFlagInsert)
                        OpenMap(map, row, col - 1);
                }
                if (flag && flag2)
                {
                    if (!Show[row - 1][col - 1].isFlagInsert)
                        OpenMap(map, row - 1, col - 1);
                }
                if (flag3)
                {
                    if (!Show[row + 1][col].isFlagInsert)
                        OpenMap(map, row + 1, col);
                }
                if (flag2 && flag3)
                {
                    if (!Show[row + 1][col - 1].isFlagInsert)
                        OpenMap(map, row + 1, col - 1);
                }
                if (flag4)
                {
                    if (!Show[row][col + 1].isFlagInsert)
                        OpenMap(map, row, col + 1);
                }
                if (flag && flag4)
                {
                    if (!Show[row - 1][col + 1].isFlagInsert)
                        OpenMap(map, row - 1, col + 1);
                }
                if (flag3 && flag4)
                {
                    if (!Show[row + 1][col + 1].isFlagInsert)
                        OpenMap(map, row + 1, col + 1);
                }
                flag = true;
                flag2 = true;
                flag3 = true;
                flag4 = true;
                return;
            }
            else
            {
                IsLose = true;
                return;
            }
        }

    }
}



/*
    ��ָ��������a�����ȡ��max-min+1�������浽����j��
    ���ȡֵ����ÿ��ֵ���ظ�
*/
//void shuiji(int min, int max)
//{
//    int a[10], j[10];
//    int num = max - min + 1; //Ҫ������ĸ���
//    int index;         //����±�
//    for (int i = 0; i < num; i++)    //׼��Ҫ���������
//    {
//        a[i] = i + min;
//    }
//    srand((int)time(0));      //�������
//    for (int i = 0; i < num; i++)
//    {
//        index = (int)((float)(num - i) * rand() / (RAND_MAX + 1.0));     //��������±�
//        j[i] = a[index];          //�Ѳ��ظ���������±걣�浽������
//        a[index] = a[num - 1 - i];    //�������Χ�ڵ����һ������±��Ӧ��ֵ,ȥ�滻���ù���ֵ.�����Ͳ��ظ���.����
//                                //�������ù���a[ index ]��������
//    };
//}


