class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) 
    {
        int n = events.size();
        int score = 0;
        int counter = 0;
        for (int i = 0; i<n; i++)
            {
                if (events[i]=="0"|| events[i]=="1" || events[i]=="2"
                   || events[i]=="3" || events[i]=="4" || events[i]=="5" 
                   || events[i] =="6")
                {
                
                    int num = stoi(events[i]);
                    score+=num;
                }
                    else if (events[i]=="W") counter++;
                else score+=1;
                if (counter==10) break;
            }
        return {score,counter};
    }
};
