import sys
import numpy as np


def triangle(n, m):
    t = np.full((n+1, n+1), 0, dtype=np.uint64)
    t[0][0] = 1
    for i in range(1, n+1):
        t[i][0] = 1
        for j in range(1, i+1):
            t[i][j] = t[i-1][j] + t[i-1][j-1]
            if i == n-1 and j == m:
                return t[i][j] + t[i][j-1]


def main():
    for line in sys.stdin:
        line = line.split(" ")
        n = int(line[0])
        m = int(line[1])
        if n:
            result = triangle(n, m)
            print("%d things taken %d at a time is %d exaclty." % (n, m, result))


if __name__ == "__main__":
    main()
