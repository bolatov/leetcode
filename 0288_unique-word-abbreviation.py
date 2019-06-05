class ValidWordAbbr:

    def _abbr(self, word):
        if len(word) <= 2:
            return word
        return f'{word[0]}{str(len(word)-2)}{word[-1]}'

    """
    @param: dictionary: a list of words
    """
    def __init__(self, dictionary):
        # do intialization if necessary
        self.table = {}
        for word in set(dictionary):
            key = self._abbr(word)
            self.table.setdefault(key, []).append(word)
        print(self.table)

    """
    @param: word: a string
    @return: true if its abbreviation is unique or false
    """
    def isUnique(self, word):
        # write your code here
        key = self._abbr(word)
        if key not in self.table:
            return True
        return len(self.table[key]) == 1 and self.table[key][0] == word

# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param = obj.isUnique(word)
