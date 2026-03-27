class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.size();
        unordered_map<int,int> mpp;
        mpp[0] = mpp[1] = mpp[2] = -1;
        int r = 0;
        int count = 0;
        while(r<n)
        {
            mpp[s[r] - 'a'] = r;
            if (mpp[0]!=-1 && mpp[1]!=-1 && mpp[2]!=-1)
            {
                int mini = min(mpp[0],mpp[1]);
                mini = min(mini,mpp[2]);
                count = count + mini + 1;;
            }
            r++;
        }
        return count;
    }
};
