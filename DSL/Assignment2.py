'''
Perform following operations on String
a) To display word with the longest length 
b) To determines the frequency of occurrence of particular character in the string 
c) To check whether given string is palindrome or not 
d) To display index of first appearance of the substring 
e) To count the occurrences of each word in a given string
'''


class MyString:

    def __init__(self, string):
        self.string = string

    def splitWords(self, string):
        string += ' '
        wordsList = []
        word = ''
        for i in range(len(string)):
            if string[i] != ' ':
                word += string[i]
            else:
                wordsList.append(word)
                word = ''
        return wordsList

    def longestWord(self):
        string = self.string
        wordsList = self.splitWords(string)
        lenList = []
        for i in wordsList:
            lenWord = len(i)
            lenList.append(lenWord)
        maxLen = 0
        maxLenInd = -1
        for i in range(len(lenList)):
            if lenList[i] > maxLen:
                maxLen = lenList[i]
                maxLenInd = i
        return (wordsList[maxLenInd])

    def charOccurance(self, character):
        string = self.string
        freq = 0
        for i in range(len(string)):
            if character == string[i]:
                freq += 1
        return freq

    def checkPalindrome(self):
        string = self.string
        flag = False

        for i in range(len(string)//2):
            if (string[i] == string[len(string)-1-i]):
                flag = True
            else:
                flag = False

        return flag

    def indexOfSubString(self, substring):
        string = self.string
        lenSubStr = len(substring)
        lenStr = len(string)
        index = -1

        for i in range(lenStr):
            word = ''
            for j in range(lenSubStr):
                word += string[i+j]
            if word == substring:
                index = i
                break

        return index

    def wordOccurance(self):
        string = self.string
        wordList = self.splitWords(string)
        occuranceList = []
        occurances = {}

        for i in range(len(wordList)):
            freq = 0
            for j in range(len(wordList)):
                if wordList[i] == wordList[j]:
                    freq += 1
            occuranceList.append(freq)

        for i in range(len(wordList)):
            occurances[wordList[i]] = occuranceList[i]

        return occurances
