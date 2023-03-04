#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "savrsen"
const int maxn = 1e7 + 7;
using namespace std;

int L, R, p[maxn];
int f[maxn];
ll res;

void Erathosenes(int n){
    fi(i, 1, n) p[i] = i;
    fi(i, 2, sqrt(n)) if (p[i] == i){
        for (int j = i * i; j <= n; j += i){
            p[j] = i;
        }
    }
    f[1] = 1;
    fi(i, 2, n){
        int tmp = i;
        ll lt = p[i];
        while (tmp % p[i] == 0){
            lt *= p[i];
            tmp /= p[i];
        }
        f[i] = f[tmp] * ((lt - 1) / (p[i] - 1));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> L >> R;
    Erathosenes(R);
    fi(i, L, R) res += abs(f[i] - (i << 1));
    cout << res;
}
