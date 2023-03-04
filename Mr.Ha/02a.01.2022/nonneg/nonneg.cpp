#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define file freopen(Ahri".inp", "r", stdin); freopen(Ahri".out", "w", stdout);
#define Ahri "nonneg"
const int maxn = 25005, INF = 2e9;

using namespace std;

int n, m, p, s;
int L[maxn];
int tp[maxn], id;
int in[maxn];
vector<pii> g1[maxn], g2[maxn];
vector<int> num[maxn];
queue<int> q;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dfs(int u){
    tp[u] = id;
    num[id].pb(u);
    for (pii vt : g1[u]){
        int v = vt.first;
        if (!tp[v]){
            dfs(v);
        }
    }
}

void enterGraph(){
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        g1[u].pb({v, w});
        g1[v].pb({u, w});
    }
    fi(i, 1, n) if (!tp[i]){
        id++;
        dfs(i);
    }
    fi(i, 1, p){
        int u, v, w;
        cin >> u >> v >> w;
        g2[u].pb({v, w});
        in[tp[v]]++;
    }
}

void Dijkstra(){
    while (pq.size()){
        int u = pq.top().second;
        if (L[u] < pq.top().first){
            pq.pop();
            continue;
        }
        pq.pop();
        for (pii vt : g1[u]){
            int v = vt.first, w = vt.second;
            if (L[v] > L[u] + w){
                L[v] = L[u] + w;
                pq.push({L[v], v});
            }
        }
    }
}

void DAG(){
    fi(i, 1, n) L[i] = INF;
    L[s] = 0;
    fi(i, 1, n) if (!in[i]) q.push(i);
    while (q.size()){
        int u = q.front();
        q.pop();
        for (int v : num[u]){
            pq.push({L[v], v});
        }
        Dijkstra();
        for (int v : num[u]){
            for (pii vt : g2[v]){
                int c = vt.first, w = vt.second;
                if (L[v] < INF && L[c] > L[v] + w) L[c] = L[v] + w;
                if (--in[tp[c]] == 0) q.push(tp[c]);
            }
        }
    }
}

int main(){
    faster file
    cin >> n >> m >> p >> s;
    enterGraph();
    DAG();
    fi(i, 1, n){
        if (L[i] >= INF) cout << "NO PATH\n";
        else cout << L[i] << '\n';
    }
}
