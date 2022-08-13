with open("origin.txt") as f:
    l = f.readlines()

str_list = []
nums = eval(l[0])
str_list.append(" ".join(nums))

ops = eval(l[1])
for ll in ops:
    str


with open("input.txt", "w") as f:
    for str in str_list:
        f.write(str + '\n')

a