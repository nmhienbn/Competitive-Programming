#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "cppset"
const int maxn = 0;

using namespace std;

set<int> a;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    int t;
    while (cin >> t){
        int x;
        if (t == 1) cin >> x, a.insert(x);
        else if (t == 2) cin >> x, a.erase(x);
        else if (t >= 3 && a.empty()) cout << "empty";
        else if (t == 3) cout << *a.begin();
        else if (t == 4) cout << *a.rbegin();
        else if (t == 5){
            cin >> x;
            auto it = a.lower_bound(x+1);
            if (it == a.end()) cout << "no";
            else cout << *it;
        }
        else if (t == 6){
            cin >> x;
            auto it = a.lower_bound(x);
            if (it == a.end()) cout << "no";
            else cout << *it;
        }
        else if (t == 7){
            cin >> x;
            auto it = a.lower_bound(x);
            if (it == a.begin()) cout << "no";
            else cout << *prev(it);
        }
        else if (t == 8){
            cin >> x;
            auto it = a.lower_bound(x+1);
            if (it == a.begin()) cout << "no";
            else cout << *prev(it);
        }
        if (t >= 3) cout << '\n';
    }

}
