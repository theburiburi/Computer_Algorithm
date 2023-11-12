#include <iostream>
#include <string>
using namespace std;

#define MESSAGE_LENGTH 100

int main()
{
    int key = 5;
    string myMessage = "Hello, I love Dongguk. Please love UiJae Jo!!!";
    char encryption[MESSAGE_LENGTH];
    char decryption[MESSAGE_LENGTH];


    unsigned int c = 0;
    int i;

    cout << "encrypted message = ";
    for (i = 0; i < myMessage.length(); i++)
    {
        c = (unsigned int) myMessage.at(i);
        c = c ^ key;
        encryption[i] = (char) c;
        cout << encryption[i];
    }
    encryption[i] = '\0';

    cout << '\n' << "decrypted mesaage = ";
    for (i = 0; i < myMessage.length(); i++)
    {
        c = (unsigned int) encryption[i];
        c = c ^ key;
        decryption[i] = (char) c;
        cout << decryption[i];
    }
    decryption[i] = '\0';
}