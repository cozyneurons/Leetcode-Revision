class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue <pair<string,int>> q;
        int n = wordList.size();
        q.push({beginWord,1});
        unordered_set <string> ump (wordList.begin(),wordList.end());
        ump.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word==endWord) return step;
            for (int i = 0; i<word.size(); i++)
            {
                char original_char = word[i];
                for ( char j = 'a'; j <= 'z'; j++)
                {
                    word[i] = j ;
                    if (ump.find(word)!=ump.end())
                    {
                        ump.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i] = original_char;
            }
        }
        return 0;
    }
};
