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

    void Score(int x, int y) {
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
};