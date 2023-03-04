#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "pie"
const int maxn = 1e3 + 5;
using namespace std;

int n, in[maxn], res;
bool kt[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int l, r;
        cin >> l >> r;
        in[l]--;
        in[r]++;
        kt[l][r] = 1;
        if (kt[r][l]) res++;
    }
    fi(i, 1, 1000) if (in[i] > 0) n += in[i];
    cout << n + res;
}
