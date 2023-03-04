#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "position"
const int maxn = 1e5+5;

using namespace std;

int n, m, a[maxn], h[maxn];
vector<int> g[maxn];
int st[maxn], top, res[maxn];

bool on_stack[maxn];
void dfs(int u){
    on_stack[u] = 1;
    //cout << u << ' ';
    st[++top] = u;
    for (auto v : g[u]){
        if (on_stack[v]){
            fi(i, 1, top){
                int t = (h[st[i]] + m - h[v]) % (h[u] - h[v] + 1) + h[v];
                //cout << st[i] << ' ' << h[u] - h[v] << '\n';
                res[st[i]] = st[t] ;
            }
        }
        else {
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
    top--;
    on_stack[u] = 0;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> a[i];
        a[i]++;
        g[i].pb(a[i]);
    }
    fi(i, 1, n){
        if (!h[i]) h[i] = 1, dfs(i);
    }
    fi(i, 1, n) cout << res[i] - 1 << ' ';
}
