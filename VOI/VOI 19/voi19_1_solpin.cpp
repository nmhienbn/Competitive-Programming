#include <bits/stdc++.h>
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
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            a[i + m][j] = a[i][j + n] = a[i + m][j + n] = a[i][j];
        }
    }
    for(int i = 1; i <= m * 2; i++){
        for(int j = 1; j <= n * 2; j++){
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
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
