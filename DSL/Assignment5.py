# def insertion(arr):
#     for i in range(1,len(arr)):
#         temp = arr[i]
#         j = i-1
#         while(j>=0 and arr[j]>temp):
#             arr[j+1] = arr[j]
#             j -= 1
#         arr[j+1] = temp
#     return arr

# print(insertion([9,8,4,5,7]))

# def shell(arr):
#     gap = len(arr)//2
#     while(gap>0):
#         for i in range(gap, len(arr)):
#             temp = arr[i]
#             j = i
#             while(j>=gap and arr[j-gap]>temp):
#                 arr[j] = arr[j-gap]
#                 j -= gap
#             arr[j] = temp
#         gap = gap//2
#     return arr

# print(shell([1,2,3,4,5,6]))


def insertion(arr):
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i
        while (j > 0 and arr[j-1] > temp):
            arr[j] = arr[j-1]
            j = j-1
        arr[j] = temp
    return arr


def shell(arr):
    gap = len(arr)//2
    while (gap > 0):
        for i in range(gap, len(arr)):
            temp = arr[i]
            j = i
            while (j > 0 and arr[j-gap] > temp):
                arr[j] = arr[j-gap]
                j = j-gap
            arr[j] = temp
        gap = gap//2
    return arr


print(shell([9, 8, 4, 5, 7]))
