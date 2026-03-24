class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int leftsum = 0,rightsum = 0,sum = 0;
        int n = cardPoints.size();
        for (int i = 0; i<k; i++)
        {
            leftsum+=cardPoints[i];
        }
        sum = leftsum;
        int rightindex = n - 1;
        for (int i = k-1; i>=0; i--)
        {
            leftsum-=cardPoints[i];
            rightsum+=cardPoints[rightindex];
            rightindex--;
            sum = max (sum, leftsum + rightsum);
        }
        return sum;
    }
};
