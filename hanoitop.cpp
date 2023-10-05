#include <iostream>
using namespace std;

void move(int n, int a, int c, int b)
{
    if (n == 1)
    {
        cout << "move disk " << n-1 << " from tray " << a << " to tray " << b << "\n";
        return;
    }
        
    move(n-1, a, b, c);
    cout <<  "move disk " << n-1 << " from tray " << a << " to tray " << b << "\n";
    move(n-1, c, a, b);
}

int main()
{
    move(3, 1, 2, 3);
    return 0;
}