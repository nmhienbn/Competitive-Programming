#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Max(x, y) x = x > y ? x : y
#define getbit(x, i) (((x) >> (i)) & 1)
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "atcoder_dp_u"
const int maxn = 16, N = 1 << 16;

using namespace std;

int n;
ll a[maxn][maxn], b[N], L[N];

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 0, n-1) fi(j, 0, n-1) cin >> a[i][j];
    int m = (1 << n) - 1;
    fi(x, 3, m){
        fi(i, 0, n-1){
            fi(j, i+1, n-1){
                if (getbit(x, i) && getbit(x, j)){
                    b[x] += a[i][j];
                }
            }
        }
    }
    fi(i, 0, m){
        int j = m^i;
        for (int k = m^i; k > 0; k = (k-1) & j){
            Max(L[i^k], L[i] + b[k]);
        }
    }
    cout << L[m];
}
