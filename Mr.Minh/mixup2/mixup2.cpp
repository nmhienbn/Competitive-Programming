#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define getbit(x, i) (((x) >> (i)) & 1)
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "mixup2"
const int maxn = 16, N = 1 << 16;

using namespace std;

int n, k, a[maxn];
ll L[N][maxn], res;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> k;
    fi(i, 0, n-1) cin >> a[i];
    int m = (1 << n) - 1;
    fi(i, 0, n-1) L[1 << i][i] = 1;
    fi(x, 1, m){
        fi(i, 0, n-1) if (getbit(x, i)){
            fi(j, 0, n-1) if (!getbit(x, j) && abs(a[i]-a[j]) > k){
                L[x | (1 << j)][j] += L[x][i];
            }
        }
    }
    fi(i, 0, n-1){
        res += L[m][i];
    }
    cout << res;
}
