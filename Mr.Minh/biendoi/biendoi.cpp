#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "biendoi"
const int maxn = 1005;

using namespace std;

int a[105][105][105], m, n, q;
int b[maxn][maxn];

void sub1(){
    fi(t, 1, q){
        int typ, i, j, res = 0;
        cin >> typ;
        if (typ <= 3) fi(i, 1, m){
            fi(j, 1, n){
                a[i][j][t] = a[i][j][t-1];
            }
        }
        if (typ == 1){
            cin >> i >> j;
            a[i][j][t] = 1;
        }
        else if (typ == 2){
            cin >> i >> j;
            a[i][j][t] = 0;
        }
        else if (typ == 3){
            cin >> i;
            fi(j, 1, n){
                a[i][j][t] = 1 - a[i][j][t];
            }
        }
        else if (typ == 4){
            int k;
            cin >> k;
            fi(i, 1, m){
                fi(j, 1, n){
                    a[i][j][t] = a[i][j][k];
                }
            }
        }
        fi(i, 1, m){
            fi(j, 1, n){
                res += (a[i][j][t] == 1);
            }
        }
        cout << res << '\n';
    }
}

void sub2(){
    ll res = 0;
    while (q--){
        int typ, i, j;
        cin >> typ;
        if (typ == 1){
            cin >> i >> j;
            if (b[i][j] == 0){
                b[i][j] = 1;
                res++;
            }
        }
        else if (typ == 2){
            cin >> i >> j;
            if (b[i][j] == 1){
                b[i][j] = 0;
                res--;
            }
        }
        else if (typ == 3){
            cin >> i;
            fi(j, 1, n){
                b[i][j] = 1 - b[i][j];
                if (b[i][j] == 1) res++;
                else res--;
            }
        }
        cout << res << '\n';
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n >> q;
    if (max({n, m, q}) <= 100){
        sub1();
    }
    else {
        sub2();
    }
}
