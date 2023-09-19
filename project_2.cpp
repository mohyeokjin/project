#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int main(void) {
    clock_t startTime = clock();
    cout << "프로젝트 2. 타임어택 끝말잇기 게임" << endl;

    string word = "apple";
    string next_word = "apple";
    double count_time = 0;
    int count = 0;
    int count_check;


    while(count_time <= 30) {
        int s = word.size();
        cout << word << endl;
        cout << "다음 단어를 입력하세요. : ";
        cin >> next_word;

        if(word[s-1] == next_word[0]) {
            if(word.find(next_word) == string::npos) {
                word += " -> " + next_word;
                count++;
            }
            else {
                cout << "중복된 단어입니다." << endl;
            }
        }
        else {
            cout << "잘못된 입력입니다." << endl;
        }

        clock_t endTime = clock();
        count_time = (double)(endTime - startTime) / 100.0f; // CLOCKS_PER_SEC로 나누면 너무 적은 수가 나옴

        cout << endl << "걸린 시간 : " << count_time << endl;

        if(count_time > 30) {

            cout << "타임 오버!" << endl << "총 입력한 단어 개수 : " << count << endl;
            break;
        }
    }




}