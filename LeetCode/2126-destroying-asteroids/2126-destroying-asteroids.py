class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        ans = mass
        for x in asteroids:
            if ans >= x:
                ans += x
            else:
                return False
        return True