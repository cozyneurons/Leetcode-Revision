// break this question into 2 parts, read and write part, both parts will be handles by two different pointers. 
class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n = chars.size();
        int index = 0;   // write pointer
        int i = 0;       // read pointer

        while (i < n)
        {
            char current = chars[i];
            int count = 0;
            while (i < n && chars[i] == current)
            {
                count++;
                i++;
            }
            chars[index++] = current;
            if (count > 1)
            {
                string cnt = to_string(count);
                for (char c : cnt)
                {
                    chars[index++] = c;
                }
            }
        }

        return index;
    }
};
