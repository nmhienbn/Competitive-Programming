#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fibval"
using namespace std;

int f[] = {1, 1, 2, 3, 5, 1, 6, 0, 6, 6, 5, 4, 2, 6, 1, 0};
int nt, u, v;

int solve(const int& l, const int& r){
    int k = (r - l + 1) / 16;
    if (k >= 2){
        return k * 16;
    }
    fi(i, l, r - 1) if (f[i % 16] == f[(i + 1) % 16]) return 2;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> u >> v;
        cout << solve(u, v) << '\n';
    }
}
