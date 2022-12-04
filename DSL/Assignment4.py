def linear(arr, key):
    index = -1
    for i in range(len(arr)):
        if (arr[i] == key):
            index = i
    return index


def sentinel(arr, key):
    index = -1
    temp = arr[len(arr)-1]
    arr[len(arr)-1] = key
    i = 0
    while (arr[i] != key):
        i += 1
    arr[len(arr)-1] = temp
    if (i < len(arr)-1 or arr[len(arr)-1] == key):
        index = i
    return index


def binaryIterative(arr, key):
    start = 0
    end = len(arr)-1
    arr.sort()
    while (start <= end):
        mid = (start+end)//2
        if (arr[mid] < key):
            start = mid+1
        elif (arr[mid] > key):
            end = mid-1
        else:
            return mid

    return -1


def binaryRecursive(arr, key, start, end):
    if (start <= end):
        mid = (start+end)//2
        if (arr[mid] == key):
            return mid
        elif (arr[mid] > key):
            return binaryRecursive(arr, key, start, mid-1)
        else:
            return binaryRecursive(arr, key, mid+1, end)
    else:
        return -1


def fibo(arr, key):
    n = len(arr)
    f2 = 0
    f1 = 1
    f = 1
    offset = -1

    while (f < n):
        f2 = f1
        f1 = f
        f = f1 + f2

    while (f2 >= 0):
        index = min(offset+f2, n-1)

        if (arr[index] < key):
            offset = index
            f = f1
            f1 = f2
            f2 = f - f1
        elif (arr[index] > key):
            f = f2
            f1 = f1-f2
            f2 = f-f1
        else:
            return index

    if (arr[n-1] == key):
        return n-1

    return -1
