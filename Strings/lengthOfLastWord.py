class Solution:
    def lengthOfLastWord(self, s: str) -> int:

        # remove the leading and trailing white spaces 
        strippedstr = s.strip()
        print(strippedstr)
        # split divides the string and stored it as different string based on a charcter 
        words = strippedstr.split(' ')
        print(words)

        return len(words[-1])