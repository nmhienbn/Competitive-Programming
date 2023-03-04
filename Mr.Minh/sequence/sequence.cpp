#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "sequence"
const int maxn = 1e5+5;
using namespace std;

int n, a[maxn], k;
ll b[maxn], minb[maxn];

bool check(int g){
    minb[0] = b[0] = a[0] - g;
    fi(i, 1, n){
        b[i] = b[i-1] + a[i] - g;
        minb[i] = min(b[i], minb[i-1]);
    }
    int l = k/g + (k%g != 0);
    fi(i, l, n){
        if (b[i] >= minb[i-l]) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    int d = 1, c = 1e9;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    cout << c;
}
