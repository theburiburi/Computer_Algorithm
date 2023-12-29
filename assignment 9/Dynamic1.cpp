#include <iostream>
#include <fstream>

#define SIZE 10
using namespace std;

int A[SIZE];
int dp[SIZE];

int main() {
    ifstream inputFile("input.txt");
    
    int num;
    int size = 0;

    while(inputFile >> num) {
        A[size++] = num;
    }

    int maxLen = 0;
    for(int i = 0; i < size; i++) {
        dp[i] = 1;

        for(int j = 0; j < i; j++) {
            if(A[i] > A[j] && dp[i] < dp[j] + 1) 
                dp[i] = dp[j]+1;
        }
        maxLen = max(maxLen, dp[i]);
    }

    cout << maxLen;
}
