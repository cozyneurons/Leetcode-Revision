class Solution {
public:
    int myAtoi(string s) 
    {
        long ans = 0;
        int n = s.size();
        int i = 0;
        bool negative = false;

        while(i<n && s[i]==' ')
        {
            i++;
        }

        if(i<n && (s[i]=='-' || s[i]=='+'))
        {
            if(s[i]=='-') negative = true;
            i++;
        }

        while(i<n && isdigit(s[i]))
        {
            ans = ans*10 + (s[i]-'0');

            if(!negative && ans > INT_MAX)
                return INT_MAX;

            if(negative && -ans < INT_MIN)
                return INT_MIN;

            i++;
        }

        if(negative) ans = -ans;

        return ans;
    }
};
