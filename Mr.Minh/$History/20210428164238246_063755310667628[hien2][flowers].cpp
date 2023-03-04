#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define pp pair<int, int>
#define name "flowers"
#define maxn 100005

using namespace std;

int n;
ll sum, res;
pp a[maxn];
bool  cmp(pp a, pp b){
    if (a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

//fi(i, 1, n) cin >> arr[i];
//fi(i, 1, n) cout << arr[i] << ' ';


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, n) {cin >> a[i].first >> a[i].second; sum += a[i].second;}
    sort(a+1, a+n+1, cmp);
    fi(i, 1, n-1){
        sum -= a[i].second;
        res += sum*a[i].first*2;
    }
    cout << res;
}
