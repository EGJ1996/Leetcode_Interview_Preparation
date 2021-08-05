#include<iostream>
#include<map>
#include<vector>

using namespace std;

bool is_valid_substr(const map<char,int>& m){
    for(auto el:m){
        // cout<<el.first<<" "<<el.second<<endl;
        if(el.second > 1){
            return false;
        }
    }
    return true;
}
    
int lengthOfLongestSubstring(string s) {
    if(s.length() <= 1){
        return s.length();
    }
    int ind1 = 0, ind2 = 1;
    map<char,int> num_elems = {};
    num_elems[s[ind1]] = 1;
    int max_substr = 1, cur_max_substr=1;
    
    while(ind2 <= s.length()){
        if(!is_valid_substr(num_elems)){
            num_elems[s[ind1]]--;
            cur_max_substr--;
            ind1++;
        }
        else{
            num_elems[s[ind2]]++;
            max_substr = max(max_substr,cur_max_substr);
            cur_max_substr++;
            ind2++;
        }
        
        // cout<<ind1<<" "<<ind2<<" "<<cur_max_substr<<endl;
        // cout<<"--------------------------"<<endl;
    }
    return max_substr;
}



int main(){
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = "dvdf";
    string s5 = "au";
    // cout<<lengthOfLongestSubstring(s1)<<endl;
    // cout<<lengthOfLongestSubstring(s2)<<endl;
    cout<<lengthOfLongestSubstring(s2)<<endl;
    return 0;
}