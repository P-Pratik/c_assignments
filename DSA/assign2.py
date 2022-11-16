'''Write a python program to compute the following operations on String
a) To display word with the longest length
b) To determine the frequency of occurance of particular charecter in string
c) To check whether given string is palindrome or not
d) To display index of first appearance
e) To count the occurences of each word in a given string '''

sentence=input()
n=len(sentence)

def l_word():
    arr=sentence.split()
    mc=0
    for i in range (len(arr)):
        count=len(arr[i])
        if count>=mc:
            mc=count
            word=arr[i]
    return mc,word

def freq_c(x):
    count=0
    for i in range(n):
        if x==sentence[i]:
            count+=1
    return count

def palindrome():
    palin=sentence[::-1]
    if palin==sentence:
        return True
    else:
        return False

def sub_str(y):
    k="substring does not exist"
    for i in range(n):
        count=0
        for j in range(len(y)):
            if y[0]==sentence[i]:
                if y[j]==sentence[i+j]:
                    count+=1
                else:
                    return k
            else:
                return k
    if count==len(y):
        return i

def c_word():
    arr=sentence.split()
    mc=0
    for i in range (len(arr)):
        count=0
        for j in range():
            print()

def main():
    len,word=l_word()
    print(word,len)
    x=input()
    print(freq_c(x))
    print(palindrome())
    y=input()
    print(sub_str(y))
main()