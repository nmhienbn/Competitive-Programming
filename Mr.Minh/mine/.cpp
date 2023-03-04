#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump ""
const int maxn = 0;

using namespace std;

int n, m;

int main(){
    faster
//    freopen(NunuAndWillump".inp", "r", stdin);
//    freopen(NunuAndWillump".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            bool x;
            cin >> x;
            cout << (x^1) << ' ';
        }
        cout <<  '\n';
    }

}
