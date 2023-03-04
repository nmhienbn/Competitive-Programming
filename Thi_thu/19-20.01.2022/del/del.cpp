#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "del"
const int maxn = 3e5 + 5;
const ll INF = 1e18;
using namespace std;

int n, a[maxn];
ll s1, s2;

priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    fi(i, 1, n - n / 2) q1.push(a[i]), s1 += a[i];
    fi(i, n - n / 2 + 1, n) q2.push(a[i]), s2 += a[i];
    fi(rep, 1, n){
        if (rep & 1){
            cout << 1ll * q1.top() * (q1.size() - q2.size()) - s1 + s2 << ' ';
            s1 -= q1.top();
            q1.pop();
        }
        else {
            cout << 1ll * q2.top() * (q1.size() - q2.size()) - s1 + s2 << ' ';
            s2 -= q2.top();
            q2.pop();
        }
    }
}
