class Solution:
    def reverseBits(self, n: int) -> int:
        reversed_bits = 0
        bit_length = 32
        for i in range(bit_length):
            reversed_bits = (reversed_bits << 1) | (n & 1)
            n >>= 1
        return reversed_bits