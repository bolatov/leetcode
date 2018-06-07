class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        def f(s):
            be, en = s.find('('), s.find(')')
            return s[be:en+1], s[:be]
        mp, result = {}, []
        for path in paths:
            splits = path.split()
            folder, files = splits[0], splits[1:]
            for file in files:
                content, fname = f(file)
                fullname = "{}/{}".format(folder, fname)
                if content not in mp: mp[content] = []
                mp[content].append(fullname)
        for content, filenames in mp.items(): 
            if len(filenames) > 1: result.append(filenames)
        return result
