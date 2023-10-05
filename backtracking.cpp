#include <iostream>
using namespace std;


int total = 0;
int queens[10] = {0, };

bool check(int y, int x)
{
    for (int j = 0; j < y; j++)
    {
        double slope = double(y - j)  / double(x - queens[j]);
        if (slope == 1.0 || slope == -1.0 || queens[j] == x) return false;
    }
    return true;
}

void search(int selected)
{

    if(selected == 10)
    {
        for (int i = 0; i < 10; i++) cout << queens[i];
        cout << endl;
        total += 1;
        return;
    }
    else
    {
        for(int i = 0; i < 10; i ++)
        {
            if (check(selected, i))
            {
                queens[selected] = i;
                search(selected + 1);
            }
        }
    }
}

int main()
{
    search(0);
    cout << total;
    return 0;
}