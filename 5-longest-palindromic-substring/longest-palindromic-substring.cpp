// class Solution {
// public:
//     string longestPalindrome(string s) {

//         int n = s.size();
//         if(n==1){
//             return s;
//         }
//         if(n==2 && s[0]!=s[1]){
//             return s[0];
//         }
//         vector<vector<int>> t(n , vector<int>(n,false));
//         int maxlen = 0;
//         int start = 0;
//         for(int i = 0;i<n;i++){
//             t[i][i] = true;
            
//         }

//         for(int i  = 0;i<n-1;i++){
//             if(s[i]==s[i+1]){
//                 t[i][i+1] = true;
//                 maxlen = 2;
//                 start = i;
//             }
//         }


//         for(int L = 3;L<=n;L++){
//             for(int i = 0;i<n-L+1;i++){
//                 int j = L+i-1;
//                 if(s[j]==s[i]  && t[i+1][j-1]== true){
//                     t[i][j] = true;


//                     if(L>maxlen){
//                         maxlen  = L;
//                         start = i;
//                     }
//                 }
//             }
//         }

//         string ans = s.substr(start ,maxlen);
//         return ans;
        
//     }
// };
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> t(n, vector<bool>(n, false));
        int maxlen = 1;
        int start = 0;

        // Single chars are palindrome
        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }

        // Check substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                t[i][i + 1] = true;
                start = i;
                maxlen = 2;
            }
        }

        // Check substrings of length >= 3
        for (int L = 3; L <= n; L++) {
            for (int i = 0; i < n - L +1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j] && t[i + 1][j - 1]) {
                    t[i][j] = true;
                    if (L > maxlen) {
                        maxlen = L;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }
};
