#include <iostream>
#include <fstream>

using namespace std;

int partition(int A[], int p, int r)
{
    int pivot = A[p];
    int h = p;
    for(int k = p+1; k <= r; k++)
    {
        if (A[k] < pivot)
        {
            h = h + 1;
            swap(A[h], A[k]);
        }
    }
    swap(A[p], A[h]);

    return h;
}

void quickSort(int A[], int p, int r)
{
    if(p < r)
    {
        int q = partition(A,p,r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
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

   quickSort(A, 0 , size - 1);

   for (int i = 0; i < size; i++) {
      cout << A[i] << " ";
   }

   cout << endl;
}