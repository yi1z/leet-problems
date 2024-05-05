class Solution:

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        columns = {
            0:[],
            1:[],
            2:[],
            3:[],
            4:[],
            5:[],
            6:[],
            7:[],
            8:[]
        }
        boxes = {
            0:[],
            1:[],
            2:[],
            3:[],
            4:[],
            5:[],
            6:[],
            7:[],
            8:[]
        }

        # get the columns
        for i in range(9):
            for row in board:
                if row[i] != '.':
                    columns[i].append(row[i])
        
        # get the boxes
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                for m in range(i, i + 3):
                    for n in range(j, j + 3):
                        if board[m][n] != '.':
                            boxes[i + j // 3].append(board[m][n])

        for i in range(9):
            counter = Counter(board[i])
            for j in counter.keys():
                if j != ".":
                    if counter[j] > 1:
                        return False

            counter = Counter(columns[i])
            for j in counter.keys():
                if counter[j] > 1:
                    return False

            counter = Counter(boxes[i])
            for j in counter.keys():
                if counter[j] > 1:
                    return False

        return True
