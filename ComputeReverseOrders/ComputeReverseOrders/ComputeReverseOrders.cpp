#include <cstdio>


using namespace std;

int getReverseOrders(int a[], int len)
{
    int ans = 0;
    for(int i = 0; i < len-1; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(a[i] > a[j]) ans++;
            printf("%d %d\n",a[i],a[j]);
        } 
    }

    return ans;
}


int main()
{
    int a[4]{4,3,2,1};
    printf("%s %d", "The number of ReverseOrder numbers of given array is:",getReverseOrders(a,4));
    return 0;
}
