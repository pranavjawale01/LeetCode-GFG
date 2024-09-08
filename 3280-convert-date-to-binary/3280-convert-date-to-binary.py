class Solution:
    def convertDateToBinary(self, date: str) -> str:
        def int_to_binary(n: int) -> str:
            return bin(n)[2:]

        year_str = date[:4]
        month_str = date[5:7]
        day_str = date[8:10]

        year_int = int(year_str)
        month_int = int(month_str)
        day_int = int(day_str)

        year_binary = int_to_binary(year_int)
        month_binary = int_to_binary(month_int)
        day_binary = int_to_binary(day_int)

        return f"{year_binary}-{month_binary}-{day_binary}"