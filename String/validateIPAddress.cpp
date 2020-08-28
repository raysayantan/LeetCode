/*
Given a string IP. We need to check If IP is a valid IPv4 address, valid IPv6 address or not a valid IP address.
Return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a valid IP of any type.
A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" 
are valid IPv4 addresses but "192.168.01.1", "192.168.1.00" and "192.168@1.1" are invalid IPv4 adresses.
A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

1 <= xi.length <= 4
xi is hexadecimal string whcih may contain digits, lower-case English letter ('a' to 'f') and/or upper-case English letters ('A' to 'F').
Leading zeros are allowed in xi.
For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses but "2001:0db8:85a3::8A2E:037j:7334" and 
"02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

 

Example 1:

Input: IP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:

Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:

Input: IP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
Example 4:

Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334:"
Output: "Neither"
Example 5:

Input: IP = "1e1.4.5.6"
Output: "Neither"
 

Constraints:

IP consists only of English letters, digits and the characters '.' and ':'.
*/
class Solution {
    bool isValidIP4String(string ip){
        if(ip.length() < 1){
            return false;
        }
        //This function will determine string can fit in IP4 addressing
        if(ip[0] == '0' && ip.length() > 1){
            return false;
        }
        
        //check if it contains other than digit
        for(int i = 0; i < ip.length(); i++){
            if(ip[i] >= '0' && ip[i] <= '9'){
                continue;
            } else {
                return false;
            }
        }
        
        int ipIntValue;
        try{
            ipIntValue = stoi(ip);
        } catch(...){
            return false;
        }
        if(ipIntValue < 0 || ipIntValue > 255){
            return false;
        }
        
        return true;
    }
    
    bool isValidIP6string(string ip){
        //This will check a string can fit in IP6 addressing
        if(ip.length() < 1 || ip.length() > 4){
            return false;
        }
        
        for(int i = 0; i < ip.length(); i++){
            if(ip[i] >= '0' && ip[i] <= '9'){
                continue;
            } else if(ip[i] >= 'a' && ip[i] <= 'f'){
                continue;
            } else if(ip[i] >= 'A' && ip[i] <= 'F'){
                continue;
            } else {
                return false;
            }
        }
        
        return true;
    }
    void splitToken(string ip, vector<string> &ipToken){
        stringstream ss(ip);
        if(ip.find(".") != string::npos){
            //split ip4 tokens
            while(ss.good()){
                string token;
                getline(ss, token, '.');
                ipToken.push_back(token);
            }
        } else if(ip.find(":") != string::npos){
            //ip6
            while(ss.good()){
                string token;
                getline(ss, token, ':');
                ipToken.push_back(token);
            }
        }
    }
public:
    string validIPAddress(string IP) {
        //split the string into ip token with delimiter ':'
        vector<string> ipToken;
        splitToken(IP, ipToken);
        string address = "Neither";
        bool isValid = true;
        if(ipToken.size() == 4){
            //Need to check for IP4 addressing
            address = "IPv4";
            for(int i = 0; i < ipToken.size(); i++){
                isValid = isValidIP4String(ipToken[i]);
                if(isValid == false){
                    address = "Neither";
                    break;
                }
            }
        } else if(ipToken.size() == 8){
            //Need to check for IP6 addressing
            address = "IPv6";
            for(int i = 0; i < ipToken.size(); i++){
                isValid = isValidIP6string(ipToken[i]);
                if(isValid == false){
                    address = "Neither";
                    break;
                }
            }
        } else {
            address = "Neither";
        }
        
        return address;
    }
};
