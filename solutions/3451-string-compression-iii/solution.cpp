class Solution {
public:
    string compressedString(string word) 
    {
        int n = word.size();
        string comp;
        int i = 0;
        while (i<n)
        {
            char current_char=word[i];
            int count = 0;
            while (current_char==word[i])
            {
                count++;
                i++;
            }
            if (count<=9)
            {
                string cnt = to_string(count);
                comp.push_back(cnt[0]);
                comp.push_back(current_char);
            }
            else 
            {
                while (count>9)
                {
                    count = count - 9;
                    string cnt = to_string(9);
                    comp.push_back(cnt[0]);
                    comp.push_back(current_char);
                }
                string cnt = to_string(count);
                comp.push_back(cnt[0]);
                comp.push_back(current_char);
            }   
        }
        return comp;
    }
};


