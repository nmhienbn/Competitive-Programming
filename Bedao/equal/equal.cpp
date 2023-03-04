#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "equal"
const int maxn = 1e6 + 5;
using namespace std;

int nt, a, b;
int p[maxn], f[maxn];

void Erathosenes(){
    fi(i, 2, 1000) if (!p[i]){
        for (int j = i * i; j <= 1000000; j += i){
            p[j] = i;
        }
    }
    fi(i, 2, 1000000){
        if (p[i]) f[i] = f[i / p[i]] + 1;
        else f[i] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    Erathosenes();
    cin >> nt;
    while (nt--){
        cin >> a >> b;
        cout << max(f[a], f[b]) - f[__gcd(a, b)] << '\n';
    }
}
