#include <iostream>
#include <fstream>

#define SIZE 10
using namespace std;

int dist[SIZE][SIZE];

int diff(char a, char b) {
    if (a==b){
        return 0;
    }
    else{
        return 1;
    }
}

void editDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();

    for(int i = 1; i <= len2; i++) {
        for(int j = 1; j <= len1; j++) {
            char a = word1[j-1];
            char b = word2[i-1];

            int result1 = dist[i-1][j-1] + diff(a, b);
            int result2 = dist[i-1][j] + 1;
            int result3 = dist[i][j-1] + 1;

            int result = min(result1, result2);
            result = min(result, result3);

            dist[i][j] = result;
        }
    }   
}

int main() {
    string word1, word2;

    cin >> word1 >> word2;

    int len1 = word1.length();
    int len2 = word2.length();
    
    dist[0][0] = 0;
    for(int i = 1; i <= len1; i++) 
        dist[0][i] = i;
    for(int i = 1; i <= len2; i++) 
        dist[i][0] = i;

    editDistance(word1, word2);
    cout << dist[len2][len1];
    
    return 0;
}
