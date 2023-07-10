#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string a = "", b = "";
    int idx = 0;
    a.append(s.begin(), s.begin() + n / 2);
    b.append(s.begin() + n / 2, s.end());
    int cnt = 0;
    string res = a;
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != b[idx]) {
            i--;
            cnt++;
            if (cnt > 1)
                break;
        }
        idx++;
    }

    string c = "", d = "";
    idx = 0;
    d.append(s.begin(), s.begin() + n / 2 + 1);
    c.append(s.begin() + n / 2 + 1, s.end());
    int cnt2 = 0;
    string res2 = c;
    for (int i = 0; i < n / 2; i++) {
        if (c[i] != d[idx]) {
            i--;
            cnt2++;
            if (cnt2 > 1)
                break;
        }
        idx++;
    }

    if (n % 2 == 0)
        cout << "NOT POSSIBLE" << '\n';
    else if ((cnt <= 1 && cnt2 > 1))
        cout << res << '\n';
    else if (cnt2 <= 1 && cnt > 1)
        cout << res2 << '\n';
    else if ((cnt > 1 || cnt2 > 1))
        cout << "NOT POSSIBLE" << '\n';
    else {
        if (!res.compare(res2))
            cout << res << '\n';
        else
            cout << "NOT UNIQUE" << '\n';
    }

    return 0;
}