#include <bits/stdc++.h>

using namespace std;
const int maxn = 2005;

int n, a[maxn], d, res;
int bit[maxn];
vector<int> g[maxn];

void update(int x, int N, int len){
    while (x <= N){
        bit[x] = max(bit[x], len);
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans = max(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("noel.inp", "r", stdin);
    //freopen("noel.out", "w", stdout);
    cin >> n >> d;
    n <<= 1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = n; j >= 1; j--) 
            if (abs(a[i] - a[j]) <= d)
                g[i].push_back(j);
    }
    for(int mid = 1; mid <= n; mid++){
        for(int i = 1; i <= mid; i++) bit[i] = 0;
        for(int r = mid + 1; r <= n; r++){
            for (int l : g[r]) 
                if (l <= mid){
                    int len = get(l - 1) + 1;
                    update(l, mid, len);
                }
        }
        res = max(res, get(mid));
    }
    cout << res;
}
