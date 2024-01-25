#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    map<int,int> ma;
    int x = 0;
    ma[x]++;
    int ans = 0;
    for(int i=0;i<a.size();i++){
        x = x^a[i];
        int k = x^b;
        ans += ma[k];
        ma[x]++;
    }
    return ans;
}