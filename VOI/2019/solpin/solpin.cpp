#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "solpin"
const int maxn = 1005;
using namespace std;

int m, n, q;
int a[maxn][maxn];
int x, y;

void add(int& x, int& y, int &m){
    x = (x + y) % m;
}

int get(int i, int j, int u, int v){
    return a[j][v] + a[i - 1][u - 1] - a[j][u - 1] - a[i - 1][v];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        a[i + m][j] = a[i][j + n] = a[i + m][j + n] = a[i][j];
    }
    fi(i, 1, m * 2) fi(j, 1, n * 2){
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
    cin >> q;
    while (q--){
        int typ;
        cin >> typ;
        if (!typ){
            int u, v;
            cin >> u >> v;
            add(x, v, m);
            add(y, u, n);
        }
        else {
            int u, v, s, t;
            cin >> u >> v >> s >> t;
            cout << get(u + x, s + x, v + y, t + y) << '\n';
        }
    }
}
