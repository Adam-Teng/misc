def brute_range(lst, a, b):
    x = len(lst)
    for i in range(len(lst)):
        if a <= lst[i]:
            x = i
            break
    if x < len(lst) - 1:
        lst = lst[x:]
        for i in range(len(lst)):
            if b < lst[i]:
                return i
        return len(lst)
    return 0


def binary_search_a(lst, a, x, y):
    if a <= lst[x]:
        return x
    if a > lst[y]:
        return y + 1
    if a == lst[y]:
        return y
    if a <= lst[(x+y)//2] and a > lst[(x+y)//2-1]:
        return (x+y)//2
    elif a <= lst[(x+y)//2-1]:
        return binary_search_a(lst, a, x, (x+y)//2-1)
    else:
        return binary_search_a(lst, a, (x+y)//2, y)


def binary_search_b(lst, a, x, y):
    if a < lst[x]:
        return x
    if a == lst[x]:
        return x + 1
    if a >= lst[y]:
        return y + 1
    if a < lst[(x+y)//2+1] and a >= lst[(x+y)//2]:
        return (x+y)//2+1
    elif a < lst[(x+y)//2]:
        return binary_search_b(lst, a, x, (x+y)//2)
    else:
        return binary_search_b(lst, a, (x+y)//2+1, y)


def binary_search_iteration(lst, a, x, y):
    mid = 0
    while x < y:
        mid = (x+y) >> 1
        if a < lst[mid]:
            y = mid
        else:
            x = mid+1
    return x-1


print(brute_range([0, 1, 3, 7, 9, 11], 0, 8))
print(binary_search_b([0, 1, 3, 7, 9, 11], 8, 0, 5) -
      binary_search_a([0, 1, 3, 7, 9, 11], 0, 0, 5))

# a 7->3
# b 7->4
