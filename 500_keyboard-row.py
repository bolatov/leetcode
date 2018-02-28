rows = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']
def check(w):
    st = set()
    for ch in w:
        for i in range(len(rows)):
            if ch in rows[i]:
                st.add(i)
    return len(st) == 1

class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        return [w for w in words if check(w)]