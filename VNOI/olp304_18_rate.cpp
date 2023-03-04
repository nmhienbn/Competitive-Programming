#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "olp304_18_rate"
const int maxn = 3e5 + 5;
using namespace std;

int n, k;
int a[maxn];
double b[maxn];

bool check(double g){
    double minb = 0;
    fi(i, 1, n) b[i] = b[i - 1] + a[i] - g;
    fi(i, k, n){
        minb = min(minb, b[i - k]);
        if (b[i] >= minb - 1e-7) return true;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    double d = 0, c = 1e6;
    while (c - d > 1e-7){
        double g = (d + c) / 2;
        if (check(g)) d = g;
        else c = g;
    }
    cout << fixed << setprecision(6) << c << endl;
}
