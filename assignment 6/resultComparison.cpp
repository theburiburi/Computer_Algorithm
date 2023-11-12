#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int comparison = 0;

void insertionSort(int A[], int n)
{
    int i, j, tmp;

    for(i = 1; i < n; i++)
    {
        tmp = A[i];

        for (j = i; A[j-1] > tmp && j > 0; j--)
        {
            A[j] = A[j-1];
            comparison++;
        }
        A[j] = tmp;
    }
}

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
        comparison++;
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

int randomizedPartition(int A[], int p, int r)
{
   random_device rd;
   mt19937 mt(rd());
   uniform_int_distribution <int> uid(p, r);

   int a = uid(mt);
   swap(A[p], A[a]);

   return partition(A, p, r);
}

void randomizedQuickSort(int A[], int p, int r)
{
   if (p < r)
   {
      int q = randomizedPartition(A, p, r);
      randomizedQuickSort(A, p, q - 1);
      randomizedQuickSort(A, q + 1, r);
   }
}

int main()
{
   ifstream inputFile("input.txt");

   const int MAX_SIZE = 100;
   int A_1[MAX_SIZE];
   int A_2[MAX_SIZE];
   int A_3[MAX_SIZE];
   int num;
   int size = 0;

   while (inputFile >> num) {
      if (size < MAX_SIZE) {
         A_1[size] = A_2[size] = A_3[size] = num;
         size++;
      }
   }

   comparison = 0;
   insertionSort(A_1, size);
   cout << "insertionSort : " << comparison << endl;

   comparison = 0;
   quickSort(A_2 , 0 , size - 1);
   cout << "quickSort : " << comparison << endl;

   comparison = 0;
   randomizedQuickSort(A_3 , 0, size - 1);
   cout << "randomizedQuickSort : " << comparison <<endl;
}
