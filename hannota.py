#i：第一个柱子

#j：第二个柱子

#k：第三个柱子

def Han_No_Ta(n, i, j, k):

if (n == 1):

print(i, "->", k)

return

Han_No_Ta(n - 1, i, k, j)

Han_No_Ta(1, i, j, k)

Han_No_Ta(n -1, j, i, k)

Han_No_Ta(3, "1", "2", "3")

