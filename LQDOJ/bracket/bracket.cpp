#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,bool>
#define pb push_back
#define ll long long
#define Irelia "bracket"
const int maxn = 1e5 + 5;
using namespace std;

int n;
priority_queue<pii> q;
ll sum;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        q.push({x, 1});
        sum += q.top().first - x;
        if (q.top().second){
            pii tmp = {q.top().first, 0};
            q.pop();
            q.push(tmp);
        }
        else {
            q.pop();
        }
    }
    cout << sum;
}
