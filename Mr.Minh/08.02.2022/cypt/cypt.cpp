#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "cypt"
const int maxn = 256;
using namespace std;

int n;
char ma[maxn];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 0, 255) ma[i] = char(i);
    fi(i, 1, n){
        cin.ignore();
        getline(cin, s);
        fi(i, 'A', 'Z') cin >> ma[i];
        cout << i << ' ';
        for (char c : s){
            cout << ma[c];
        }
        cout <<  '\n';
    }
}
