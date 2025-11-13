"""
Problem 6.4: Word Break with Dictionary

You are given a string of n characters s[1...n], which you believe to be a 
corrupted text document in which all punctuation has vanished (so that it 
looks something like "itwasthebestoftimes..."). You wish to reconstruct the 
document using a dictionary, which is available in the form of a Boolean 
function dict(·): for any string w,

                    { true   if w is a valid word
         dict(w) =  {
                    { false  otherwise.

(a) Give a dynamic programming algorithm that determines whether the string 
    s[·] can be reconstituted as a sequence of valid words. The running time 
    should be at most O(n²), assuming calls to dict take unit time.

(b) In the event that the string is valid, make your algorithm output the 
    corresponding sequence of words.
"""


s = "itwasthebestoftimes"
def dict(word):
    valid_words = {
        "it",
        "was",
        "the",
        "best",
        "of",
        "times"
    }
    return word in valid_words

n = len(s)


def f(s):
	if len(s) == 0:
		return True

	for j in range(1, len(s) + 1):
		if dict(s[:j]) and f(s[j:]):
			return True

	return False


# memo: s[ind:] can be reconstituted or not
memo = [None] * (n + 1)
memo[n] = True

def f(s, memo):
	return recursion(0)

def recursion(ind):
	if ind == n:
		return True

	if memo[ind] is not None:
		return memo[ind]

	for j in range(ind + 1, n + 1):
		if dict(s[ind:j]) and recursion(j):
			memo[ind] = True
			return True

	memo[ind] = False
	return False


# bottom-up dp: from right to left
dp = [False] * (n + 1)  # dp[i] signifies s[i:] can be reconstituted or not

# Base case: s[n:], which is the empty string, 
dp[n] = True

def f(s, dp):
	for i in range(n - 1, -1, -1):
		for j in range(i + 1, n + 1):  # Traverse all cutting points
			if dict(s[i:j]) and dp[j]:  # dp[j] means s[j:] can be reconstituted
				dp[i] = True
				break

	return dp[0]


def wordBreak(s, dict):
    n = len(s)
    dp = [False] * (n + 1)
    next_cut = [-1] * (n + 1)
    dp[n] = True
    
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n + 1):
            if dict(s[i:j]) and dp[j]:
                dp[i] = True
                next_cut[i] = j
                break
    
    if not dp[0]:
        return []
    
    result = []
    i = 0
    while i < n:
        j = next_cut[i]
        result.append(s[i:j])
        i = j
    
    return result

# 测试
s = "itwasthebestoftimes"
words = {"it", "was", "the", "best", "of", "times"}
print(wordBreak(s, lambda w: w in words))
# 输出：['it', 'was', 'the', 'best', 'of', 'times']
