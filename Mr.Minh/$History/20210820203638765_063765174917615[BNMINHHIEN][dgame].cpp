#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "dgame"
const int maxn = 4005;

using namespace std;

int r, b, g, m;
bool L[maxn], xd[maxn];

bool calc(int u){
    if (xd[u]) return L[u];
    if (u == r || u == b || u == g) return 1;
    int best = 1 - min({calc(u-r), calc(u-b), calc(u-g)});
    xd[u] = 1;
    return (L[u] = best);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> r >> b >> g >> m;
    while (m--){
        int p;
        cin >> p;
        cout << calc(p) << '\n';
    }
}
