#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "expedi"
const int maxn = 1e4+5;
using namespace std;

int n, l, p, L[maxn], cnt, res;
pii a[maxn];
priority_queue<int> q;

bool cmp(pii a, pii b){
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1, cmp);
    cin >> a[0].first >> a[0].second;
    q.push(a[0].second);
    fi(i, 1, n+1){
        while (q.size()){
            if (cnt >= a[i-1].first - a[i].first){
                break;
            }
            int u = q.top();
            q.pop();
            cnt += u;
            res++;
        }
        cnt -= a[i-1].first - a[i].first;
        if (cnt < 0){
            cout << -1;
            exit(0);
        }
        q.push(a[i].second);
    }
    cout << res-1;
}
