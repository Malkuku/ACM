def solve():
    n = int(input())
    x = 0
    y = 0
    turn = 0
    for i in range(n):
        input_line = input().strip().split()  # 读取一行输入并分割成列表
        ch = input_line[0]  # 第一个元素是字符 ch
        xx = int(input_line[1])  # 第二个元素是整数 xx
        if ch == 'F':
            if turn == 0:
                x += xx
            elif turn == 1:
                y += xx
            elif turn == 2:
                x -= xx
            elif turn == 3:
                y -= xx
        elif ch == 'B':
            turn = (turn + 2) % 4
            if turn == 0:
                x += xx
            elif turn == 1:
                y += xx
            elif turn == 2:
                x -= xx
            elif turn == 3:
                y -= xx
        elif ch == 'L':
            turn = (turn + 1) % 4
            if turn == 0:
                x += xx
            elif turn == 1:
                y += xx
            elif turn == 2:
                x -= xx
            elif turn == 3:
                y -= xx
        elif ch == 'R':
            turn = (turn + 3) % 4
            if turn == 0:
                x += xx
            elif turn == 1:
                y += xx
            elif turn == 2:
                x -= xx
            elif turn == 3:
                y -= xx
    print(x, y, turn)

t = int(input())
for _ in range(t):
    solve()