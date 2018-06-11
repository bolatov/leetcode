class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.mp = {}
        
    def buildDict(self, dict):
        """
        Build a dictionary through a list of words
        :type dict: List[str]
        :rtype: void
        """
        for s in dict:
            if not s: continue
            s += '$'
            if s[0] not in self.mp: self.mp[s[0]] = MagicDictionary()
            md = self.mp[s[0]]
            for i in range(1, len(s)):
                if s[i] not in md.mp: md.mp[s[i]] = MagicDictionary()
                md = md.mp[s[i]]

    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        def dfs(md, word, k):
            if not md: return False
            if not word: return k == 0
            
            return (word[0] != '$' and any(dfs(md.mp[key], word[1:], k - 1) for key in md.mp.keys() if key != word[0])) \
                    or dfs(md.mp.get(word[:1]), word[1:], k)
        if not word: return False
        word += '$'
        return dfs(self, word, 1)


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
