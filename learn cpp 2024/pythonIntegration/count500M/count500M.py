import time

start_time = time.time()

total = 0
for i in range(1, 500000001):
    total += 1
end_time = time.time()
duration = end_time - start_time

print(f"Counting to 500 million and incrementing a variable took {duration:.6f} seconds. Final value: {total}")
