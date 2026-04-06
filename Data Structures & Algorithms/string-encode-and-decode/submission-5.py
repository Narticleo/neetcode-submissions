class Solution:

    def encode(self, strs: List[str]) -> str:
        result=""
        for s in strs:
            result += (str(len(s)) + '#' + s)
        return result
    
    def decode(self, s: str) -> List[str]:
        strs = []
        start = 0
        while(start<len(s)):
            sign = s.find('#', start)
            num = int(s[start:sign])
            strs.append(s[sign+1:sign+1+num])
            start = sign + num + 1
        return strs