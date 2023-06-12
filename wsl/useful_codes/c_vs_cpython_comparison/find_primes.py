def findPrimes(num1, num2):
    print("The Prime Numbers in ({}, {}) are:".format(num1, num2))

    for i in range(num1 + 1, num2):
        isPrime = True

        for j in range(2, i // 2 + 1):
            if i % j == 0:
                isPrime = False
                break

        if isPrime:
            print(i)

findPrimes(0, 1000000)
