# def check_REF(A:set, R:set):
#     for a in A :
#         if (a, a) not in R: return False
#     return True

# def check_SIM(R:set):
#     for a, b in R:
#         if (b, a) not in R: return False
#     return True

# def check_ANTI(R:set):
#     for a, b in R:
#         if (b, a) in R and b != a: return False
#     return True

def check_TRANS(A:list, R:set, ADJ:list):
    for a in A: # check the relations for each a
        for b in ADJ[a]: # b relations of a
            for c in ADJ[b]: # c relations of b
                if (a,c) not in R: return False
    return True

n, m = map(int, input().split())
A = list(range(n)) # because A is used often
R = [] # This is Stephen's Free Style Implemntation TM

ADJ = [[] for _ in A] # adjacency matrix for transitive check
for _ in range(m): 
    a, b = map(int, input().split())
    ADJ[a].append(b) # list of b integers that are related to a
    R.append((a, b)) # list of each relation in R
R = set(R)

REF = all((a,a) in R for a in A)
SIM = all((b,a) in R for a, b in R)
ANTI = all((b, a) not in R or a == b for a, b in R)
TRANS = check_TRANS(A, R, ADJ)

print("Refleksif." if REF else "Tidak Refleksif.")
print("Simetris." if SIM else "Tidak Simetris.")
print("Antisimetris." if ANTI else "Tidak Antisimetris.")
print("Transitif." if TRANS else "Tidak Transitif.")