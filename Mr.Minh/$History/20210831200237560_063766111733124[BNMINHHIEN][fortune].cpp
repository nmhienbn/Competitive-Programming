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

int n, k, id, num[maxn], VieteJumping[maxn], a[maxn], b[maxn];
ll L[maxn][maxk];
vector<int> g[maxn];

stack<int> st;
bool cl[maxn];
void dfs(int u){
    num[u] = ++id;
    b[id] = a[u];
    cl[num[u]] = 1;
    while (st.size() && !cl[st.top()]){
        VieteJumping[st.top()] = num[u];
        st.pop();
    }
    st.push(num[u]);
    for(auto v : g[u]){
        dfs(v);
    }
    cl[num[u]] = 0;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        fi(i, 0, n){
            num[i] = 0;
            fi(j, 1, k){
                L[i][j] = 0;
            }
        }
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
        fi(i, 0, n){
            L[VieteJumping[i]][0] = max(L[VieteJumping[i]][0], L[i][0]);
            fi(j, 1, k){
                L[VieteJumping[i]][j] = max({L[VieteJumping[i]][j], L[i][j], L[i][j-1] + b[i]});
            }
        }
        cout << L[n+1][k] << '\n';
    }
}
