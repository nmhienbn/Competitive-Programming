#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define getbit(x, i) (x>>i)&1
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "acm"
const int maxn = 1e4+5;

using namespace std;

int n, a[maxn][20];
ll L[1 << 11], M[1 << 11];
ll res;

void sub1(){
    fi(i, 1, n){
        fi(j, i, n){
            fi(k, j, n){
                ll sum = 0;
                fi(t, 1, 11){
                    sum += max({a[i][t], a[j][t], a[k][t]});
                }
                res = max(res, sum);
            }
        }
    }
}

void sub2(){
    fi(i, 0, (1 << 11) - 1){
        fi(j, 1, n){
            ll sum = 0;
            fi(t, 0, 10){
                if (getbit(i, t)) sum += a[j][t+1];
            }
            L[i] = max(sum, L[i]);
        }
    }
    fi(i, 0, (1 << 11) - 1){
        fi(j, i+1, (1 << 11) - 1){
            if ((i&j) == 0){
                M[i|j] = max(M[i|j], L[i] + L[j]);
            }
        }
    }
    int u = (1 << 11) - 1;
    fi(i, 0, u){
        res = max(res, L[i] + M[u^i]);
    }
    res = T[(1 << 11) - 1];
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        fi(j, 1, 11){
            cin >> a[i][j];
        }
    }
    if (n <= 100){
        sub1();
    }
    else {
        sub2();
    }
    cout << res;
}
