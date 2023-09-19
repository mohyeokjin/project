#include <iostream>
#include <string>

using namespace std;

class Calculator {
    protected:
    int a, b;
    string u_cal;
    virtual double calc(int a, int b) = 0;

    public:
    void cal() {
        cout << "------------------------------" << endl << "결과 : " << calc(a, b) << endl << "------------------------------" << endl;
    }

};

class Add : public Calculator {
    public:
    double calc(int a, int b) {
        return a + b;
    }
};

class Sub : public Calculator {
    public:
    double calc(int a, int b) {
        return a - b;
    }
};

class Mul : public Calculator {
    public:
    double calc(int a, int b) {
        return a * b;
    }
};

class Div : public Calculator {
    public:
    string warning() {
        return "0은 계산할 수 없습니다.";
    }

    double calc(int a, int b) {
        if (b == 0) warning();
        else return a / b;
    }
};


int main() {
    int num_a, num_b, result;
    string u_cal, run;

    Add add;
    Sub sub;
    Mul mul;
    Div div;

    cout << "숫자를 입력해주세요. : ";
    cin >> num_a;
    cout << "연산자를 입력해주세요. : ";
    cin >> u_cal;
    cout << "숫자를 입력해주세요. : ";
    cin >> num_b;

    while(1) {

        if(u_cal == "+") {
            cout << "------------------------------" << endl << "결과 : " << add.calc(num_a, num_b) << endl << "------------------------------" << endl;
            result = num_a + num_b;
        }
        if(u_cal == "-") {
            cout << "------------------------------" << endl << "결과 : " << sub.calc(num_a, num_b) << endl << "------------------------------" << endl;
            result = num_a - num_b;
        }
        if(u_cal == "*") {
            cout << "------------------------------" << endl << "결과 : " << mul.calc(num_a, num_b) << endl << "------------------------------" << endl;
            result = num_a * num_b;
        }
        if(u_cal == "/") {
            cout << "------------------------------" << endl << "결과 : " << div.calc(num_a, num_b) << endl << "------------------------------" << endl;
            result = num_a / num_b;
        }

        cout << "연산을 계속 진행하시겠습니까? (Y : 계속, AC : 초기화, EXIT : 종료) ";
        cin >> run;

        if(run == "Y") {
            cout << "연산자를 입력해주세요. : ";
            cin >> u_cal;
            cout << "숫자를 입력해주세요. : ";
            cin >> num_b;
            num_a = result;
        }
        if(run == "AC") {
            cout << "숫자를 입력해주세요. : ";
            cin >> num_a;
            cout << "연산자를 입력해주세요. : ";
            cin >> u_cal;
            cout << "숫자를 입력해주세요. : ";
            cin >> num_b;
        }
        if(run == "EXIT") break;


    }
}