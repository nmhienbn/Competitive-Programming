#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "vosnet"
const int maxn = 3005;
using namespace std;

int n, m;
vector<int> g[maxn];
int f[15];
int lg2[maxn];
int d[maxn];
queue<int> q;

void bfs(int st){
    fi(i, 1, n) d[i] = 0;
    q.push(st);
    d[st] = 1;
    while (q.size()){
        int u = q.front();
        q.pop();
        for (int v : g[u]){
            if (!d[v]){
                d[v] = d[u] + 1;
                if (v > st) f[lg2[d[u]]]++;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 2, n){
        lg2[i] = lg2[i >> 1] + 1;
        if (i > (1 << lg2[i])) lg2[i]++;
    }
    //fi(i, 1, n) cout << (1 << lg2[i]) << '\n';
    fi(i, 1, n) bfs(i);
    int i = 0;
    do {
        i++;
        cout << f[i] << ' ';
    } while (f[i]);
}
