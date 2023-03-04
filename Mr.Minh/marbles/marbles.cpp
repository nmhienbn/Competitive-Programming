#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "marbles"
const int maxn = 0;

using namespace std;

ll n, m;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m;
    m -= n*(n-1)/2;
    if (m < 0){
        cout << -1;
        exit(0);
    }
    cout << m/n << ' ' << m/n - (m%n == 0) + n;

}
