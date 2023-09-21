#include <iostream>
#include <random>
#include <ctime>
#include "BaseballBetting.h"

using namespace std;

int main() {
    cout << "프로젝트. 야구 배팅 게임" << endl;

    srand((unsigned int)time(NULL));
    BaseballBetting game;
    int c_baseBall[3];
    int u_baseBall[3];
    int u1_baseBall[3];
    int strike = 0;
    int strike_1 = 0;
    int ball = 0;
    int count = 0;
    int ball_1 = 0;
    int count_1 = 0;
    int score_1 = 0;
    int score_2 = 0;
    int a, b, x, y; // 각 플레이어 점수, 베팅 여부, 베팅 금액
    int score_s = 3; // strike 점수
    int score_b = 1; // ball 점수

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

    while(true) {
        cout << "첫 번째 플레이어 : 1 ~ 9 사이의 숫자 3개를 입력해주세요. ";
        cin >> u_baseBall[0] >> u_baseBall[1] >> u_baseBall[2];

        cout << "두 번째 플레이어 : 1 ~ 9 사이의 숫자 3개를 입력해주세요. ";
        cin >> u1_baseBall[0] >> u1_baseBall[1] >> u1_baseBall[2];

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

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(c_baseBall[i] == u1_baseBall[j]) {
                    if(i == j) {
                        strike_1++;
                    }
                    else {
                        ball_1++;
                    }
                }
            }
        }

        score_1 = (strike * score_s) + (ball * score_b);
        score_2 = (strike_1 * score_s) + (ball_1 * score_b);

        game.setscore_1(game.getscore_1()+score_1);
        game.setscore_2(game.getscore_2()+score_2);

        cout << "베팅하시겠습니까? (1 : 수락, 2 : 거절) ";
        cin >> a >> b;

        if(a == 1 && b == 1) { // 플레이어 두 명 모두 동의해야 베팅 진행
            cout << "첫 번째 플레이어 : 베팅할 금액을 입력해주세요. (베팅 가능 금액 : " << game.getbet_1() << ") : ";
            cin >> x;
            if(x > game.getbet_1()) {
                cout << "베팅 가능 금액을 초과하였습니다. 다시 입력해주세요. " << endl;
                cin >> x;
            }
            cout << "두 번째 플레이어 : 베팅할 금액을 입력해주세요. (베팅 가능 금액 : " << game.getbet_2() << ") : ";
            cin >> y;
            if(y > game.getbet_1()) {
                cout << "베팅 가능 금액을 초과하였습니다. 다시 입력해주세요. " << endl;
                cin >> y;
            }
            
            game.Score(score_1, score_2); // 베팅 후 점수 공개 및 결과 발표

            if(score_1 > score_2) {
                cout << endl << "첫 번째 플레이어 승리!" << endl;
                game.setbet_1(game.getwin_1(game.getbet_1(), x, y));
                game.setbet_2(game.getlose_2(game.getbet_2(), x, y));
                game.Result();
            }
            else if(score_1 < score_2) {
                cout << endl << "두 번째 플레이어 승리!" << endl;
                game.setbet_1(game.getlose_1(game.getbet_1(), x, y));
                game.setbet_2(game.getwin_2(game.getbet_2(), x, y));
                game.Result();
            }
            else if(score_1 == score_2) {
                cout << endl << "무승부입니다!" << endl << endl;
                game.Result();
            }
        }
        else { // 베팅 거절 시 그대로 진행
            game.Result();
            continue;
        }

        if(game.getscore_1() >= 30 && game.getscore_2() >= 30) { // 총 획득한 점수 동일할 때 남아있는 베팅 금액 기준 승부 판정
            if(game.getbet_1() == game.getbet_2()) {
                cout << "================== 결과 ===================" << endl;
                cout << "무승부입니다!" << endl;
                break;
            }
            else if(game.getbet_1() > game.getbet_2()) {
                cout << "================== 결과 ===================" << endl << endl;
                cout << "첫 번째 플레이어 승리!" << endl;
                game.Result();
                break;
            }
            else if(game.getbet_1() < game.getbet_2()) {
                cout << "================== 결과 ===================" << endl << endl;
                cout << "두 번째 플레이어 승리!" << endl;
                game.Result();
                break;
            }
        }
        else if(game.getscore_1() >= 30 || game.getscore_2() >= 30 || game.getbet_1() == 0 || game.getbet_2() == 0) { // 획득한 점수 기준 또는 베팅 금액 모두 소진 시
            if(game.getscore_1() > game.getscore_2() || game.getbet_1() > game.getbet_2()) {
                cout << "===========================================" << endl << endl;
                cout << "첫 번째 플레이어가 최종 승리하였습니다." << endl;
                game.Result();
                break;
            }
            else if(game.getscore_1() < game.getscore_2() || game.getbet_1() < game.getbet_2()) {
                cout << "===========================================" << endl << endl;
                cout << "두 번째 플레이어가 최종 승리하였습니다." << endl;
                game.Result();
                break;
            }
        }
        // 점수 초기화
        strike = 0;
        ball = 0;
        strike_1 = 0;
        ball_1 = 0;
        score_1 = 0;
        score_2 = 0;
        continue;
    }

}