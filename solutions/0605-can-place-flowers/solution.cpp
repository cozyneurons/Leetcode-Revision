class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int s = flowerbed.size();
        if (s == 1 && flowerbed[0] == 0)
        {
            flowerbed[0] = 1;
            n--;
        }
        for (int i = 0;i<s; i++)
        {
            
            if (i==0 && flowerbed[i]==0 && i+1<s && flowerbed[i+1]==0)
            {
                flowerbed[i] = 1;
                n--;
            }
            else if (i>0 && i+1<s && flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0)
            {
                flowerbed[i] = 1;
                n--;
            }
            else if (i>0 && i==s-1 && flowerbed[i]==0 && flowerbed[i-1]==0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0 ? true : false;
    }
};
