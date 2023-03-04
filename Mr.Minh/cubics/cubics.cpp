#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "cubics"
const int maxn = 1e5+5;

using namespace std;

int n, k, res, id;
ll now, pre;
unordered_map<ll, int> vt;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    vt[0] = 1;
    fi(i, 1, n){
        cin >> now;
        now -= k;
        now += pre;
        pre = now;
        if (vt[now] == 0){
            vt[now] = i+1;
        }
        else {
            int pre = vt[now];
            if (i - pre + 1 > res){
                res = i - pre + 1;
                id = pre;
            }
        }
    }
    cout << res;
    if (res > 0) cout << ' ' << id;
}
