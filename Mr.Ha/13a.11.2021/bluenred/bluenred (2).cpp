#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "bluenred"
const int maxn = 1005;
using namespace std;

struct dl {
    int u, v, w;
} a[maxn];

int n, res, S;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    fi(i, 1, n) fi(j, i+1, n) {

    }
}
