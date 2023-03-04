#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "surgery"
const int maxn = 1e5+5, maxm = 5e5+5;

using namespace std;

int n, k, m, a[maxm], nex[maxm], pre[maxn], kt[maxn];
priority_queue<pii> q;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k >> m;
    fi(i, 1, m) cin >> a[i];
    fid(i, m, 1){
        nex[i] = (pre[a[i]] == 0 ? n+1 : pre[a[i]]);
        pre[a[i]] = i;
    }
    int i = 1;
    while (i <= m){
        if (!kt[a[i]])
            q.push({nex[i], a[i]}), kt[a[i]] = 1;
        else q.pop(), q.push({nex[i], a[i]});
        i++;
        if (q.size() == k){
            break;
        }
    }
    int res = k;
    fi(j, i, m){
        if (!kt[a[j]]){
            kt[q.top().second] = 0;
            q.pop();
            q.push({nex[j], a[j]});
            kt[a[j]] = 1;
            res++;
        }
    }
    cout << res;
}
