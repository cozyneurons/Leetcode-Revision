class Solution {
private:
    int result = 0;
    void concatenate(vector<string>& arr, string& ans, vector<int>& chars, int index)
    {
        result = max(result, (int)ans.size());
        for (int i = index; i < arr.size(); i++)
        {
            string& s = arr[i];
            vector<int> temp = chars;
            bool valid = true;
            for (char c : s)
            {
                if (temp[c - 'a'] == 1)
                {
                    valid = false;
                    break;
                }
                temp[c - 'a'] = 1;
            }
            if (valid)
            {
                ans += s;
                concatenate(arr, ans, temp, i + 1);
                ans.resize(ans.size() - s.size());
            }
        }
    }

public:
    int maxLength(vector<string>& arr) 
    {
        vector<int> chars(26, 0);
        string ans = "";

        concatenate(arr, ans, chars, 0);
        return result;
    }
};
