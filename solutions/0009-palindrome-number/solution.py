class Solution(object):
    def isPalindrome(self, x):
        s=str(x)
        n=s[::-1]
        if n==s:
            return True
        else:
            return False
        
