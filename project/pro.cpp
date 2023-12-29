#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
//#include <iterator>
//#include <cstdlib>
#include <ctime>

#define SIZE 500 //firstHash 사이즈크기 지정

using namespace std;
int size;

int hashKey(string word);
void buildHash(const vector<string>& sentences, unordered_map<string, string>& firstHash, unordered_map<string, vector<string>>& secondHash);
vector<string> senToWord(const string& sentence);
void generateSen(const unordered_map<int, string> &firstHash, const unordered_map<string, vector<string>> &secondHash);


int hashKey(string word) // 단어를 key값으로 변경하는 함수입니다.
{
    int key = 0;
    for(char c : word)
    {
        key += c*c + c;
    }
    key %= SIZE;
    return key;
}

void buildHash(const vector<string>& sentences, unordered_map<int, string>& firstHash, unordered_map<string, vector<string>>& secondHash)
{

    for (const string& sentence : sentences) {
        vector<string> words = senToWord(sentence); 

        if (!(words.size() < 3))
        {
            for (size_t i = 0; i < words.size() - 2; i++)
            {
                
                string key = words[i] + " " + words[i + 1];
                if (i == 0)
                    firstHash[hashKey(key)] = key;
                secondHash[key].push_back(words[i + 2]);
            }
        }
    }
}





void generateSen(const unordered_map<int, string>& firstHash, const unordered_map<string, vector<string>>& secondHash) 
{
    
    int index = rand() % SIZE; // 첫 번째 해쉬에서 랜덤하게 두 개의 단어를 가져옵니다.
    vector<string> words = senToWord(firstHash.at(index)); // 두 개의 단어를 벡터로 넣어줍니다.
    while(words.size() < 1)
    {
        int index = rand() % SIZE;
        vector<string> words = senToWord(firstHash.at(index));
    }

    string word1 = words[0];
    string word2 = words[1];
    size_t nextWord = 0;

    cout << word1 << " " << word2;
    while (true)
    {
        string key = word1 + " " + word2;
        
        auto it = secondHash.find(key);
        if (it->second.empty() || it == secondHash.end())
            break;

        string word3 = it->second[nextWord++];

        cout << word3 << " ";

        word1 = word2; 
        word2 = word3; 
    }
}


vector<string> senToWord(const string& sentence) 
{
    istringstream file(sentence);
    vector<string> wordVector;
    string word;

    while(file >> word)
        wordVector.push_back(word);

    return wordVector;
}

int size;
int main() {
    int size = 0;
    unordered_map<int, string> firstHash;
    unordered_map<string, vector<string>> secondHash;

    ifstream file("war_peace_plain.txt"); 
    vector<string> sentences;

    string line;
    while (getline(file, line))
        sentences.push_back(line);

    buildHash(sentences, firstHash, secondHash);

    int selection = 0;
    while (true) 
    {
        cout << "Choose options below.\n"<< "1) Generate a sentence.\n" << "2) Finish.\n";
        cin >> selection;
        cout << endl;

        if (selection == 1) 
            generateSen(firstHash, secondHash);

        else if (selection == 2) 
        {
            cout << "Thank you!" << endl;
            break;
        }
        else 
            cout << "Please try again" << endl;
    }
    return 0;
}
