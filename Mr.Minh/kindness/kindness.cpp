#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "kindness"
const int maxn = 1e5+5;

using namespace std;

int n, cnt[30];
ll res;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> s;
    n = s.size();
    fi(i, 0, n-1){
        int now = s[i] - 'a';
        fi(j, 0, 25) if (j != now){
            res += cnt[j];
        }
        cnt[now]++;
    }
    cout << res + 1;
}
