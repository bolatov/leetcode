class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.mp = {}
        self.val = 0

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: void
        """ 
        if key[0] not in self.mp:
            self.mp[key[0]] = MapSum()
        ms = self.mp[key[0]]
        for i in range(1, len(key)):
            if key[i] not in ms.mp:
                ms.mp[key[i]] = MapSum()
            ms = ms.mp[key[i]]
        ms.val = val

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        ms = self.mp.get(prefix[0], None)
        
        for i in range(1, len(prefix)):
            if not ms: return 0
            ms = ms.mp.get(prefix[i], None)
        if not ms: return 0
        
        def dfs(node):
            if not node: return 0
            r = node.val
            for child_node in node.mp.values():
                r += dfs(child_node)
            return r
        return dfs(ms)


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
