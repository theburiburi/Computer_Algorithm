#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("input1.txt");
    if(!inputFile){
        cout << "error";
        exit(-1);
    }

    int capacity;
    while(inputFile >> capacity){
        int cup_300 = 0;
        int cup_500 = 0;

        for (int i = capacity / 500; i >= 0; i--){
            int rest_capacity = capacity - (500 * i);
            if (rest_capacity % 300 == 0)
            {
                cup_500 = i;
                cup_300 = rest_capacity / 300;
                break;
            }
        }

        if (cup_300 == 0 && cup_500 == 0){
            cout << "-1" << " ";
        }
        else {
            cout << cup_300 + cup_500 << " ";
        }
    }
}