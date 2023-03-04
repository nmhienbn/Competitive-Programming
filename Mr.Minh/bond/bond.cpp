#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define getbit(x, i) (((x) >> (i)) & 1)
#define Irelia "bond"
const int maxn = 20, N = 1 << 20;
using namespace std;

int n;
double L[N][maxn], a[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 0, n-1) fi(j, 0, n-1){
        int x;
        cin >> x;
        a[i][j] = double(x)/100;
    }
    fi(i, 0, n-1) L[1 << i][i] = a[0][i]*100;
    int m = (1 << n) - 1;
    fi(x, 1, m){
        int k = __builtin_popcount(x);
        fi(i, 0, n-1) if (getbit(x, i)){
            fi(j, 0, n-1) if (!getbit(x, j)){
                L[x | (1 << j)][j] = max(L[x | (1 << j)][j], L[x][i] * a[k][j]);
            }
        }
    }
    cout << fixed << setprecision(6) << *max_element(L[m], L[m]+n);
}
