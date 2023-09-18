#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;


int main() {
    cout << "프로젝트 3. 랜덤 숫자 맞추기" << endl;

    srand((unsigned int)time(NULL));

    int c_numbers[6];
    int u_numbers[6];
    int u_num;
    int count = 0;

    for(int i = 0; i < 6; i++) {
        int num = rand() % 25 + 1;
        c_numbers[i] = num;
        for(int j = 0; j < i; j++) {
            if(c_numbers[j] == num) {
                i--;
            }
        }
    }
    cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다. " << endl;
    for(int i = 0; i < 6; i++) {
        cout << i+1 << "번째 번호를 입력하세요. : ";
        cin >> u_num;
        u_numbers[i] = u_num;
        for(int j = 0; j < i; j++) {
            if(u_numbers[j] == u_num) {
                i--;
                cout << "이미 입력된 숫자입니다. 다시 입력해주세요. " << endl;
            }
            else if(u_numbers[j] < 0 || u_numbers[j] > 25) {
                cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다. 다시 입력해주세요. " << endl;
            }
        }
    }

    cout << "당첨번호 공개!" << endl;
    for(int i = 0; i < 6; i++) {
        cout << c_numbers[i] << "  ";
        for(int j = 0; j < i; j++) {
            if(c_numbers[i] == u_numbers[j]) {
                count++;
            }
        }
        cout << endl;
    }

    cout << "1 ~ 7등까지 결과가 나올 수 있습니다. " << endl << "결과 : ";
    if(count == 6) {
        cout << "1등입니다!";
    }
    else if(count == 5) {
        cout << "2등입니다!";
    }
    else if(count == 4) {
        cout << "3등입니다!";
    }
    else if(count == 3) {
        cout << "4등입니다!";
    }
    else if(count == 2) {
        cout << "5등입니다!";
    }
    else if(count == 1) {
        cout << "6등입니다!";
    }
    else if(count == 0) {
        cout << "7등입니다!";
    }

}