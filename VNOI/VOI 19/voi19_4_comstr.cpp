#include<bits/stdc++.h>
using namespace std;

int m, m1, m2, r;
vector<int> fo[30];
int sumall[100005], nums[100005][26];
string s;

struct cmp{
    bool operator ()(int &ax, int &bx){
        return ax < bx;
    }
};
priority_queue<int, vector<int>, cmp> pq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("in.inp", "r", stdin);
    //freopen("out.out", "w", stdout);
    cin >> m >> m1 >> m2 >> r;
    cin >> s;
    //Find max ficolasi
    for(int i = 0; i<m1; i++)
        fo[1].push_back(i);
    for(int i = 0; i<m2; i++)
        fo[2].push_back(i + m1);
    int olp = 2;
    while(fo[olp].size()<m){
        olp++;
        for(int i = 0; i<fo[olp-1].size(); i++)
            fo[olp].push_back(fo[olp-1][i]);
        for(int i = 0; i<fo[olp-2].size(); i++)
            fo[olp].push_back(fo[olp-2][i]);
    }
    //Get loc vecotor
    for(int i = 0; i<m; i++){
        nums[fo[olp][i]][s[i] - 'A']++;
        sumall[fo[olp][i]]++;
    }
    //Process
    int res = 0;
    for(int i = 0; i<m1+m2; i++){
        res += sumall[fo[olp][i]] - nums[fo[olp][i]][s[i] - 'A'];
    }
    if(r > 0){
        for(int i = 0; i<m1+m2; i++){
            int z = fo[olp][i];
            int minest = sumall[z] - nums[z][s[i] - 'A'];
            int oran = minest;
            for(int j = 0; j<26; j++){
                if(nums[z][j] == 0 || j == s[i] - 'A')
                    continue;
                minest = min(minest, sumall[z] - nums[z][j] - 1);
            }
            pq.push(oran - minest);
        }
        for(int i = 1; i<=r; i++){
            res -= pq.top();
            pq.pop();
        }
    }
    //print
    cout << res << endl;
    return 0;
}
