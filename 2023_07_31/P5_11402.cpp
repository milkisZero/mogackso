// #이항계수 #뤼카의 정리 #페르마 소정리
// nCr ≡ ∏k(i=0) niCri (mod p), O(logn/logp)이고 거의 상수시간이다
// n이 mod에 비해 클 때 & m이 소수일 때 사용한다
// mod! 만큼 팩토리얼 전처리, n<k일 경우 nCr = 0이다
// m으로 나눠주며 n%m C k%m를 누적곱한다.
#include <iostream>
using namespace std;
using ll = long long;

ll fact[2005];

ll nCr(ll fact, ll invFact, ll powN, ll mod) {
    while (powN) {
        if (powN % 2)
            fact = (fact * invFact) % mod;
        powN /= 2;
        invFact = (invFact * invFact) % mod;
    }
    return fact;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    ll n, k, m;
    cin >> n >> k >> m;

    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= m; i++) {
        fact[i] = (fact[i - 1] * i) % m;
    }

    ll res = 1;
    while (n || k) {
        if (n % m < k % m) {
            res = 0;
            break;
        }
        res *= nCr(fact[n % m], fact[k % m] * fact[(n % m) - (k % m)], m - 2, m) % m;
        res %= m;
        n /= m, k /= m;
    }

    cout << res;

    return 0;
}