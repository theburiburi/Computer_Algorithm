#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// 1번째와 2번째 단어를 저장할 해시 테이블
unordered_map<string, string> firstSecondWordTable;

// 1번째와 2번째 문장을 키로 하고 3번째 문장을 값으로 저장할 해시 테이블
unordered_map<string, string> twoSentencesTable;

// 파일에서 1번째와 2번째 단어를 읽어서 해시 테이블에 저장하는 함수
void buildFirstSecondWordTable(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "파일을 열 수 없습니다." << endl;
        exit(EXIT_FAILURE);
    }

    string firstWord, secondWord, thirdWord;
    while (file >> firstWord >> secondWord >> thirdWord) {
        firstSecondWordTable[firstWord + " " + secondWord] = thirdWord;
    }

    file.close();
}

// 1번째와 2번째 문장을 키로 하고 3번째 문장을 값으로 저장하는 함수
void buildTwoSentencesTable() {
    for (const auto& entry : firstSecondWordTable) {
        string key = entry.first;
        string thirdWord = entry.second;
        twoSentencesTable[key] = thirdWord;
    }
}

// 무작위로 문장을 생성하는 함수
string generateSentence() {
    string sentence;
    string currentKey;

    // 시작 키 선택
    auto it = firstSecondWordTable.begin();
    advance(it, rand() % firstSecondWordTable.size());
    currentKey = it->first;

    // 문장 생성
    sentence = currentKey + " " + twoSentencesTable[currentKey];

    return sentence;
}

int main() {
    // 텍스트 파일에서 1번째와 2번째 단어를 읽어서 해시 테이블에 저장
    string filename = "war_peace_plain-1.txt";
    buildFirstSecondWordTable(filename);

    // 1번째와 2번째 문장을 키로 하고 3번째 문장을 값으로 저장
    buildTwoSentencesTable();

    // 예시: 문장 생성 및 출력
    while (true) {
        cout << "1. 문장 출력\t2. 종료" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            string sentence = generateSentence();
            cout << sentence << endl << endl;
        }
        else if (choice == 2) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "올바른 선택이 아닙니다. 다시 선택하세요." << endl;
        }
    }

    return 0;
}