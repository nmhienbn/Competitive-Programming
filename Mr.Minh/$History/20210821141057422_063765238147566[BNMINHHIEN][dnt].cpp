#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "dnt"
const int maxn = 6e4+5;

using namespace std;

int n, bit[maxn];
ll res;

void update (int x){
    while (x > 0){
        bit[x]++;
        x -= x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x <= maxn-5){
        ans += bit[x];
        x += x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        if (x > 1) res += get(x-1);
        update(x);
    }
    cout << res;
}
