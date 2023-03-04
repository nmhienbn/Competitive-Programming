#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 5, maxm = 1e5 + 5;
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
    cin >> n >> k >> S >> m;
    for (int i = 1; i <= S; i++) {
        string s1;
        cin >> s1;
        if (!ma[s1]) ma[s1] = ++cnt, s[cnt] = s1;
    }
    for (int i = 1; i <= cnt; i++) cl[i] = 1, q.push(i), res.push_back(i);
    for (int i = 1; i <= m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int u = ma[s1], v = ma[s2];
        if (!u) u = ma[s1] = ++cnt, s[cnt] = s1;
        if (!v) v = ma[s2] = ++cnt, s[cnt] = s2;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) if (!cl[v]) {
            if (++deg[v] >= k) {
                cl[v] = 1;
                res.push_back(v);
                q.push(v);
            }
        }
    }
    sort(res.begin(), res.end(), cmp);
    cout << res.size() << '\n';
    for (int i : res) cout << s[i] << ' ';
    return 0;
}
