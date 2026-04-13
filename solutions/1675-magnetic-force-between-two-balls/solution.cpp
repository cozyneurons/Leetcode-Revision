class Solution {
private:
    bool sahiHai(vector<int>& position, int m, int mid)
{
    int count = 1;
    int lastPos = position[0];

    for (int i = 1; i < position.size(); i++)
    {
        if (position[i] - lastPos >= mid)
        {
            count++;
            if (count >= m) return true;
            lastPos = position[i];
        }
    }
    return false;
}
public:
    int maxDistance(vector<int>& position, int m) 
    {
        int n = position.size();
        sort(position.begin(),position.end());
        if (m==2) return position[n-1] - position[0];
        int low = n/m;
        int high = position[n-1]-position[0];
        int ans = 0;
        while (low<=high)
        {
            int mid = low + (high-low)/2;
            if (sahiHai(position, m, mid))
            {
                ans = mid;
                low = mid + 1; 
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
