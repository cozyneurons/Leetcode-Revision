class Solution {
public:
    vector<int> findGoodIntegers(int n) 
    {
        vector<int> ans;
        unordered_map<int,int> ump;
        int cuberoot = cbrt(n);
        for (int i = 1; i<=cuberoot; i++)
            {
                for (int j = i; j<=cuberoot; j++)
                    {
                        int cubesum = i*i*i + j*j*j;
                        if (cubesum>n)
                        {
                            break;
                        }
                        ump[cubesum]++;
                    }
            }
        for (auto & it : ump)
            {
                if (it.second>=2) ans.push_back(it.first);
            }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
