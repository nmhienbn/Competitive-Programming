#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "decode"
const int maxn = 10005;

using namespace std;

int n, k, nex[maxn];
string s;
pair<char, int> a[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    while (cin >> s >> k){
        string res;
        n = s.size();
        s = ' ' + s;
        fi(i, 1, n){
            a[i] = {s[i], i};
        }
        sort(a+1, a+n+1);
        int j = k;
        fi(i, 1, n){
            cout << a[j].first;
            j = a[j].second;
        }
        cout << res << '\n';
    }
}
