#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "tires"
const int maxn = 1e5 + 5, N = 1e5;
using namespace std;

int n, a[maxn], phi[maxn], x;
ll res;
bool cl[maxn];

void Euler(int n){
    int m = sqrt(n);
    fi(i, 1, n) a[i] = i;
    fi(i, 2, m) if (a[i] == i){
        for (int j = i*i; j <= n; j += i){
            a[j] = i;
        }
    }
    phi[1] = 1;
    fi(i, 2, n){
        int p = a[i], u = i / p, cnt = 1;
        while (u % p == 0){
            cnt *= p;
            u /= p;
        }
        phi[i] = phi[u] * cnt * (p-1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    Euler(N);
    cin >> n;
    fi(i, 1, n + 1) cin >> x, cl[x] = 1;
    fi(i, 2, N){
        for (int j = i; j <= N; j += i){
            if (cl[j]){
                res += phi[i];
                break;
            }
        }
    }
    cout << res;
}
