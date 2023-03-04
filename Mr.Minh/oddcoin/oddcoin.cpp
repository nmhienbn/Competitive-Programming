#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "oddcoin"
const int maxn = 1e6 + 5;

using namespace std;

int q, x, t, L[maxn];
int a[20];

void minimize(int& x, int y){
    if (x > y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> q;
    a[1] = 1, a[2] = 3, a[3] = 5;
    fi(i, 4, 15) a[i] = a[i - 3] * 10;
    fi(i, 1, min(t, maxn - 5)){
        L[i] = 1e9;
        fi(j, 1, 15) if (a[j] <= i){
            minimize(L[i], L[i - a[j]] + 1);
        }
    }
    while (q--){
        cin >> x >> t;
        fi(i, x, min(t, maxn - 5)){
            minimize(L[i], L[i - x] + 1);
        }
        if (t <= maxn - 5) cout << L[t] << '\n';
        else {
            int res = 1e9;
            int y = max(x, a[15]);
            int z = (t - maxn) / y;
            while (y * z <= t){
                z++;
                minimize(res, z + L[t - y * z]);
            }
            cout << res << '\n';
        }
    }

}
