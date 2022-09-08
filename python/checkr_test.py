

'''
f(0) = 0
f(1) = 1
f(n) = f(n-1) + f(n-2) for n > 1
 
 Sample examples for f(0) to f(12)...
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
'''

def fibonnaci(n):
	sum_ = 0
	if n == 0 or n == 1:
		return n
	else:
		sum_ += fibonnaci(n-1) + fibonnaci(n-2)
		return sum_
	pass

def fibonaci2(n):
	sum_ = 0
	fib1 = 0
	fib2 = 1

	for i in range(0, n):
		sum_ = fib1 + fib2
		fib1 = fib2
		fib2 = sum_

	return sum_;
