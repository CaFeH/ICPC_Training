import sys
from itertools import permutations


def main():
    i = 0
    sys.stdin.readline()
    for line in sys.stdin:
        i += 1
        banner = line[:-1]
        perm = permutations(banner, len(banner))
        print("Data set %d: %d" % (i, len(set(perm))))


if __name__ == "__main__":
    main()
