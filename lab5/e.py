import heapq

def kth_sum(commands, k):
    min_heap = []  # Куча для хранения k наибольших значений
    total_sum = 0  # Переменная для хранения суммы элементов кучи

    for command in commands:
        if command[0] == "insert":
            x = command[1]
            if len(min_heap) < k:
                heapq.heappush(min_heap, x)
                total_sum += x
            elif x > min_heap[0]:
                total_sum += x - heapq.heappop(min_heap)
                heapq.heappush(min_heap, x)
        elif command[0] == "print":
            print(total_sum)

# Ввод данных
n, k = map(int, input().split())
commands = []

for _ in range(n):
    line = input().split()
    if line[0] == "insert":
        commands.append(("insert", int(line[1])))
    else:
        commands.append(("print",))

# Запуск решения
kth_sum(commands, k)
