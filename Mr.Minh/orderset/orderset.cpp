#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "orderset"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define order_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int maxn = 0;

using namespace std;

int n;
order_set s;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        char c;
        int x;
        cin >> c >> x;
        if (c == 'I') s.insert(x);
        else if (c == 'D') s.erase(x);
        else if (c == 'K'){
            if (x > int(s.size())) cout << "invalid\n";
            else cout << *s.find_by_order(x-1) << '\n';
        }
        else cout << s.order_of_key(x) << '\n';
    }

}
