#include <bits/stdc++.h>
using namespace std;

int magicSlow(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == i)
            return i;
    }
    return -1;
}

int magicFast(vector<int> a)
{
    
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 5, 7, 7, 8, 9};

    cout << magicSlow(a) << endl;

    return 0;
}