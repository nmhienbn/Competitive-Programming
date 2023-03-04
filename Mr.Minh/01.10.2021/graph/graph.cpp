#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "graph"
const int maxn = 1005;

using namespace std;

int n, m, low[maxn], num[maxn], id, cnt;
vector<int> g[maxn], scc[maxn];

stack<int> st;
void dfs(int u){
    st.push(u);
    num[u] = low[u] = ++id;
    for(auto v : g[u]){
        if (num[v]){
            low[u] = min(low[u], num[v]);
        }
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]){
        cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            scc[cnt].pb(v);
            low[v] = num[v] = 1e9;
        } while (v != u);
        //sort(scc[cnt].begin(), scc[cnt].end());
    }
}

bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    fi(i, 1, n){
        if (!num[i]){
            dfs(i);
        }
    }
    //sort(scc+1, scc+cnt+1, cmp);
    cout << cnt << '\n';
    fi(i, 1, cnt){
        for (auto v : scc[i]){
            cout << v << ' ';
        }
        cout << '\n';
    }
}
