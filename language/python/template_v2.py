from sys import stdin, stdout

# Update recursion limit
#from sys import setrecursionlimit, getrecursionlimit
#setrecursionlimit(1000000)
#print(getrecursionlimit())

def input(): 
    return stdin.readline()


# use f-string
def print(inp, end='\n'):
    stdout.write(inp+end)


# for genearing all possible & all permutation solution
def gen_comb(N: int, permute:bool=False):
    from itertools import permutations as permutations
    for i in range(1 << N):
        p = []

        for j in range(N):
            if i & (1 << j) > 0:
                p.append(j)
        
        if len(p) == 0: continue

        for perm in permutations(p):
            yield perm

# ---------------------- Code Starts ----------------------

print(f"This is a {12}")