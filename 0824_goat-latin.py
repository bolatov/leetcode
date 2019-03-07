class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        words = S.split()
        vowels = {'a', 'e', 'i', 'o', 'u'}
        for i in range(len(words)):
            w = words[i]
            if w[0].lower() not in vowels:
                words[i] = w[1:] + w[0]
            words[i] += "ma"
            words[i] += "a" * (i + 1)
        return ' '.join(words)