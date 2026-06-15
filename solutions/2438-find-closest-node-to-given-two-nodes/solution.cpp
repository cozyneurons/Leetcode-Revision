class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();

        vector<int> dist1(n,-1);

        vector<int> dist2(n,-1);

        int ans = -1;

        int curr1 = node1;
        int dist = 0;
        while(curr1!=-1 && dist1[curr1]==-1)
        {
            dist1[curr1] = dist;
            dist++;
            curr1 = edges[curr1];
        }

        int curr2 = node2;
        dist = 0;
        while(curr2!=-1 && dist2[curr2]==-1)
        {
            dist2[curr2] = dist;
            dist++;
            curr2 = edges[curr2];
        }

        int max_of_both = 0;
        int toto = INT_MAX;
        for (int i = 0; i<n; i++)
        {
             if (dist1[i]==-1 || dist2[i]==-1) continue;
            max_of_both = max(dist1[i],dist2[i]);
            if (max_of_both < toto)
            {
                toto = max_of_both;
                ans = i;
            }
        }

        return ans;
    }
};
