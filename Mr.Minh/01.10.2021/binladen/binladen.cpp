#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "binladen"
const int maxn = 3000;

using namespace std;

struct dl {
    int u, v;
    ll w;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int m, n, a[maxn][15], b[maxn][15];
ll L[maxn][15];

void Dijkstra(){
    priority_queue<dl> q;
    fi(i, 1, n) q.push({1, i, L[1][i]});
    while (q.size()){
        int i = q.top().u, j = q.top().v;
        q.pop();
        if (L[i+1][j] > L[i][j] + a[i+1][j]){
            L[i+1][j] = L[i][j] + a[i+1][j];
            q.push({i+1, j, L[i+1][j]});
        }
        if (L[i-1][j] > L[i][j] + a[i][j]){
            L[i-1][j] = L[i][j] + a[i][j];
            q.push({i-1, j, L[i-1][j]});
        }
        if (L[i][j-1] > L[i][j] + b[i][j-1]){
            L[i][j-1] = L[i][j] + b[i][j-1];
            q.push({i, j-1, L[i][j-1]});
        }
        if (L[i][j+1] > L[i][j] + b[i][j]){
            L[i][j+1] = L[i][j] + b[i][j];
            q.push({i, j+1, L[i][j+1]});
        }
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n) cin >> a[i][j];
        fi(j, 1, n-1) cin >> b[i][j];
    }
    fi(i, 1, n) L[1][i] = a[1][i];
    fi(i, 2, m){
        fi(j, 1, n){
            L[i][j] = 1e9;
        }
    }
    Dijkstra();
    cout << L[m][n];
}
