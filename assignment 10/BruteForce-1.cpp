#include <iostream>

using namespace std;

bool sameCheck(string shortStr, string longStr)
{
    int checkCount = longStr.length() - shortStr.length();
    bool same;
    for(int i = 0; i < checkCount; i++)
    {
        same = true;
        for (int j = 0; j< shortStr.length(); j++)
        {
            if (shortStr[j] != longStr[i+j])
            {
                same = false;
                break;
            }
        }
        if (same == true) return true;
    }
    return false;
}

int main() 
{
    string shortStr, longStr, tmp;

    while(true)
    {
        cin >> shortStr >> longStr;
        if (shortStr.length() > longStr.length())
        {
            tmp = shortStr;
            shortStr = longStr;
            longStr = tmp;
        }
        if(sameCheck(shortStr,longStr))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
}
