class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        myJewels = 0
        setJewels = set(J)
        for item in S:
        	if item in setJewels:
        		myJewels = myJewels + 1

        return myJewels

myS = Solution()
#print myS.numJewelsInStones("abc","abcqccbev")
print (myS.numJewelsInStones("abc","abcqccbev"))
