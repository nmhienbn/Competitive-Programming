#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "yoghurt2"
const int maxn = 250005;
using namespace std;

int n, a[maxn], b[maxn], res;
ll sum;
bool kt[maxn];
priority_queue<pii> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) cin >> b[i];
    fi(i, 1, n){
        sum += a[i];
        if (sum >= b[i]){
            sum -= b[i];
            kt[i] = 1;
            q.push({b[i], i});
            res++;
        }
        else {
            if (q.empty()) continue;
            int val = q.top().first, id = q.top().second;
            if (sum + val >= b[i] && b[i] < val){
                q.pop();
                kt[id] = 0;
                kt[i] = 1;
                sum = sum + val - b[i];
                q.push({b[i], i});
            }
        }
    }
    cout << res << '\n';
    fi(i, 1, n) if (kt[i]) cout << i << ' ';
}
