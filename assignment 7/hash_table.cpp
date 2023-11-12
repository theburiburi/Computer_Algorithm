#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

#define TABLE_SIZE 541
#define NAME_SIZE 10

struct Hash
{
    char name[NAME_SIZE];
    unsigned short collision;
};

struct Hash hash_table[TABLE_SIZE];

int hash1(char str[])
{
    int i, h;

    for(i = 0, h = 0; i < strlen(str); i++)
    {
        h = ((int)str[i] + h) % TABLE_SIZE;
    }
    return h;
}

int hash2(char str[])
{
    int i, h;

    for(i = 0, h = 0; i < strlen(str); i++)
    {
        h = ((int)str[i] + h*h) % TABLE_SIZE;
    }
    return h;
}

void hash_insert1(char name[])
{
    int number = 0;
    int key = hash1(name);
    while (strcmp(hash_table[key].name, "") != 0)
    {
        hash_table[key].collision++;
        number++;
        key = (number + key)%TABLE_SIZE;
    }
    strcpy(hash_table[key].name, name);
}

void hash_insert2(char name[])
{
    int number = 0;
    int key = hash2(name);
    while (strcmp(hash_table[key].name, "") != 0)
    {
        hash_table[key].collision++;
        number++;
        key = (number * number + key)%TABLE_SIZE;
    }
    strcpy(hash_table[key].name, name);
}


void initialize_table()
{
    int i;
    for(i = 0; i < TABLE_SIZE; i++)
    {
        strcpy(hash_table[i].name, "");
        hash_table[i].collision = 0;
    }
}

int main()
{
    int collision1 = 0;
    int collision2 = 0;
    string line1;
    string line2;
    char get_name[NAME_SIZE];

    ifstream inputfile;

    initialize_table();
    inputfile.open("names.txt");

    while(getline(inputfile, line1))
    {
        int i;
        for (i=0; line1[i] != '\0'; i++)
            get_name[i] = line1[i];
        get_name[i] = '\0';
        hash_insert1(get_name);
    }

    cout << "Hash1 출력결과 : " << '\n';
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(strcmp(hash_table[i].name, "") == 0) 
            printf("table[%d] : %s %d \n", i, "EMPTY", hash_table[i].collision);
        else 
            printf("table[%d] : %s %d \n", i, hash_table[i].name, hash_table[i].collision);
        collision1 += hash_table[i].collision;
    }
    inputfile.close();


    initialize_table();
    inputfile.open("names.txt");
    while(getline(inputfile, line2))
    {
        int i;
        for (i=0; line2[i] != '\0'; i++)
            get_name[i] = line2[i];
        get_name[i] = '\0';
        hash_insert2(get_name);
    }
    
    cout << "Hash2 출력결과 : " << '\n';
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        
        if(strcmp(hash_table[i].name, "") == 0) 
            printf("table[%d] : %s %d \n", i, "EMPTY", hash_table[i].collision);
        else 
            printf("table[%d] : %s %d \n", i, hash_table[i].name, hash_table[i].collision);
        collision2 += hash_table[i].collision;
    }

    inputfile.close();
    cout << '\n';
    cout << "Total collision number in Hash1 " << collision1 << '\n';
    cout << "Total collision number in Hash2 " << collision2 << '\n';

    
    return 0;
}
