
def main():
	n = int(input())
	res = n * (n - 1) * (n - 2) // 6 + (n - 4) * (n - 1) * (n - 2) * (n - 3) // 24
	res %= 987654321
	print(res)

main()