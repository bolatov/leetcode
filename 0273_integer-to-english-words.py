digits = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine']
teens = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
tens = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety'] 

class Solution:
        
    def toWord(self, num):
        tokens = []
        if num >= 1_000_000_000:
            quotient, num = divmod(num, 1_000_000_000)
            tokens.append(digits[quotient])
            tokens.append('Billion')
            
        if num >= 1_000_000:
            quotient, num = divmod(num, 1_000_000)
            _tokens = self.toWord(quotient)
            tokens.extend(_tokens)
            tokens.append('Million')
            
        if num >= 1000:
            quotient, num = divmod(num, 1000)
            _tokens = self.toWord(quotient)
            tokens.extend(_tokens)
            tokens.append('Thousand')
            
        if num >= 100:
            quotient, num = divmod(num, 100)
            tokens.append(digits[quotient])
            tokens.append('Hundred')
        if num >= 20:
            quotient, num = divmod(num, 10)
            tokens.append(tens[quotient])
            tokens.append(digits[num])
        elif num >= 10:
            quotient, num = divmod(num, 10)
            tokens.append(teens[num])
        else:
            tokens.append(digits[num])
        return tokens
            
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return 'Zero'
        tokens = self.toWord(num)
        return ' '.join([t for t in tokens if t])
