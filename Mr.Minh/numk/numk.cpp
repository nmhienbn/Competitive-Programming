#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "numk"
const int maxn = 1e6+5;
using namespace std;

int n, m, a[15], L[maxn], b[maxn][20], res[maxn];
pii pre[maxn];
queue<int> q;

bool LCA(int u, int v){
    if (L[u] != L[v]) return L[u] < L[v];
    fid(i, 17, 0){
        if (b[u][i] != b[v][i]){
            u = b[u][i];
            v = b[v][i];
        }
    }
    return u < v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 0, m-1) L[i] = 1e9;
    fi(i, 1, n){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    fi(i, 1, n){
        int v = a[i] % m;
        if (L[v] > 1 && a[i]){
            q.push(v);
            L[v] = 1;
            pre[v] = {a[i], v};
        }
    }
    while (q.size()){
        int u = q.front();
        q.pop();
        fi(i, 1, n){
            int v = (u*10 + a[i]) % m;
            if (L[v] > L[u] + 1){
                L[v] = L[u] + 1;
                pre[v] = {a[i], u};
                b[v][0] = u;
                fi(i, 1, 17) b[v][i] = b[b[v][i-1]][i-1];
                q.push(v);
            }
            else if (L[v] == L[u] + 1){
                if (LCA(u, b[v][0])){
                    pre[v] = {a[i], u};
                    b[v][0] = u;
                    fi(i, 1, 17) b[v][i] = b[b[v][i-1]][i-1];
                    q.push(v);
                }
            }
        }
    }
    if (L[0] == 1e9){
        cout << -1;
        exit(0);
    }
    int i = 0;
    fid(j, L[0], 1){
        res[j] = pre[i].first;
        i = pre[i].second;
    }
    fi(i, 1, L[0]) cout << res[i];
}
