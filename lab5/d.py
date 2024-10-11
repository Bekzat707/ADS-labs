import heapq

def min_operations_to_reach_density(n, k, densities):
    # Создаем минимальную кучу из плотностей
    heapq.heapify(densities)
    
    operations = 0
    
    # Пока минимальная плотность меньше требуемой
    while len(densities) > 1 and densities[0] < k:
        # Извлекаем две смеси с наименьшей плотностью
        first = heapq.heappop(densities)
        second = heapq.heappop(densities)
        
        # Создаем новую смесь по формуле
        new_mixture = first + 2 * second
        
        # Возвращаем новую смесь в кучу
        heapq.heappush(densities, new_mixture)
        
        # Увеличиваем количество операций
        operations += 1
    
    # Проверяем минимальную плотность после всех операций
    if densities[0] >= k:
        return operations
    else:
        return -1

# Ввод данных
n, k = map(int, input().split())
densities = list(map(int, input().split()))

# Вывод результата
print(min_operations_to_reach_density(n, k, densities))