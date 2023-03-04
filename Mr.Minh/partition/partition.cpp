#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "partition"
const int maxn = 255;
using namespace std;

int n, res;
int G[maxn][maxn], GC[maxn][maxn];

bool chiadoi(int G[][maxn], int src, int cl[]){
    cl[src] = 1;
    queue<int> q;
    q.push(src);
    while (q.size()){
        int u = q.front();
        q.pop();
        fi(v, 1, n){
            if (G[u][v] && cl[v] == -1){
                cl[v] = 1 - cl[u];
                q.push(v);
            }
            else if (G[u][v] && cl[v] == cl[u])
                return false;
        }
    }
    return true;
}

bool isBipartite(int G[][maxn]){
    int cl[maxn];
    fi(i, 1, n)
        cl[i] = -1;

    fi(i, 1, n)
        if (cl[i] == -1)
            if (chiadoi(G, i, cl) == false)
                return false;
    fi(i, 1, n) res += cl[i];
    return true;
}

bool check(int G[][maxn]){
    fi(i, 1, n)
        fi(j, 1, n)
             GC[i][j] = (i != j ? !G[i][j] : 0);

    return  isBipartite(GC);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) fi(j, 1, n) cin >> G[i][j];
    if (!check(G)){
        cout << "Impossible";
        return 0;
    }
    cout << (res < n ? abs(n-res*2) : res%2);
}
