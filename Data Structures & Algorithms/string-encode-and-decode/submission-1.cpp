class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded_string;
        for(const auto&s : strs) {
            encoded_string += to_string(s.size());
            encoded_string += "-";
            encoded_string += s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        string tmp;
        int frq = -1;
        bool flag = false;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '-') {
                // frq = 5;
                frq = stoi(tmp);
                tmp.clear();
                flag = true;
                continue;
            }
            if(flag) {
                if(!frq) decoded_strs.emplace_back();
                else {
                    while(frq--) {
                        tmp += s[i];
                        i++;
                    }
                    decoded_strs.push_back(tmp);
                }
                tmp.clear();
                flag = false;
                frq = -1;
            }
            tmp += s[i];
        }
        if(frq > -1) decoded_strs.emplace_back();
        return decoded_strs;
    }
};
