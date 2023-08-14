class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if p == '.*':
            return True

        i, j = 0, 0
        len_s = len(s)
        len_p = len(p)

        while j < len_p:
            # if p[j] is a character
            if p[j] not in ['.', '*']:
                # check if the next is *
                if j + 1 < len_p:
                    if p[j + 1] == "*":
                        prev = p[j]
                        j += 1
                        # check if there are repeating prev character
                        while i < len_s:
                            if s[i] != prev:
                                break
                            i += 1
                        i += 1
                        j += 1
                    else:
                        pass
                else:
                    pass

                if s[i] != p[j]:
                    return False
                else:
                    i += 1
                    j += 1

            elif p[j] == '.':
                i += 1
                j += 1
        
        # if we have not seen all of s
        if i < len_s:
            return False
        
        return True

