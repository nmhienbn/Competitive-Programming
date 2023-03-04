#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "acm"
const int maxn = 10005, N = 1 << 11;

using namespace std;

void maximize(ll& a, ll b){
    if (a < b) a = b;
}

int n, a[maxn][15];
ll L[N], M[N], res;

void dynamic_bitmask(){
    int u = N - 1;
    fi(i, 0, u){
        fi(j, 1, n){
            ll sum = 0;
            fi(t, 0, 10){
                if (gb(i, t)) sum += a[j][t + 1];
            }
            maximize(L[i], sum);
        }
    }
    fi(i, 0, u){
        fi(j, i + 1, u){
            if ((i & j) == 0){
                maximize(M[i | j], L[i] + L[j]);
            }
        }
    }
    fi(i, 0, u){
        maximize(res, L[i] + M[u ^ i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) fi(j, 1, 11){
        cin >> a[i][j];
    }
    dynamic_bitmask();
    cout << res;
}
