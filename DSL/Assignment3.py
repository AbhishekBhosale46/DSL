'''
Write a python program to compute following computation on matrix:
a) Addition of two matrices
b) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix
'''

matrix1 = [[1, 2, 3],
           [0, 0, 0]]

matrix2 = [[0, 0, 0],
           [1, 1, 1]]


def add(mat1, mat2):
    result = []
    if len(mat1) != len(mat2):
        return -1
    elif len(mat1[0]) != len(mat2[0]):
        return -1
    else:
        for i in range(len(mat1)):
            row = []
            for j in range(len(mat2[0])):
                row.append(mat1[i][j] + mat2[i][j])
            result.append(row)
        return result


def sub(mat1, mat2):
    result = []
    if len(mat1) != len(mat2):
        return -1
    elif len(mat1[0]) != len(mat2[0]):
        return -1
    else:
        for i in range(len(mat1)):
            row = []
            for j in range(len(mat2[0])):
                row.append(mat1[i][j] - mat2[i][j])
            result.append(row)
        return result


matrixa = [[1, 2, 3],
           [0, 0, 0]]

matrixb = [[0, 1],
           [1, 1],
           [0, 1]]


def multi(mat1, mat2):
    result = []
    if len(mat1[0]) != len(mat2):
        return -1
    else:


print(sub(matrix1, matrix2))
