import sys

def A004290(n):
    if n in (0, 1):
        return str(n)

    p = [None] * n 
    for i, ten in enumerate((pow(10, k, n) for k in range(n)), start=1):
        for j in range(n):
            if p[j] and not p[(j + ten) % n] and p[j] != i:
                p[(j + ten) % n] = i

        if not p[ten]:
            p[ten] = i

        if p[0]: # found solution
            break
    else: # no break
        assert 0, "solution not found for i in [1, %d]" % n

    # collect digits
    digits = []
    i = count = 0
    while True:
        digits.append("0" * (count - p[i]))
        digits.append("1")
        count = p[i] - 1
        i = (i + n - pow(10, count, n)) % n
        if i == 0:
            break

    digits.append("0" * count)
    return "".join(digits)

def main():
    for num in range(2, 100):
        print("%d\tdivides\t%s" % (num, A004290(num)))

main()
