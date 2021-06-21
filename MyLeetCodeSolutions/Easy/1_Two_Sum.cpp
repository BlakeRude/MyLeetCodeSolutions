// On^2 solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Init solution vector and size
        vector<int> solution;
        int s = nums.size();
        
        for(int i = 0; i < s; i++)
        {
            for(int j = 0; j < s; j++)
            {
                if(i != j)
                {
                    if((nums[i]+nums[j]) == target)
                    {
                        solution.push_back(i);
                        solution.push_back(j);
                        return solution;
                    }
                }
            }
        } 
        throw runtime_error("No solution");
    }
};

//On solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        int s = nums.size();
        map<int, int> map;
        
        for(int i = 0; i < s; i++)
        {
            int n = target - nums[i];
            if(map.find(n) != map.end())
            {
                solution.push_back(map.find(n)->second);
                solution.push_back(i);
                return solution;
            }
            map.insert(make_pair(nums[i],i));
        }
        throw runtime_error("No solution");
    }
};