class Solution {
public:
    string getHint(string secret, string guess) 
    {
        vector<int> v1(10,0);
        vector<int> v2(10,0);

        int x = 0;
        int y = 0;
        int n = secret.size();

        for(int i = 0; i < n; i++)
        {
            if(secret[i] == guess[i]) x++;

            v1[secret[i] - '0']++;
            v2[guess[i] - '0']++;
        }

        for(int j = 0; j < 10; j++)
        {
            y += min(v1[j], v2[j]);
        }

        y -= x;

        return to_string(x) + "A" + to_string(y) + "B";
    }
};
