#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void print(const vector<int> &vec) {
    for(int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void permutation(vector<int> &numbers, int start, int end) {
    if(start == end) {
        print(numbers);
        return;
    }

    for(int k = start; k < numbers.size(); k++) {
        swap(numbers[start], numbers[k]);
        permutation(numbers, start+1, end);
        swap(numbers[k], numbers[start]);    
    }

    return;
}

int main()
{
    string getString;
    getline(cin, getString);
    istringstream istr(getString);

    vector<int> num;
    int digit;

    while (istr >> digit) {
        num.push_back(digit);
    }
    
    permutation(num, 0, num.size()-1);
}
