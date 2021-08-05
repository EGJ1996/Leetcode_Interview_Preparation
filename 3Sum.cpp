#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int first = 0, second = 0, third = 0;
    int cur_closest = 0, all_closest = 1e6;
    sort(nums.begin(), nums.end());
    for(first = 0; first < nums.size()-2; first++){
        second = first + 1;
        third = nums.size()-1;
        while(second < third){
            cur_closest = nums[first] + nums[second] + nums[third];
            if(abs(cur_closest - target) < abs(all_closest - target)){
                all_closest = cur_closest;
            }
            if(cur_closest == target)
                return target;
            else if(cur_closest > target){
                third--;
            }
            else{
                second++;
            }
        }
    }
    return all_closest;
}


int main(){
    vector<int> nums = {1,2,4,8,16,32,64,128};
    // threeSumClosest(nums,100);
    cout<<threeSumClosest(nums, 82)<<endl;
    return 0 ;
}