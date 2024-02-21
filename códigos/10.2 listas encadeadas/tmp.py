def rollingHash(s,m):
    sum = 0
    for c in s:
        sum = (sum * 128 + ord(c)) % m
    return sum

def rollingHash2(s,m):
    r = len(s)
    sum = 0
    for i in range(0,r):
        sum = (sum * 128 + ord(s[i])) % m
    return sum

def hash(s,m):
    r = len(s)
    sum = 0
    for i in range(0,r):
        sum+=ord(s[i])*128**(r-1-i)
    return sum % m


s=input('string to hash: ')
m=17
print(rollingHash(s,m),rollingHash2(s,m),hash(s,m))