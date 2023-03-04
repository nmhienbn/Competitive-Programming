#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "move12"
const int maxn = 1e4 + 5;
using namespace std;

int n;
int a[maxn], t[maxn];
pii b[maxn];

bool check(int g){
    fi(i, 1, n){
        int x = g / t[i];
        b[i] = {a[i] - x, a[i] + x};
    }
    sort(b + 1, b + n + 1);
    priority_queue<int, vector<int>, greater<int>> q;
    int j = 1;
    fi(i, 1, n){
        while (j <= n && b[j].first <= i){
            q.push(b[j].second);
            j++;
        }
        while (q.size() && q.top() < i) q.pop();
        if (q.empty()) return 0;
        q.pop();
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i] >> t[i];
    int d = 0, c = 1e8;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
