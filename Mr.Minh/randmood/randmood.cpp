#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "randmood"

using namespace std;

int n;
double p;

double binpow(double a, int k){
    if (k == 1) return a;
    double tg = binpow(a, k >> 1);
    if (k & 1) return tg * tg * a;
    return tg * tg;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n >> p;
    cout << fixed << setprecision(10) << (1 + binpow(1 - p * 2, n)) / 2;
}
