class Solution:
    def titleToNumber(self, s: str) -> int:
        res = 0;
        for letter in s:
            res = res * 26 + ord(letter) - 64  # ord('A')=65
        return res


def main():
    s="AB"
    ans=Solution().titleToNumber(s)
    print(ans)

if __name__=='__main__':
    main()
