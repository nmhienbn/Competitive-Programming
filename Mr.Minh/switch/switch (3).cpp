#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "switch"
const int maxn = (1 << 25) + 10;
using namespace std;

int n, st, L[maxn], x;

queue<int> q;

int kq(int v){
    int ans = v, cnt = 0;
    fi(i, 0, n){
        if (gb(v, i)) cnt++;
        else {
            if (cnt >= 4){
                fi(j, i - cnt, i - 1) ans -= (1 << j);
            }
            cnt = 0;
        }
    }
    return ans;
}

void bfs(){
    L[st] = 1;
    q.push(st);
    while (q.size()){
        int u = q.front();
        q.pop();
        fi(i, 0, n - 1) if (!gb(u, i)){
            int v = kq(u + (1 << i));
            if (!L[v]){
                L[v] = L[u] + 1;
                if (v == 0) return;
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
    cin >> n;
    fi(i, 0, n - 1){
        cin >> x;
        st += (x << i);
    }
    bfs();
    cout << L[0] - 1;
}
