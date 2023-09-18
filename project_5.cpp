#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;


int main() {
    cout << "프로젝트 5. 야구게임" << endl;

    srand((unsigned int)time(NULL));
    int c_baseBall[3];
    int u_baseBall[3];

    cout << "야구 게임" << endl;
    for(int i = 0; i < 3; i++) {
        int num = rand() % 9 + 1;
        c_baseBall[i] = num;
        for(int j = 0; j < i; j++) {
            if(c_baseBall[j]==num) {
                i--;
            }
        }
    }
    
    for(int i = 0; i < 3; i++) {
        cout << c_baseBall[i] << " ";
    }
    cout << endl;

    int strike = 0;
    int ball, count = 0;

    while(true) {
        cout << "1 ~ 9 사이의 숫자 3개를 입력하시오. (이외의 숫자 : 종료)" << endl;
        cin >> u_baseBall[0] >> u_baseBall[1] >> u_baseBall[2];

        if(u_baseBall[0] < 1 || u_baseBall[0] > 9 || u_baseBall[1] < 1 || u_baseBall[1] > 9 || u_baseBall[2] < 2 || u_baseBall[2] > 9) {
            break;
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(c_baseBall[i] == u_baseBall[j]) {
                    if(i == j) {
                        strike++;
                    }
                    else {
                        ball++;
                    }
                }
            }
        }
        count++;

        if(strike == 3) {
            cout << count << "번 만에 맞췄습니다." << endl;
            break;
        }
        else {
            cout << "Strike : " << strike << "    " << "Ball : " << ball << "    " << count << "회" << endl;
            strike = 0;
            ball = 0;
            continue;
        }



    }

    return 0;




}