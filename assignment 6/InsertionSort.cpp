#include <iostream>
#include <fstream>
using namespace std;

void insertion_sort(int A[], int n)
{
    int i, j, tmp;

    for(i = 1; i < n; i++)
    {
        tmp = A[i];
        for (j = i; A[j-1] > tmp && j > 0; j--)
        {
            A[j] = A[j-1];
        }
        A[j] = tmp;
    }
}

int main()
{
   ifstream inputFile("input.txt");

   const int MAX_SIZE = 100;
   int A[MAX_SIZE];
   int num;
   int size = 0;

   while (inputFile >> num) {
      if (size < MAX_SIZE) {
         A[size] = num;
         size++;
      }
   }

   insertion_sort(A, size);

   for (int i = 0; i < size; i++) {
      cout << A[i] << " ";
   }

   cout << endl;
}

