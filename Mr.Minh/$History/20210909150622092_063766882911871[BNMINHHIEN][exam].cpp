#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "exam"
const int maxn = 2e5+5, maxm =2e6+5;

using namespace std;

int n, res, maxx;
ll cnt[maxm];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        maxx = max(maxx, x);
        int u = sqrt(x);
        fi(i, 1, u){
            if (x % i == 0){
                cnt[i]++;
                if (i != x/i) cnt[x/i]++;
            }
        }
    }
    fi(i, 1, maxx){
        if (cnt[i]*i > cnt[res]*res && cnt[i] > 1){
            res = i;
        }
    }
    cout << cnt[res]*res;
}
