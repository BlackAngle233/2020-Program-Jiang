#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a{1,2,3};
    vector<int> b;
    b.resize(3);
    std::copy(a.begin(),a.end() , b.begin());
    for(int i = 0; i < b.size(); ++i)
    {
        cout << b[i] << endl;
    }

    return 0;
}
