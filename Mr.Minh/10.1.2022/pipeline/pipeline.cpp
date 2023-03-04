#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "pipeline"
const int maxn = 1e5 + 5;
using namespace std;

int n, m, k;
vector<int> g[maxn];
int cnt[maxn];
bool cl[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        cnt[u]++;
        cnt[v]++;
    }
    cnt[0] = -1;
    fi(i, 1, k){
        int u = 0;
        fi(i, 1, n){
            if (cnt[i] > cnt[u] && !cl[i]) u = i;
        }
        cl[u] = 1;
        if (cnt[u]){
            cnt[u] = 0;
            for (int v : g[u]) cnt[v]--;
        }
    }
    if (*max_element(cnt + 1, cnt + n + 1) <= 0){
        cout << "YES\n";
        fi(i, 1, n){
            if (cl[i]) cout << i << ' ';
        }
    }
    else cout << "NO";

}
