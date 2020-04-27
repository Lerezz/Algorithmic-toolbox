n = int(input())
num_list = [int(i) for i in input().split()]


def compare(digit, max_digit):
    return int(str(digit)+str(max_digit))>=int(str(max_digit)+str(digit))

def largestnumber(lst):
    answer = []
    
    while num_list!=[]:
        max_digit = 0
        for digit in lst:
            if compare(digit, max_digit):
                max_digit = digit
        answer.append(max_digit)
        num_list.remove(max_digit)

    return answer

print(''.join([str(i) for i in largestnumber(num_list)]))
