#include <bits/stdc++.h>

using namespace std;
const int maxn = 50005;
const int blockSize = 230;
struct Edge{
    int u, v, w;
    bool operator < (const Edge &other) {
        return w < other.w;
    }
};
vector<Edge> eA, eB;
struct TGraph {
    int n, s, t;
    vector<vector<int> > adjA, adjB;
    vector<Edge> eA, eB;
    vector<int> mark;
    int cntMARK = 0, cntCC = 0, costA = 0, costB = 0;
    vector<int> belong;
    TGraph(int n, int s, int t, vector<Edge> &eA, vector<Edge> &eB):n(n), s(s), t(t), eA(eA), eB(eB) {
        adjA.resize(n + 1);
        adjB.resize(n + 1);
        belong.resize(n + 1);
        mark.resize(n + 1);
        for (int i = 0; i < eA.size(); ++i) {
            int u = eA[i].u, v = eA[i].v;
            adjA[u].push_back(i);
            adjA[v].push_back(i);
        }
        for (int i = 0; i < eB.size(); ++i) {
            int u = eB[i].u, v = eB[i].v;
            adjB[u].push_back(i);
            adjB[v].push_back(i);
        }
        cntMARK = 0;
        cntCC = 0;
    }
    bool Able(int u, int limA, int limB) {
        mark[u] = cntMARK;
        if (u == t) return true;
        for (int id : adjA[u]) if (id < limA) {
            int v = eA[id].v;
            if (v == u) v = eA[id].u;
            if (mark[v] != cntMARK && Able(v, limA, limB))   
                return true;
        }
        for (int id : adjB[u]) if (id < limB) {
            int v = eB[id].v;
            if (v == u) v = eB[id].u;
            if (mark[v] != cntMARK && Able(v, limA, limB))   
                return true;
        }
        return false;
    }  
    int TwoPointer(int iA, int iB, int step) {
        ++cntMARK;
        while (iB > -step && Able(s, iA, iB)) {
            iB -= step;
            ++cntMARK;
        }
        if (iB + step <= (int) eB.size()) return iB + step;
        return eB.size() + 1;
    }
    void DFS(int u, int limA, int limB) {
        mark[u] = cntMARK;
        belong[u] = cntCC;
        for (int id : adjA[u]) if (id < limA) {
            int v = eA[id].v;
            costA = max(costA, eA[id].w);
            if (v == u) v = eA[id].u;
            if (mark[v] != cntMARK)
                DFS(v, limA, limB);
        }
        for (int id : adjB[u]) if (id < limB) {
            int v = eB[id].v;
            costB = max(costB, eB[id].w);
            if (v == u) v = eB[id].u;
            if (mark[v] != cntMARK) 
                DFS(v, limA, limB);
        }
    }
    int Decompose(int limA, int limB) {
        cntCC = 0;
        ++cntMARK;
        costA = costB = 0;
        for (int i = 1; i <= n; ++i) if (mark[i] != cntMARK) {
            ++cntCC;
            DFS(i, limA - blockSize, limB - blockSize);
        }
        limA = min(limA, (int) eA.size());
        limB = min(limB, (int) eB.size());
        ::eA.clear();
        ::eB.clear();
        for (int i = 0; i < limA; ++i) {
            int u = eA[i].u, v = eA[i].v, w = eA[i].w;
            if (belong[u] != belong[v])
                ::eA.push_back({belong[u], belong[v], w});
        }
        for (int i = 0; i < limB; ++i) {
            int u = eB[i].u, v = eB[i].v, w = eB[i].w;
            if (belong[u] != belong[v])
                ::eB.push_back({belong[u], belong[v], w});
        }
        assert(::eA.size() <= blockSize * 2);
        assert(::eB.size() <= blockSize * 2);
        return cntCC;
    }
};
int n, m, s, t;
int F[maxn + blockSize];
int Solve() {
    TGraph InitGraph(n, s, t, eA, eB);
    int last = eB.size();
    for (int iA = 0; iA < eA.size() + blockSize; iA += blockSize) {
        last = InitGraph.TwoPointer(iA, last, blockSize);
        if (last < 0) last = min((int) eB.size(), blockSize);
        if (last <= (int) eB.size())
            F[iA] = last;
        else 
            F[iA] = -1e9;
        last = min(last, (int) eB.size());
    }
    int res = 2e9;
    int save = eA.size();
    for (int iA = 0; iA < save + blockSize; iA += blockSize) {
        if (F[iA] < -1e5) continue;
        int iB = F[iA];
        int newN = InitGraph.Decompose(iA, iB);
        int newS = InitGraph.belong[s];
        int newT = InitGraph.belong[t];
        TGraph curGraph(newN, newS, newT, eA, eB);
        int last = eB.size();
        for (int i = 0; i <= eA.size(); ++i) {
            last = curGraph.TwoPointer(i, last, 1);
            if (last <= (int) eB.size()) {
                int costA = max(i == 0 ? 0 : eA[i - 1].w, InitGraph.costA);
                int costB = max(last == 0 ? 0 : eB[last - 1].w, InitGraph.costB); 
                res = min(res, costA + costB);
            }
            else 
                last = eB.size();
        }
    }
    return res;
}
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    freopen("BUS.INP", "r", stdin);
    freopen("BUS.OUT", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m  >> s >> t;
    for (int i = 1, c, u, v, w; i <= m; ++i) {
        cin >> c >> u >> v >> w;
        if (c == 1) eA.push_back({u, v, w});
        else eB.push_back({u, v, w});
    }
    sort(eA.begin(), eA.end());
    sort(eB.begin(), eB.end());
    auto xA = eA, xB = eB;
    int res = Solve();
    eA = xB, eB = xA;
    res = min(res, Solve());
    cout << res;
    return 0;
}
1
