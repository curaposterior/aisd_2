#!/usr/bin/python3 
#https://pl.wikipedia.org/wiki/Algorytm_Knutha-Morrisa-Pratta

def kmp_table(word: str):
    n = len(word)
    T = [0] * n
    i = 2
    j = 0
    
    T[0] = -1
    T[1] = 0
    while i < n:
        if (word[i - 1] == word[j]):
            T[i] = j+1
            i += 1
            j += 1
        else:
            if (j > 0):
                j = T[j]
            else:
                T[i] = 0
                i += 1
    return T

def kmp_search(s: str, w: str) -> int:
    m = 0
    i = 0
    
    T = kmp_table(w)

    while m + i < len(s):
        if w[i] == s[m + i]:
            i += 1
            if i == len(w):
                return m
        else:
            m = m + i - T[i]
            if i > 0:
                i = T[i]

    return len(s)


if __name__ == "__main__":

    assert kmp_search("simeaneiu adfa fdsfs", "ean") == 3 #should return 3
    print(kmp_search("simeaneiu adfa fdsfs", "ean"))