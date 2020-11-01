/*
Suppose we have a file system that stores both files and directories.
If we were to write this representation in code, it will look like this: "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext". 
Note that the '\n' and '\t' are the new-line and tab characters. Every file and directory has a unique absolute path in the file system, which is the order of directories that 
must be opened to reach the file/directory itself, all concatenated by '/'s. Using the above example, the absolute path to file2.ext is "dir/subdir2/subsubdir2/file2.ext". 
Each directory name consists of letters, digits, and/or spaces. Each file name is of the form name.extension, where name and extension consist of letters, digits, and/or spaces.
Given a string input representing the file system in the explained format, return the length of the longest absolute path to a file in the abstracted file system. 
If there is no file in the system, return 0.
Input: input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
Output: 20
Explanation: We have only one file, and the absolute path is "dir/subdir2/file.ext" of length 20.

Input: input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
Output: 32
Explanation: We have two files:
"dir/subdir1/file1.ext" of length 21
"dir/subdir2/subsubdir2/file2.ext" of length 32.
We return 32 since it is the longest absolute path to a file.

Input: input = "a"
Output: 0
Explanation: We do not have any files, just a single directory named "a".

Input: input = "a"
Output: 0
Explanation: We do not have any files, just a single directory named "a".

1 <= input.length <= 104
input may contain lowercase or uppercase English letters, a new line character '\n', a tab character '\t', a dot '.', a space ' ', and digits.
*/
class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> s;
        int maxlen = 0;
        int index = 0;
        int counter = 0;
        while(true){
            int start = index;
            index = input.find('\n', start);
            string token = "";
            if(index != string::npos)
                token = input.substr(start, (index - start));
            else
                token = input.substr(start);
            
            int level = 0;
            for(int idx = 0; idx < token.length(); idx++){
                if(token[idx] == '\t'){
                    level++;
                } else {
                    break;
                }
            }
            token = token.substr(level);
            while(s.size() > level){
                string top = s.top();
                s.pop();
                counter -= top.length();
            }
            
            bool isFile = (token.find(".") == string::npos) ? false : true;
            if(isFile){
                int len = counter + s.size() + token.length();
                maxlen = max(maxlen, len);
            } else {
                s.push(token);
                counter += token.length();
            }
            if(index == string::npos) break;
            index++;
            if(index >= input.length()) break;
        }
        
        return maxlen;
    }
};
