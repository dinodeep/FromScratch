

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
    print(len(b) * 8)


SHA256(bytes("hello world!", "ascii"))
