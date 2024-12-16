from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 2

        for n in nums[2:]:
            if n != nums[k - 2]:
                nums[k] = n
                k += 1

        return k
