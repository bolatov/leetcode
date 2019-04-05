class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        pos = 0
        for ch in name:
            pos = typed.find(ch, pos)
            if pos < 0:
                return False
            pos += 1
        return True
