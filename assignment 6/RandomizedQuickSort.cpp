#include <iostream>
#include <fstream>
#include <random>

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

int randomizedPartition(int A[], int p, int r)
{
   random_device device;
   mt19937 random(device());
   uniform_int_distribution<int> distribution(p, r);

   int a = distribution(random);

   int pivot = A[a];
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
   int A[MAX_SIZE];
   int num;
   int size = 0;

   while (inputFile >> num) {
      if (size < MAX_SIZE) {
         A[size] = num;
         size++;
      }
   }

   randomizedQuickSort(A, 0, size - 1);

   for (int i = 0; i < size; i++) {
      cout << A[i] << " ";
   }
   cout << endl;
}
