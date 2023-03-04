#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "number"
const int maxn = 105;

using namespace std;

int n, b[maxn], c[maxn], cnt, pr[maxn];
ll res;
bool p[105];

void xuli(int i){
    ll ans = 1;
    //cout << i << ' ';
    fi(j, 1, i) ans *= b[j];
    if (ans > res){
        res = ans;
        cnt = i;
        fi(j, 1, i) c[j] = b[j];
        fi(j, 1, n) c[i + j] = 1, cnt++;
    }
}

void ql(int i){
    bool ok = 1;
    fi(j, pr[i-1] + 1, n) if (p[j]){
        ok = 0;
        pr[i] = j;
        int v = j;
        while (v <= n){
            b[i] = v;
            n -= v;
            ql(i+1);
            n += v;
            v *= j;
        }
    }
    if (ok) xuli(i - 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    p[1] = 0;
    p[2] = 1;
    fi(i, 3, n){
        p[i] = 1;
        for (int j = 2; j * j <= i; j++){
            if (i % j == 0){
                p[i] = 0;
                break;
            }
        }
    }

    ql(1);
    sort(c + 1, c + cnt + 1);
    cout << res << '\n';
    fi(i, 1, cnt) cout << c[i] << ' ';
}
