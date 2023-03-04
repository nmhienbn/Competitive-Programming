#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "dgame"
const int maxn = 1e4+5;

using namespace std;

int a[3], m;
bool L[maxn], xd[maxn];

bool calc(int u){
    if (xd[u]) return L[u];
    xd[u] = 1;
    if (u < min({a[0], a[1], a[2]})) return L[u] = 0;
    fi(i, 0, 2) if (u == a[i]) return L[u] = 1;
    int best = 0;
    fi(i, 0, 2) if (u > a[i]) best = max(best, 1 - calc(u-a[i]));
    return (L[u] = best);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    fi(i, 0, 2) cin >> a[i];
    cin >> m;
    while (m--){
        int p;
        cin >> p;
        cout << calc(p) << '\n';
    }
}
