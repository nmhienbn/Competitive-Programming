#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "hash"
const int maxn = 15;
using namespace std;

int n, k, m, mod, kt, inv, tmp, d;
int f[(1 << 25) + 1], res;

void ql(int i, int now){
    if (i > kt){
        f[now]++;
        return;
    }
    fi(j, 1, 26){
        int nex = ((now * 33) ^ j) & mod;
        ql(i + 1, nex);
    }
}

void Euclidean(int a, int b, int& d, int& x, int& y){
    if (b == 0){
        x = 1; y = 0; d = a;
        return;
    }
    int x1, y1;
    Euclidean(b, a % b, d, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

void calc(int i, int now){
    if (i == kt){
        res += f[now];
        return;
    }
    fi(j, 1, 26){
        int nex = ((now ^ j) * inv) & mod;
        calc(i - 1, nex);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k >> m;
    mod = (1 << m) - 1;
    if (n > 5) kt = n / 2;
    else kt = n;
    ql(1, 0);
    if (n <= 5){
        cout << f[k];
        exit(0);
    }
    Euclidean(33, (1 << m), d, inv, tmp);
    calc(n, k);
    cout << res;
}
