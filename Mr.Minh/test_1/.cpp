#include <bits/stdc++.h>
using namespace std;

int n = 1e5, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    m = n;
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) cout << n << ' ';
    cout << '\n';
    for (int i = 1; i <= m; i++){
        cout << 2 << ' ' << n << ' ' << n << ' ' << 1 << '\n';
    }
}
