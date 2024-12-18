class Solution:
    def maxArea(self, height: list[int]) -> int:
        l, r = 0, len(height) - 1
        max_water = 0

        while l < r:
            curr = min(height[l], height[r]) * (r - l)
            max_water = max(max_water, curr)

            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return max_water
