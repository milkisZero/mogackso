// #피보나치 #오퍼레이터 재정의 #점화식 행렬
// 행렬을 이용하여 점화식을 고속연산 할 수 있다.
// 점화식이 이전의 항 몇 개의 선형결합, 선형방정식의 꼴일 경우, O(m 3 log(n))
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> vec;
vec operator*(const vec &a, const vec &b) {
    // 벡터 크기 정의
    vec c(2, vector<long long>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            long long tmp = 0;
            for (int k = 0; k < 2; k++)
                tmp += a[i][k] * b[k][j];
            // 나머지만 연산
            c[i][j] = tmp % 1000000;
        }
    }
    return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    n--;

    vec base = {{1, 1}, {1, 0}};
    vec res = {{1, 0}, {0, 1}};

    while (n) {
        // 9 -> 4 4 1   a^4 = (a^2)^2 이므로 지수가 1이 나머지면 그 값은 이전 거듭제곱한 값
        // 4 1 -> 2 2 1
        // 2 1 -> 1 1 1
        // 1 1
        if (n % 2) {
            res = res * base;
            n--;
        }
        else {
            base = base * base;
            n /= 2;
        }
    }

    cout << res[0][0];

    return 0;
}