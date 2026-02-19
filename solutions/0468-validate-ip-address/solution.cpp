class Solution {
public:
    string validIPAddress(string IP) {

        regex ipv4("^\\d{1,3}(\\.\\d{1,3}){3}$");
        regex ipv6("^([0-9a-fA-F]{1,4})(:([0-9a-fA-F]{1,4})){7}$");

        if(regex_match(IP, ipv4)) {

            stringstream ss(IP);
            string part;

            while(getline(ss, part, '.')) {
                if(part.size() > 1 && part[0] == '0') return "Neither";
                int x = stoi(part);
                if(x > 255) return "Neither";
            }

            return "IPv4";
        }

        if(regex_match(IP, ipv6)) return "IPv6";

        return "Neither";
    }
};
