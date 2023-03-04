#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "divisors"
const int maxn = 1e6+5;
using namespace std;

int s, t, L[maxn];
queue<int> q;
vector<int> p[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> t;
    fi(i, 2, t){
        for (int j = i*2; j <= t; j += i){
            p[j].pb(i);
        }
    }
    if (s == t){
        cout << 0;
        exit(0);
    }
    q.push(s);
    while (q.size()){
        int u = q.front();
        if (u == t) break;
        q.pop();
        for (auto i : p[u]) if (u % i == 0){
            if (u + i <= t && !L[u + i]){
                L[u + i] = L[u] + 1;
                q.push(u + i);
            }
            if (u + u / i <= t && !L[u + u / i]){
                L[u + u / i] = L[u] + 1;
                q.push(u + u / i);
            }
        }
    }
    cout << (L[t] == 0 ? -1 : L[t]);
}
