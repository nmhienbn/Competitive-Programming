#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "queue"
const int maxn = 5e4 + 5;
using namespace std;

int nt, n, m;
pii a[maxn], b[maxn];

bool check(int g){
    fi(i, 1, g) b[i] = a[i];
    sort(b + 1, b + g + 1);
    int j = 1;
    priority_queue<int, vector<int>, greater<int>> q;
    fi(i, 1, m){
        while (j <= g && b[j].first <= i){
            q.push(b[j].second);
            j++;
        }
        if (q.size()){
            if (q.top() < i) return 0;
            else q.pop();
        }
    }
    return q.empty();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> nt;
    while (nt--){
        cin >> m >> n;
        fi(i, 1, n) cin >> a[i].first >> a[i].second;
        int d = 1, c = n;
        while (d <= c){
            int g = (d + c) >> 1;
            if (check(g)) d = g + 1;
            else c = g - 1;
        }
        cout << c << '\n';
    }
}
