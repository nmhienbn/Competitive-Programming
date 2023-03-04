#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "fortune"
const int maxn = 1e5+5, maxk = 1e3+5;

using namespace std;

int n, k, id, num[maxn], VieteJumping[maxn];
ll a[maxn], L[maxn][maxk];
vector<int> g[maxn];

stack<int> st;
bool cl[maxn];
void dfs(int u){
    num[u] = ++id;
    cl[u] = 1;
    st.push(u);
    for(auto v : g[u]){
        while (st.size() && !cl[st.top()]){
            VieteJumping[st.top()] = v;
            st.pop();
        }
        dfs(v);
    }
    cl[u] = 0;
}

void dfs2(int u){
    for(auto v : g[u]){
        dfs2(v);
    }
    fi(i, 0, k){
        L[VieteJumping[u]][i] = max(L[VieteJumping[u]][i], L[u][i]);
    }
    fi(i, 1, k){
        L[VieteJumping[u]][i] = max(L[VieteJumping[u]][i], L[u][i-1] + a[u]);
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;
        fi(i, 0, n){
            g[i].clear();
        }
        fi(i, 1, n){
            int u, w;
            cin >> u >> w;
            g[u].pb(i);
            a[i] = w;
        }
        dfs(0);
        while (st.size()){
            VieteJumping[st.top()] = n+1;
            st.pop();
        }
        dfs2(0);
        //fi(i, 0, n) cout << VieteJumping[i] << ' ';
        //fi(i, 0, n) cout << L[i][1] << ' ';
        cout << L[n+1][k] << '\n';
    }
}
