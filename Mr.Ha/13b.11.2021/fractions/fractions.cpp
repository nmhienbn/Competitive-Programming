#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "fractions"
const int maxn = 1e6+5;

using namespace std;

int n, a[maxn], phi[maxn];
ll f[maxn];

void Euler(){
    int m = sqrt(n);
    fi(i, 1, n) a[i] = i;
    fi(i, 2, m) if (a[i] == i){
        for (int j = i*i; j <= n; j += i){
            a[j] = i;
        }
    }
    f[1] = phi[1] = 1;
    fi(i, 2, n){
        int p = a[i], u = i/p, cnt = 1;
        while (u % p == 0){
            cnt *= p;
            u /= p;
        }
        phi[i] = phi[u]*cnt*(p-1);
        f[i] = f[i-1] + phi[i];
    }
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    Euler();
    cout << f[n];

}
