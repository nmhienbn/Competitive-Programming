#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "areadif"
const int maxn = 310;

using namespace std;

int m, n, a[maxn][maxn], sum, res = 1e9;

bool b[maxn][maxn];
void dfs(int i, int j){
    b[i][j] = 1;
    if (i == m+1){
        res = min(res, abs(m*n - sum*2));
        b[i][j] = 0;
        return;
    }
    if (a[i][j] != a[i+1][j] && j <= n && !b[i][j+1]) dfs(i, j+1);
    if (a[i][j-1] != a[i+1][j-1] && j > 1 && !b[i][j-1]) dfs(i, j-1);
    if (a[i][j] != a[i][j-1]){
        sum += j-1;
        dfs(i+1, j);
        sum -= j-1;
    }
    b[i][j] = 0;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            char c;
            cin >> c;
            a[i][j] = c - 'A' + 1;
        }
    }
    fi(i, 1, n+1){
        dfs(1, i);
    }
    cout << res;
}
