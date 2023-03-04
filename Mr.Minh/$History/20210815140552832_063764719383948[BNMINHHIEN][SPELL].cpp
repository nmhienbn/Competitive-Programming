#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define fir first
#define se second
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "SPELL"
const int maxn = 305;

using namespace std;

int m, n, k, res = 1e9, L[maxn][maxn][maxn];
char s[maxn];
vector<pii> g[30];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, k) cin >> s[i];
    fi(i, 1, m){
        fi(j, 1, n){
            char c;
            cin >> c;
            g[c - 'a'].pb({i, j});
        }
    }
    memset(L, 60, sizeof(L));
    for (auto vt : g[s[1] - 'a']){
        L[vt.fir][vt.se][1] = 1;
    }
    fi(x, 2, k){
        for (auto vt : g[s[x] - 'a']){
            for (auto vt2 : g[s[x-1] - 'a']){
                if (abs(vt.fir-vt2.fir) + abs(vt.se-vt2.se) != 0)
                    L[vt.fir][vt.se][x] = min(L[vt.fir][vt.se][x], L[vt2.fir][vt2.se][x-1] + abs(vt.fir-vt2.fir) + abs(vt.se-vt2.se));
            }
        }
    }
    for (auto vt : g[s[k] - 'a']){
        res = min(res, L[vt.fir][vt.se][k]);
    }
    cout << res;
}
