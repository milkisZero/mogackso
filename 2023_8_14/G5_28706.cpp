#include <iostream>
using namespace std;

int dp[200000][2];
int num[200000][2];
char op[200000][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> op[i][0];
            cin >> num[i][0];
            cin >> op[i][1];
            cin >> num[i][1];
        }

        return 0;
    }
}