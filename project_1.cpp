#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main() {
    int num;
    int basken = 0;
    int s[31];
    bool turn = false;

    srand((unsigned int)time(NULL));

    cout << "프로젝트 1. 배스킨라빈스 31 게임" << endl;

    for (int i = 0; i < 31; i++) {
        s[i] = i+1;
    }

    while (basken < 32) {
        cout << "개수를 입력하세요. : ";
        cin >> num;
        if(num < 4 && num > 0 && turn == false) {
            cout << "사용자가 부른 숫자!" << endl;
            for (int j = 0; j < num; j++) {
                cout << s[basken + j] << endl;
                if(s[basken + j] == 31) {
                    cout << "게임 종료! 컴퓨터의 승리입니다." << endl;
                    break;
                }
            }
            basken = num + basken;
            turn = true;
        }
        else {
            cout << "1~3 사이의 숫자를 입력하세요." << endl;
        }

        if(turn == true) {
            int c_num = rand() % 3 + 1;
            cout << "컴퓨터가 부른 숫자!" << endl;
            for (int x = 0; x < c_num; x++) {
                cout << s[basken + x] << endl;
                if(s[basken + x] == 31) {
                    cout << "게임 종료! 사용자의 승리입니다." << endl;
                    break;
                }
            }
            basken = c_num + basken;
            turn = false;
        }
    }





}