#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "frog"
const int maxn = 1e3+5;

using namespace std;

int n, m, k, pre[maxn][maxn], id;
ll a[maxn][maxn], L[maxn][maxn];
int q[maxn]; // deque

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n >> k;
    fi(i, 1, m){
        fi(j, 1, n){
            cin >> a[i][j];
        }
    }
    fi(i, 1, n) L[1][i] = a[1][i];
    fi(i, 2, m){
        int d = 1, c = 0;
        fi(j, 1, k){
            while (d <= c && L[i-1][q[c]] <= L[i-1][j]) c--;
            q[++c] = j;
        }
        fi(j, 1, n){
            while (d <= c && L[i-1][q[c]] <= L[i-1][j+k]) c--;
            q[++c] = j+k;
            while (q[d] < j-k) d++;
            L[i][j] = L[i-1][q[d]] + a[i][j];
            pre[i][j] = q[d];
        }
    }
    fi(i, 1, n){
        if (L[m][i] > L[m][id]){
            id = i;
        }
    }
    cout << L[m][id] << '\n';
    stack<int> vt;
    fid(i, m, 1){
        vt.push(id);
        id = pre[i][id];
    }
    while (vt.size()){
        cout << vt.top() << '\n';
        vt.pop();
    }
}
