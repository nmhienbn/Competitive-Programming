#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "wordgame"
const int maxn = 5e5+5;

using namespace std;

int n;
char pre;
string s;
set<string> ss;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n >> s;
    ss.insert(s);
    pre = s.back();
    fi(i, 2, n){
        cin >> s;
        if (ss.find(s) != ss.end() || s.front() != pre){
            cout << "NO\n" << i;
            exit(0);
        }
        pre = s.back();
        ss.insert(s);
    }
    cout << "YES";
}
