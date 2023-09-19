#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;

    cout << "프로젝트 4. 마방진 만들기" << endl;
    cout << "마방진의 행 혹은 열의 수를 자연수로 입력해주세요. (홀수) : ";
    cin >> n;

    vector<vector<int>> S(n, vector<int>(n,0));

    int x = 0;
    int y = n/2;

    S[x][y] = 1;

    for(int i = 2; i <= n * n; i++) {
        x--;
        y++;
        
        if(x < 0) x = n - 1;
        if(y >= n) y -= n;
        if(S[x][y] != 0) x++;

        S[x][y] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << S[i][j] << "  ";
        }
        cout << endl;
    }




/*     int arr[50][50]{0};
    int n;
    int z = 1;
    int count = 0;

    cout << "마방진의 행 혹은 열의 수를 자연수로 입력해주세요. (홀수)";
    cin >> n;

    int x = 0;
    int y = n/2;

    for(int i = 0; i < n * n; i++) {
        count++;

        if(x < 0) x += n;
        if(y >= n) y -= n;
        arr[x][y] = count;

        if(count%n==0) {
            x++;
            continue;
        }
        x--;
        y++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    return 0; */




}