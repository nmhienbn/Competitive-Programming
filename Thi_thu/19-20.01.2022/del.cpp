#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "del"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
const int maxn = 3e5 + 5;
const ll INF = 1e18;
using namespace std;

int n, a[maxn];
pii b[maxn];
ll s[maxn], sum;
int vt;

void sub1(){
    fi(i, 1, n) b[i] = {a[i], i};
    sort(b + 1, b + n + 1);
    while (n > 0){
        fi(i, 1, n) s[i] = s[i - 1] + b[i].first;
        ll res = INF;
        fi(i, 1, n){
            ll now = 1ll * b[i].first * (i * 2 - n) - s[i] * 2;
            if (now < res){
                res = now;
                vt = i;
            }
            else if (now == res && b[i].second < b[vt].second){
                vt = i;
            }
        }
        cout << res + s[n] << ' ';
        fi(i, vt, n - 1) b[i] = b[i + 1];
        n--;
    }
    exit(0);
}

ordered_set set1;
int cho[maxn];
ll bit[maxn];

void update(int x, int val){
    while (x <= maxn - 5){
        bit[x] += val;
        x += x & -x;
    }
}

ll get(int x){
    ll ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

void ud(int x, int pos){
    pos++;
    cout << 1ll * (pos * 2 - n) * a[x] + sum - get(cho[x]) * 2 << ' ';
    update(cho[x], -a[x]);
    set1.erase({a[x], x});
    n--;
    sum -= a[x];
}

void sub2(){
    fi(i, 1, n){
        b[i] = {a[i], i};
        sum += a[i];
    }
    sort(b + 1, b + n + 1);
    fi(i, 1, n){
        cho[b[i].second] = i;
        update(i, b[i].first);
    }
    fi(i, 1, n){
        set1.insert(b[i]);
    }
    while (n > 0){
        pii x = *(set1.find_by_order(n / 2));
        x.second = 0;
        int pos = set1.order_of_key(x);
        x = *(set1.find_by_order(pos));

        if (n % 2 == 0){
            pii x2 = *(set1.find_by_order(n / 2 - 1));
            x2.second = 0;
            int pos2 = set1.order_of_key(x2);
            x2 = *(set1.find_by_order(pos2));
            if (x2.second < x.second){
                ud(x2.second, pos2);
                continue;
            }
        }
        ud(x.second, pos);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    if (n <= 3000) sub1();
    sub2();
}
