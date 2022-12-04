def partion(arr,low, high):
    pivot  = arr[low]
    i = low
    j = high

    while(i<j):
        
        while(arr[i]<=pivot):
            if(i<high): 
                i += 1
            else:
                break

        while(arr[j]>pivot): j -= 1

        if(i<j):
            arr[i], arr[j] = arr[j], arr[i]

    arr[low], arr[j] = arr[j], arr[low]

    return arr

print(partion([10,5,2,9,3,8,4,1], 0, 7))