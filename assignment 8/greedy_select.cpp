#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define SIZE 10

struct LineInfo {
    int start;
    int end;
    int length;
};

LineInfo heapArr[SIZE + 1];
LineInfo selectedArr[SIZE];
int n = 1, num = 0;

void insertHeap(LineInfo line){
    int p = n;
    heapArr[n++] = line;
    while (1 < p && heapArr[p].length < heapArr[p/2].length){
        swap(heapArr[p], heapArr[p/2]);
        p = p/2;
    }
}

LineInfo pollHeap(){
    int i = 1;
    LineInfo pop = heapArr[1];
    swap(heapArr[1], heapArr[--n]);
    while (i < n){
        if (heapArr[i].length >= heapArr[i*2].length){
            if(i*2 > n) break;
            swap(heapArr[i], heapArr[i*2]);
            i = i * 2;
        }
        else if(heapArr[i].length >= heapArr[i*2+1].length){
            if(i*2 + 1 > n) break;
            swap(heapArr[i], heapArr[i*2+1]);
            i = i * 2 + 1;
        }
        else break;
    }
    return pop;
}

void readFile() {
    ifstream inputFile("input2.txt");
    LineInfo input;
    for(int i = 0; i < SIZE; i++){
        inputFile >> input.start >> input.end;
        input.length = input.end - input.start;
        insertHeap(input);
    }
    inputFile.close();
}

void selectLine(){
    for (int i = 0; i < SIZE; i++)
    {
        LineInfo pop = pollHeap();

        bool check = 1;
        for(int j =0; j < num; j++)
        {
            if(!(selectedArr[j].end <= pop.start || pop.end <= selectedArr[j].start ))
            {
                check = 0;
                break;
            }
        }

        if(check)
            selectedArr[num++] = pop;
    }
}

int main()
{
    readFile();
    selectLine();
    cout << num << endl;
    return 0;
}
