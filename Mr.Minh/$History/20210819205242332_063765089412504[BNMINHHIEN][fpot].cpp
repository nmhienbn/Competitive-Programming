#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define se second
#define ff first
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "fpot"
const int maxn = 1e5+5;

using namespace std;

int n, dis;
pii a[maxn];

bool check(int k){
    deque<int> q1, q2;
    fi(i, 1, n){
        while (q1.size() && a[q1.front()].se >= a[i].se) q1.pop_front();
        q1.push_front(i);
        while (q2.size() && a[q2.front()].se <= a[i].se) q2.pop_front();
        q2.push_front(i);
        while (q1.size() && a[q1.back()].ff < a[i].ff-k) q1.pop_back();
        while (q2.size() && a[q2.back()].ff < a[i].ff-k) q2.pop_back();
        if (a[q2.back()].se - a[q1.back()].se >= dis) return true;
    }
    return 0;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> dis;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1);
    int d = 0, c = a[n].first-a[1].first;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g-1;
        else d = g+1;
    }
    cout << d;
}
