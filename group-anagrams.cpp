class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> current;
        vector<vector<string>> output;
        
        unordered_map<string, vector<string>> map;
        for ( auto i : strs)
        {   
            cout << i << " ";
            string sorted = i;
            sort(i.begin(), i.end());
            map[i].push_back(sorted);
        }
        
        for ( auto  i : map)
        {
            output.push_back(i.second);
        }
        
        return output;
    }
};