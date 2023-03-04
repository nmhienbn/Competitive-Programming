#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "vodivide"
const int maxn = 5005;
using namespace std;

struct dl {
    int f, s, id;
    bool operator < (const dl& x) const {
        return f < x.f;
    }
};

int n, sum;
dl a[maxn];
int st[maxn], sn;
bool cl[maxn];
priority_queue<pii> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].f;
    fi(i, 1, n) cin >> a[i].s;
    fi(i, 1, n) a[i].id = i;
    sort(a + 1, a + n + 1);
    fi(i, 1, n){
        q.push({a[i].s, a[i].id});
        if (i & 1){
            sum += q.top().first;
            cl[q.top().second] = 1;
            q.pop();
        }
    }
    cout << sum << '\n';
    fi(i, 1, n){
        if (cl[a[i].id]){
            st[++sn] = a[i].id;
        }
        else {
            cout << st[sn--] << ' ' << a[i].id << '\n';
        }
    }
}
