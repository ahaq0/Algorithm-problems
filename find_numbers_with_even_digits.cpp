class Solution {
public:
    int findNumbers(vector<int>& nums) {
     
        string str = "";
        int count= 0;
        
  
        for (auto &&i: nums) 
        {
		    str = to_string(i);
            if(str.length() % 2 == 0)
            {
                cout << i << " ";
                count += 1;
            }
            str = "";
        }

        
        return count;
    }
};