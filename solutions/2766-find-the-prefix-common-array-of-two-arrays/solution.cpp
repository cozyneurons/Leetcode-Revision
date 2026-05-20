class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        int count = 0;

        vector<int> ans(n,0);
        unordered_map<int,int> ump;

        for (int i = 0; i<n; i++)
        {
            ump[A[i]]++;
            ump[B[i]]++;
            if (A[i]!=B[i] && ump[A[i]]>1 && ump[B[i]]>1)
            {
                count+=2;
                ans[i] = count;
            }
            else if (ump[A[i]]>1 || ump[B[i]]>1)
            {
                count++;
                ans[i] = count;
            }
            else
            {
                ans[i] = count;
            }
        }
        return ans;
    }
};
