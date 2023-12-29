#include <iostream>
#include <fstream>

#define SIZE 10
using namespace std;

int A[SIZE];
int dp1[SIZE];
int dp2[SIZE];

int main() {
    ifstream inputFile("input.txt");
    int num;
    int size = 0;

    while(inputFile >> num) {
        A[size++] = num;
    }

    int maxLen = 0;
    int maxLen_Sum = 0;

    for(int i = 0; i < size; i++) {
        dp1[i] = 1;
        dp2[i] = A[i];

        for(int j = 0; j < i; j++) {
            if(A[i] > A[j] && dp1[i] < dp1[j]+1) {
                dp1[i] = dp1[j]+1;
                dp2[i] = dp2[j] + A[i];
            }
        }

        if(maxLen < dp1[i]) {
            maxLen = dp1[i];
            maxLen_Sum = dp2[i];
        }
    }
    
    cout << maxLen_Sum;
}
