#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 30005
#define maxm 1000006
#define MOD
#define Seraphine "safenet2"

using namespace std;

int n, m, low[maxn], num[maxn], id, res = 1;
vector<int> g[maxn];

int cl[maxn];
stack<pii> st;
void dfs(int u, int p){
    num[u] = low[u] = ++id;
    for (auto v : g[u]){
        if (v == p) continue;
        if (num[v]){
            low[u] = min(low[u], num[v]);
        }
        else {
            st.push({v, u});
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]){
                int cnt = 1;
                while (true){
                    pii now = st.top();
                    st.pop();
                    cnt++;
                    if (now == pii(v, u)) break;
                }
                res = max(res, cnt);
            }
        }
    }
}

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(u, 1, n){
        if (!num[u]){
            dfs(u, -1);
        }
    }
    cout << res;
}
