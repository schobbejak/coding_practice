class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        max_pop = 0

        # Find max and min of birth year O(n)
        max_death = 0
        min_birth = 0
        for log in logs:
            max_death = max(max_death, log[1])
            min_birth = min(min_birth, log[0])

        # Create list in range max_birth - min_birth to count people alive
        pop_count = [0 for x in range(max_death-min_birth + 1)]

        # Loop through logs and add count
        for log in logs:
            birth_year = log[0] - min_birth
            death_year = log[1] - min_birth

            for i in range(birth_year, death_year):
                pop_count[i] = pop_count[i] + 1

        # Return max of list
        year = 0
        for i, count in enumerate(pop_count):
            if count > max_pop:
                max_pop = count
                year = i
        year = year + min_birth
        return year
