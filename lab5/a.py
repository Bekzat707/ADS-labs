import heapq

def minimum_cost_to_merge(n, array_sizes):
    # Create a min-heap from the array sizes
    heapq.heapify(array_sizes)
    
    total_cost = 0
    
    # Continue merging until only one array remains
    while len(array_sizes) > 1:
        # Extract the two smallest arrays
        first = heapq.heappop(array_sizes)
        second = heapq.heappop(array_sizes)
        
        # Merge them and calculate the cost
        merge_cost = first + second
        total_cost += merge_cost
        
        # Insert the merged array back into the heap
        heapq.heappush(array_sizes, merge_cost)
    
    return total_cost

# Input handling
n = int(input())  # number of arrays
array_sizes = list(map(int, input().split()))  # array sizes

# Calculate and output the minimum cost
print(minimum_cost_to_merge(n, array_sizes))