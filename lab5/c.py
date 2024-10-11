import heapq

def max_revenue(n, m, seats):
    # Преобразуем массив мест в отрицательные значения для использования min-heap как max-heap
    seats = [-seat for seat in seats]
    heapq.heapify(seats)  # Преобразуем в кучу (min-heap)
    
    total_revenue = 0
    
    # Продаем m билетов
    for _ in range(m):
        # Извлекаем ряд с наибольшим количеством свободных мест (из-за отрицательных значений это минимальный элемент)
        largest_seat = -heapq.heappop(seats)
        
        # Добавляем стоимость билета
        total_revenue += largest_seat
        
        # Уменьшаем количество мест в этом ряду и возвращаем его обратно в кучу
        heapq.heappush(seats, -(largest_seat - 1))
    
    return total_revenue

# Ввод
n, m = map(int, input().split())  # количество рядов и количество болельщиков
seats = list(map(int, input().split()))  # количество мест в каждом ряду

# Вывод результата
print(max_revenue(n, m, seats))