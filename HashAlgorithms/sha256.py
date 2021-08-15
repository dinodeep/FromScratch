'''
REFERENCES: https://github.com/karpathy/cryptos/blob/main/cryptos/sha256.py
'''


import math
from itertools import count, islice


def isprime(n: int) -> bool:
    return not any([n % i == 0 for i in range(2, n)])


def ugly_n_primes(n: int):
    primes = []
    for i in range(2, 10000):
        if isprime(i):
            primes.append(i)
        if len(primes) == n:
            return primes


def first_n_primes(n: int) -> list:
    return islice(filter(isprime, count(start=2)), n)


def frac_bin(f, n=32):
    f -= int(f)
    f *= 2**n
    f = int(f)
    return f


def genH():
    return [frac_bin(p ** (1/2.)) for p in first_n_primes(8)]


def genK():
    return [frac_bin(p ** (1/3.)) for p in first_n_primes(64)]


def pad(b: bytes) -> bytearray:

    # convert to bytearray
    b = bytearray(b)
    num_bits = len(b) * 8

    # append a single 1
    b.append(0b10000000)

    # pad with 0s until the data is a multiple of 512, less 64 bits
    while (len(b) * 8) % 512 != 448:
        b.append(0x00)

    # append 64 bits to the end where the 64 bits are a big-endian integer representing
    # the length of the original input in BINARY
    b.extend(num_bits.to_bytes(8, "big"))

    return b


def SHA256(data: bytes) -> bytes:

    b = pad(data)

    h0, h1, h2, h3, h4, h5, h6, h7 = genH()
    K = genK()

    # chunk loop (each chunk is 512 bits = 64 bytes)
    for i in range(0, len(b), 64):
        chunk = b[i:i+64].copy()

        # create window where each entry is 32 bits = 4 bytes
        empty = 0
        w = [chunk[j:j+4] for j in range(0, len(chunk), 4)]
        for i in range(48):
            w.append(bytearray(empty.to_bytes(4, "big")))


SHA256(bytes("hello world!", "ascii"))
