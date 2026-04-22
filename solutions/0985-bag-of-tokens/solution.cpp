class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());

        int score = 0;
        
        int i = 0;
        int j = n-1;

        while(i<=j)
        {
            if (power >= tokens[i])
            {
                power = power - tokens[i];
                score++;
                i++;
            }
            else if (score >= 1 && i!=j && power + tokens[j] > tokens[i])
            {
                power += tokens[j];
                score--;    
                j--;
            }
            else
            {
                i++;
            }
        }

        return score;
    }
};
