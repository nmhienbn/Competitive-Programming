#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "baba"
const int maxn = 1e6 + 5, mod = 33;
using namespace std;

int n, sub, id, now;
int cnt[mod];
ll res;
int a[maxn], b[maxn], f[maxn];
string s;

int get(int l, int r){
    return (a[r] - a[l - 1] * b[r - l + 1] + 1089) % mod;
}

int calc(int i, int j){
    int d = 0, c = res - 1;
    while (d <= c){
        int g = (d + c) >> 1;
        if (get(i, i + g - 1) == get(j, j + g - 1)) d = g + 1;
        else c = g - 1;
    }
    if (s[i + d] > s[j + d]) return i;
    return j;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> sub;
    n = s.size();
    s = ' ' + s;
    b[0] = 1;
    fi(i, 1, n){
        a[i] = (a[i - 1] * 10 + s[i] - '0') % mod;
        b[i] = (b[i - 1] * 10) % mod;
    }
    fi(i, 1, n){
        f[i] = a[i] * b[n - i] % mod;
    }
    if (sub == 1){
        fi(i, 1, n){
            cnt[f[i]]++;
        }
        cnt[0]++;
        fi(i, 0, 32) res += 1ll * cnt[i] * (cnt[i] - 1) / 2;
        cout << res;
    }
    else {
        res = -1;
        fi(i, 1, n){
            if (!cnt[f[i]] && f[i]) cnt[f[i]] = i;
            int tmp = i - cnt[f[i]];
            if (res < tmp){
                res = tmp;
                id = cnt[f[i]];
            }
            else if (res == tmp){
                id = calc(id, cnt[f[i]]);
            }
        }
        if (~res) fi(i, id + 1, id + res) cout << s[i];
        else cout << -1;
    }
}
