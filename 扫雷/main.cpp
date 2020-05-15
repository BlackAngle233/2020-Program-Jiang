#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int l,r;
int *mine;//存储地雷所在位置
int mines;//存储地雷数目
void randperm(int Num)
{
    vector<int> temp;
    for (int i = 0; i < Num; ++i)
    {
        temp.push_back(i + 1);
    }
    mines=Num/10;
    mine=new int[mines];
    random_shuffle(temp.begin(), temp.end());
    for (int i = 0; i < mines; i++)
    {
        mine[i]=temp[i];
    }
}//生成随机数
class MAP
{
public:
    int Lines;
    int Rows;
    int** maps;
    bool** CanBeSee;
    int HasTouched;
    MAP(int m,int n)
    {
        HasTouched=0;
        Lines=m;
        Rows=n;
        maps=new int*[m];
        CanBeSee=new bool*[m];
        for(int i=0;i<m;i++)
        {
            maps[i]=new int[n];
            CanBeSee[i]=new bool[n];
        }//分配地图
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                maps[i][j]=0;
                CanBeSee[i][j]=0;
            }
        }//初始化数组
        for(int i=0;i<mines;i++)
        {
            int rt=mine[i]/Lines;
            int lt=mine[i]%Lines;
            maps[lt][rt]=-9;
            if(lt>0)maps[lt-1][rt]++;
            if(lt+1<Lines)maps[lt+1][rt]++;
            if(rt>0)maps[lt][rt-1]++;
            if(rt+1<Rows)maps[lt][rt+1]++;
            if(lt>0&&rt>0)maps[lt-1][rt-1]++;
            if(lt+1<Lines&&rt+1<Rows)maps[lt+1][rt+1]++;
            if(lt>0&&rt+1<Rows)maps[lt-1][rt+1]++;
            if(lt+1<Lines&&rt>0)maps[lt+1][rt-1]++;
        }//埋雷并且初始化数字
    }
    void DisPlay()
    {
        for(int i=0;i<Lines;i++)
        {
            for(int j=0;j<Rows;j++)
            {
                cout<<maps[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    bool Touch(int a,int b)
    {
        if(CanBeSee[a][b])return 1;
        if(a>=Lines||b>=Rows)
        {
            cout<<"error input";
            return 1;
        }
        if(maps[a][b]<0)
        {
            cout<<"You failed";
            return 0;
        }
        CanBeSee[a][b]=1;
        HasTouched++;
        if(HasTouched+mines==Lines*Rows)
        {
            cout<<"You win";
            return 0;
        }
        if(maps[a][b]!=0)return 1;
        if(a>0&&maps[a-1][b]!=-1)Touch(a-1,b);
        if(a>0&&b>0&&maps[a-1][b-1]!=-1)Touch(a-1,b-1);
        if(a>0&&b+1<Rows&&maps[a-1][b+1]!=-1)Touch(a-1,b+1);
        if(b>0&&maps[a][b-1]!=-1)Touch(a,b-1);
        if(b+1<Rows&&maps[a][b+1]!=-1)Touch(a,b+1);
        if(a+1<Lines&&maps[a+1][b]!=-1)Touch(a+1,b);
        if(a+1<Lines&&b>0&&maps[a+1][b-1]!=-1)Touch(a+1,b-1);
        if(a+1<Lines&&b+1<Rows&&maps[a+1][b+1]!=-1)Touch(a+1,b+1);
        return 1;
    }
    void Play()
    {
        for(int i=0;i<Lines;i++)
        {
            for(int j=0;j<Rows;j++)
            {
                if(CanBeSee[i][j])cout<<maps[i][j]<<' ';
                else cout<<'*'<<' ';
            }
            cout<<endl;
        }
    }
};
int main()
{
    cout<<"please input the lines you want:";
    cin>>l;
    cout<<"please input the rows you want:";
    cin>>r;
    randperm(l*r);
    MAP tmp(l,r);
    //tmp.DisPlay();
    while(true)
    {
        tmp.Play();
        cout<<"Please input the line you want to touch:";
        cin>>l;
        cout<<"Please input the row you want to touch:";
        cin>>r;
        if(!tmp.Touch(l,r))break;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
