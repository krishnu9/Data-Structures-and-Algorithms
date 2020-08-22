#include <bits/stdc++.h>
using namespace std;

class Tower
{
private:
    int ind;

public:
    stack<int> disks;
    void index(int i)
    {
        ind = i;
    }
    void add(int d)
    {
        if (!disks.empty() && disks.top() <= d)
            cout << "Error!\n";
        else
            disks.push(d);
    }
    void moveTopTo(Tower &T)
    {
        if (disks.empty())
            return;
        int topDisk = disks.top();
        disks.pop();
        T.add(topDisk);
    }
    void moveDisks(int n, Tower &destination, Tower &buffer)
    {
        if (n > 0)
        {
            moveDisks(n - 1, buffer, destination);
            moveTopTo(destination);
            buffer.moveDisks(n - 1, destination, *this);
        }
        return;
    }
    void displayStack()
    {
        stack<int> copy = disks;
        int topD;
        cout << "Stack " << ind << ": ";
        while (!copy.empty())
        {
            topD = copy.top();
            cout << topD << ' ';
            copy.pop();
        }
        cout << endl;
    }
};

int main()
{
    int n = 3;
    Tower towers[n];
    for (int i = 0; i < n; i++)
        towers[i].index(i);
    for (int i = n - 1; i >= 0; i--)
        towers[0].add(i);

    cout << "BEFORE" << '\n';
    for (int i = 0; i < n; i++)
        towers[i].displayStack();

    towers[0].moveDisks(n, towers[2], towers[1]);

    cout << "AFFTER" << '\n';
    for (int i = 0; i < n; i++)
        towers[i].displayStack();

    return 0;
}
