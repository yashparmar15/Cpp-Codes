/*Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true*/


class Solution {
public:
    bool isLongPressedName(string a, string b) {
        if(b.size() < a.size())
            return 0;
        if(b == a)
            return 1;
        int a1 = 0;
        int b1 = 0;
        while(a1 < a.size() && b1 < b.size()){
            if(a[a1] != b[b1])
                return false;
            while(a1 < a.size() and b1 < b.size() and a[a1] == b[b1]){
                a1++;
                b1++;
            }
            a1--;
            b1--;
            char c = b[b1];
            while(b1 < b.size() and b[b1] == c)
                b1++;
            a1++;
        }
        if(a1 < a.size() || b1 < b.size())
            return 0;
        return 1;
    }
};
