#include <iostream>
using namespace std;

string message = "Hello Dongguk. My name is Uijae Cho";
int MESSAGE_LENGTH;

unsigned int* encryption;
char* decryption;


struct Node {
    int first;
    int second;
    int third;
};

Node* extendedEuclid(int a, int b)
{
    Node* n1 = new Node();
    if (b == 0)
    {
        n1->first = 1; 
        n1->second = 0;
        n1->third = a;
        return n1;
    }
    else
    {
        Node* n2 = extendedEuclid(b, a%b);
        n1->first = n2->second;
        n1->second = n2->first - ((a/b)*n2->second);
        n1->third = n2->third;
        delete n2; return n1;
    }
}

unsigned int do_exp(int c, int key, int N)
{
    unsigned int prod = 1;
    for (int i = 0; i < key; i++)
    {
        prod = (prod * c) % N;
    }
    return prod;
}

void print_encryption(unsigned int e[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << e[i];
    }
    cout << endl;
}

void print_decryption(char c[], int length)
{
    for (int i = 0; i < length; i++)
        cout << c[i];
    cout << endl;
}


int main()
{
   MESSAGE_LENGTH = message.length();

   encryption = new unsigned int[MESSAGE_LENGTH];
   decryption = new char[MESSAGE_LENGTH];

   Node* n;
   int p = 11, q = 17, e = 3;
   int N = p * q;

   for (int i = 0; i < MESSAGE_LENGTH; i++)
   {
      char me = message[i]; 
      int c = (unsigned int) me;
      encryption[i] = do_exp(c, e, N);
   }


   n = extendedEuclid(e, (p - 1) * (q - 1));
   int d = n->first;

   if (d < 0)
      d = d + (p-1)*(q-1);

   for (int i = 0; i < MESSAGE_LENGTH; i++)
      decryption[i] = (char)do_exp(encryption[i], d, N);

   cout << message << endl;
   print_encryption(encryption, MESSAGE_LENGTH);
   print_decryption(decryption, MESSAGE_LENGTH);

   return 0;
}