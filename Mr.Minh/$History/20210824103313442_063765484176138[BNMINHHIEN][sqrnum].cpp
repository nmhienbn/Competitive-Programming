#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "sqrnum"
const int maxn = 1e7+5, mod = 1e9+7;

using namespace std;

int p[maxn], cnt[maxn];
ll a[maxn] = {0, 1, 1, 1};

void Erathosenes(){
    fi(i, 1, maxn-5) p[i] = i;
    int u = sqrt(maxn-5);
    fi(i, 2, u){
        for (int j = i*i; j <= maxn-5; j += i){
            p[j] = min(p[i], i);
        }
    }
}

void calc(){
    fi(i, 2, maxn-5){
        a[i] = a[i-1];
        int x = i, y = 1;
        while (x > 1){
            ll v = p[x];
            if (cnt[v]){
                a[i] = (a[i] * (v*v % mod)) % mod;
                y *= v*v;
            }
            cnt[v] = 1 - cnt[v];
            x /= v;
        }
        //cout << i << ' ' << y << '\n';
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    Erathosenes();
    calc();
    int n;
    cin >> n;
    while (cin >> n){
        cout << a[n] << '\n';
    }
}
