#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "looksay"
const int maxn = 0;
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        cin >> s;
        int pre = s[0] - '0', cnt = 0;
        for (auto c : s){
            int now = c - '0';
            if (now == pre) cnt++;
            else {
                cout << cnt << pre;
                cnt = 1;
            }
            pre = now;
        }
        cout << cnt << pre;
        cout << '\n';
    }

}
