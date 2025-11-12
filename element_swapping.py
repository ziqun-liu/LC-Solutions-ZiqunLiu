def getMaximumSumOfStrengths(arr):
    n = len(arr)
    if n == 0:
        return 0
    if n == 1:
        return arr[0]

    dp = [[0] * 2 for _ in range(n)]
    
    for i, num in enumerate(arr):
        if i == 0:
            dp[0][0] = dp[0][1] = arr[0]
        elif i == 1:
            res0 = arr[0] + arr[i] * (i + 1)
            res1 = arr[i] * i + arr[i - 1] * (i + 1)
            dp[i][0] = res0
            dp[i][1] = res1
        else:
            res0 = max(dp[i - 1][0], dp[i - 1][1]) + arr[i] * (i + 1)
            res1 = dp[i - 1][0] - arr[i - 1] * i + arr[i] * i + arr[i - 1] * (i + 1)
            dp[i][0], dp[i][1] = res0, res1
    
    return max(dp[n - 1][0], dp[n - 1][1]) 