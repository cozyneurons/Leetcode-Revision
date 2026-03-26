class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int i=0;
        int j=arr.size()-2;
        while(i<arr.size()-1)
        {
            if (arr[i]==0)
            {
                for (int j = arr.size()-1; j>i; j--)
                {
                    arr[j] = arr[j-1];
                }
                arr[i+1]=0;
                i++;
            }
            i++;
        }
    }
};
