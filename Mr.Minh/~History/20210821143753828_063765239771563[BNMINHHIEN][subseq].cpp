#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "subseq"
const int maxn = 1e5+5;

using namespace std;

int n, b[maxn], bit[maxn], res, len, f[maxn];
pii a[maxn];

pii get(int x){
    int ans = 0, cnt = 0;
    while (x > 0){
        if (bit[x] > ans){
            ans = bit[x];
            cnt = f[x];
        }
        else if (bit[x] == ans){
            cnt += f[x];
        }
        x -= x & -x;
    }
    return {ans, cnt};
}

void update(int x, int val, int cnt){
    while (x <= n){
        if (bit[x] < val){
            bit[x] = val;
            f[x] = cnt;
        }
        else if (bit[x] == val){
            f[x] += cnt;
        }
        x += x & -x;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a+1, a+n+1);
    a[0].first = -1;
    int id = 0;
    fi(i, 1, n){
        if (a[i].first != a[i-1].first){
            b[a[i].second] = ++id;
        }
        else b[a[i].second] = id;
    }
    fi(i, 1, n){
        pii ans = get(b[i]-1);
        if (ans.second == 0) ans.second++;
        update(b[i], ans.first+1, ans.second);
        if (ans.first+1 > len){
            len = ans.first+1;
            res = ans.second;
        }
        else if (ans.first+1 == len){
            res += ans.second;
        }
    }
    cout << res;
}
