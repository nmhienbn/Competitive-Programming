#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "segments"
#define maxn 100005
#define maxa 1e9

using namespace std;

int n, m, L[maxn];
pair<int, int> a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }
    sort(a+1, a+n+1);
    fi(i, 1, m){
        int t, dem = 0;
        cin >> t;
        fi(j, 1, n)
            if (a[j].first <= t){
                if (a[j].second >= t) dem++;}
            else break;
        cout << dem << ' ';
    }
}
