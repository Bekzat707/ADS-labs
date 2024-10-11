import heapq

def last_stone_weight(stones):
    # Convert all stone weights to negative (to simulate max-heap)
    stones = [-stone for stone in stones]
    heapq.heapify(stones)  # Create a min-heap
    
    # Continue until there's at most one stone left
    while len(stones) > 1:
        # Pop the two heaviest stones (largest negative values)
        first = -heapq.heappop(stones)  # Get the largest
        second = -heapq.heappop(stones)  # Get the second largest
        
        # If they are not equal, push the remaining weight back into the heap
        if first != second:
            heapq.heappush(stones, -(first - second))
    
    # If there is a stone left, return its weight, otherwise return 0
    return -stones[0] if stones else 0

# Input handling
n = int(input())  # Number of stones
stones = list(map(int, input().split()))  # Weights of the stones

# Calculate and output the result
print(last_stone_weight(stones))