import Components
import router

# a function that converts a string into its zigzag version
def zigzag(s: str, numRows: int):
    word = {}
    for i in range(numRows):
        word[i] = {}
    # counter in the string
    k = 0
    # location in the word matrix
    i, j = 0, 0
    while k < len(s):
        while i < numRows and k < len(s):
            word[i][j] = s[k]
            i += 1
            k += 1
        if i > 0:
            i -= 1
        for n in range(numRows - 2):
            if k < len(s):
                j += 1
                i -= 1
                word[i][j] = s[k]
                k += 1
        if i > 0:
            i -= 1
        j += 1
    
    result = ""
    print(word[0].values())
    for i in range(numRows):
        for c in word[i].values():
            result += c
    return result


