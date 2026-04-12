class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) 
    {
        vector<double> ans;
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        double s = (a+b+c)/2;
        double area = sqrt(s*(s-a)*(s-b)*(s-c));
        if (area>0)
        {
            double value_a = (b*b + c*c - a*a)/(2*b*c);
            double angle_A = acos(value_a)*180.0/M_PI;
            ans.push_back(angle_A);
            
            double value_b = (a*a + c*c - b*b)/(2*a*c);
            double angle_B = acos(value_b)*180.0/M_PI;
            ans.push_back(angle_B);
            
            double value_c = (a*a + b*b - c*c)/(2*b*a);
            double angle_C = acos(value_c)*180.0/M_PI;
            ans.push_back(angle_C);
        }
        if (ans.size()>1) sort(ans.begin(),ans.end());
        return ans;
    }
};
