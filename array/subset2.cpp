#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
class Solution {
public:
      void getallsubset(vector<int>& nums , vector<int> &ans, int i ,vector<vector<int>> &allsubset){
            if(i==nums.size())  {
             allsubset.push_back(ans);
             return;
            }       
            //include
               ans.push_back(nums[i]);
               getallsubset(nums,ans,i+1,allsubset);
                  ans.pop_back();
            int idx= i+1;
            while(idx < nums.size() && nums[idx]== nums[idx-1]){
                idx++;
            }
            //exclude
                 getallsubset(nums,ans,idx,allsubset);  
    
      }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>allsubset;
        vector<int>ans;
        getallsubset(nums,ans,0,allsubset);
        return allsubset;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};  // test input
    
    vector<vector<int>> result = sol.subsetsWithDup(nums);  // ✅ declare result properly

    cout << "Subsets:\n";
    for (auto &subset : result) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }
    return 0;
}
