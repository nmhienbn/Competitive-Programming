#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define all(a) a.begin(), a.end()
#define pb push_back
#define ll long long
#define Irelia "specone"
const int maxn = 1e4 + 5, maxm = 1e5 + 5;
using namespace std;

int n, k, S, m;
int cnt;
bool cl[maxn];
int deg[maxn];
unordered_map<string, int> ma;
queue<int> q;
string s[maxn];
vector<int> g[maxn], res;

bool cmp(int a, int b){
    return s[a] < s[b];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k >> S >> m;
    fi(i, 1, S){
        string s1;
        cin >> s1;
        if (!ma[s1]) ma[s1] = ++cnt, s[cnt] = s1;
    }
    fi(i, 1, cnt) cl[i] = 1, q.push(i), res.pb(i);
    fi(i, 1, m){
        string s1, s2;
        cin >> s1 >> s2;
        int u = ma[s1], v = ma[s2];
        if (!u) u = ma[s1] = ++cnt, s[cnt] = s1;
        if (!v) v = ma[s2] = ++cnt, s[cnt] = s2;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n){
        sort(all(g[i]));
        g[i].resize(unique(all(g[i])) - g[i].begin());
    }
    while (q.size()){
        int u = q.front();
        q.pop();
        for (int v : g[u]) if (!cl[v]){
            if (++deg[v] >= k){
                cl[v] = 1;
                res.pb(v);
                q.push(v);
            }
        }
    }
    sort(all(res), cmp);
    cout << res.size() << '\n';
    for (int i : res) cout << s[i] << ' ';
}
