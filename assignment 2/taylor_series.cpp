#include <iostream>
using namespace std;

double taylor(double x, double n)
{
    if(n >= 30) return 0;
    else return 1 + (x/n) * taylor(x, n+1);
}

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << taylor(i, 1) << endl;
    }
    return 0;
}