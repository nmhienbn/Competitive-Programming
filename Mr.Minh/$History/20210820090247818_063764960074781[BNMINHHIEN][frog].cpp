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
deque<int> q;

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
        q.clear();
        fi(j, 1, k){
            while (q.size() && L[i-1][q.front()] <= L[i-1][j]) q.pop_front();
            q.push_front(j);
        }
        fi(j, 1, n){
            if (j + k <= n){
                while (q.size() && L[i-1][q.front()] <= L[i-1][j+k]) q.pop_front();
                q.push_front(j+k);
            }
            while (q.back() < j-k) q.pop_back();
            L[i][j] = L[i-1][q.back()] + a[i][j];
            pre[i][j] = q.back();
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
