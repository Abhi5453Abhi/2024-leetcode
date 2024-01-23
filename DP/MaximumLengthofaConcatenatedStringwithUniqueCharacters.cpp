class Solution {
public:
    unordered_map<string,int> ma;
    int check(string &arr, string &temp){
        vector<int> ct(26);
        if(temp.size()>26)return true;
        for(int i=0;i<temp.size();i++){
            ct[temp[i]-'a']++;
            if(ct[temp[i]-'a'] > 1)return true;
            
        }
        for(int i=0;i<arr.size();i++){
            ct[arr[i]-'a']++;
            if(ct[arr[i]-'a'] > 1)return true;
            
        }
        return false;
    }
    int solve(vector<string>& arr, int i, string temp){
        if(i == arr.size()){
            return ma[temp] = temp.size();
        }
        if(ma.find(temp) != ma.end())return ma[temp];
        int exc = 0;
        int inc = 0;
        if(check(arr[i],temp)){
            exc = solve(arr,i+1,temp);
        }else{     
            inc = max(
                solve(arr,i+1,temp+arr[i]),
                solve(arr,i+1,temp)
            );
        }
        return ma[temp] = max(inc,exc);
    }
    int maxLength(vector<string>& arr) {
        return solve(arr,0,"");
    }
};