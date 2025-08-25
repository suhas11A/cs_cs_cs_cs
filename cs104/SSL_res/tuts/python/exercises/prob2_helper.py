def matmul(A,B):
    # TODO: Implement matrix multiplication
    pass

def display_matrix(A):
    for row in A:
        print(row)

if __name__ == "__main__":
    A = [[1,2,3],[4,5,6],[7,8,9]]
    B = [[3,1,2],[9,10,1],[4,5,6]]
    print("A:")
    display_matrix(A)
    print("B:")
    display_matrix(B)

    C = matmul(A,B)
    print("C = AB:")
    display_matrix(C)