#include <iostream>

using namespace std;

class BaseballBetting {
    public:
    int score_1, score_2, x, y;
    int bet_1 = 10000;
    int bet_2 = 10000;

    int getscore_1() { return score_1; }
    int getscore_2() { return score_2; }
    int getbet_1() { return bet_1; }
    int getbet_2() { return bet_2; }
    int getwin_1(int bet_1, int x, int y) { return bet_1 += y; }
    int getwin_2(int bet_2, int x, int y) { return bet_2 += x; }
    int getlose_1(int bet_1, int x, int y) { return bet_1 -= x; }
    int getlose_2(int bet_2, int x, int y) { return bet_2 -= y;}

    void setscore_1(int score_1) { this -> score_1 = score_1; }
    void setscore_2(int score_2) { this -> score_2 = score_2; }
    void setbet_1(int bet_1) { this -> bet_1 = bet_1; }
    void setbet_2(int bet_2) { this -> bet_2 = bet_2; }

    void Start() {
        cout << "*****************************************************************" << endl;
        cout << "*                                                               *" << endl;
        cout << "*                         야구 베팅 게임                        *" << endl;
        cout << "*                                                               *" << endl;
        cout << "*                         < 게임 규칙 >                         *" << endl;
        cout << "*                                                               *" << endl;
        cout << "*          1. 플레이어 2명 진행                                 *" << endl;
        cout << "*          2. 랜덤한 숫자 3개 맞추기                            *" << endl;
        cout << "*          3. 같은 자리, 같은 숫자 = strike                     *" << endl;
        cout << "*          4. 다른 자리, 같은 숫자 = ball                       *" << endl;
        cout << "*          5. strike = 3점, ball = 1점                          *" << endl;
        cout << "*          6. 숫자, 베팅 여부 및 베팅 금액 입력                 *" << endl;
        cout << "*          7. 더 높은 점수의 플레이어가 베팅 금액 획득          *" << endl;
        cout << "*          8. 점수 30점 또는 베팅 금액 소진 시 게임 종료        *" << endl;
        cout << "*                                                               *" << endl;
        cout << "*****************************************************************" << endl;
        cout << endl << endl;
    }

    void Score(int x, int y) {
        cout << endl;
        cout << "================== 점수 ===================" << endl;
        cout << "첫 번째 플레이어 : " << x << endl;
        cout << "두 번째 플레이어 : " << y << endl;
    }

    void Result() {
        cout << endl;
        cout << "================== 결과 ===================" << endl;
        cout << "================== 점수 ===================" << endl;
        cout << "첫 번째 플레이어 : " << score_1 << endl;
        cout << "두 번째 플레이어 : " << score_2 << endl;
        cout << "================== 금액 ===================" << endl;
        cout << "첫 번째 플레이어 : " << bet_1 << endl;
        cout << "두 번째 플레이어 : " << bet_2 << endl;
        cout << endl;
    }

        void Fianl() {
        cout << endl;
        cout << "================ 최종 결과 =================" << endl;
        cout << "================ 최종 점수 =================" << endl;
        cout << "첫 번째 플레이어 : " << score_1 << endl;
        cout << "두 번째 플레이어 : " << score_2 << endl;
        cout << "================ 최종 금액 =================" << endl;
        cout << "첫 번째 플레이어 : " << bet_1 << endl;
        cout << "두 번째 플레이어 : " << bet_2 << endl;
        cout << endl;
    }
};