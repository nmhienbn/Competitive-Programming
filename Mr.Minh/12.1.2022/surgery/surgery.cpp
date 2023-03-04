#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "surgery"
const int maxn = 5e5 + 5;
using namespace std;

int n, m, k, a[maxn];
int nex[maxn], now[maxn];
int cnt, res;
bool cl[maxn];
priority_queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k >> m;
    fi(i, 1, m) cin >> a[i];
    fid(i, m, 1){
        if (!now[a[i]])
            nex[i] = m + 1;
        else
            nex[i] = now[a[i]];
        now[a[i]] = i;
    }
    fi(i, 1, m){
        if (cl[a[i]]){
            q.push(nex[i]);
            continue;
        }
        if (cnt < k){
            cnt++;
            cl[a[i]] = 1;
            q.push(nex[i]);
            res++;
        }
        else {
            int u = q.top();
            cl[a[u]] = 0;
            q.pop();

            cl[a[i]] = 1;
            q.push(nex[i]);
            res++;
        }
    }
    cout << res;
}
