class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size(), len=nums[0].size();
        string ans=string(len, '1');
        for(int i=0; i<n; i++)
            ans[i]=('1'-nums[i][i])+'0';
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();