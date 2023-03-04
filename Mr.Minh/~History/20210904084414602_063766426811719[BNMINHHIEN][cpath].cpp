#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "cpath"
const int maxn = 55, mod = 2017;

using namespace std;

struct matrix {
    ll a[maxn][maxn];
    friend matrix operator * (matrix a, matrix b){
        matrix c;
        fi(i, 1, 50){
            fi(j, 1, 50){
                c.a[i][j] = 0;
                fi(k, 1, 50){
                    c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        return c;
    }
    friend matrix binpow(matrix a, int k){
        if (k == 1) return a;
        matrix tg = binpow(a, k/2);
        if (k & 1) return tg*tg*a;
        return tg*tg;
    }
} A, res;

int n, m, k;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m >> k;
    if (k == 0){
        cout << 0;
        exit(0);
    }
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        A.a[u][v]++;
    }
    res = binpow(A, k);
    cout << res.a[1][n];
}
