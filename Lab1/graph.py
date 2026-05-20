import csv
import matplotlib.pyplot as plt

ns = []
choice = []
bubble = []
shaker = []
std_sort = []

with open("timings.csv", "r") as f:
    reader = csv.DictReader(f)
    for row in reader:
        ns.append(int(row["n"]))
        choice.append(int(row["choice"]))
        bubble.append(int(row["bubble"]))
        shaker.append(int(row["shaker"]))
        std_sort.append(int(row["std"]))

plt.figure(figsize=(10, 6))
plt.plot(ns, choice,   marker="o", label="Selection sort")
plt.plot(ns, bubble,   marker="s", label="Bubble sort")
plt.plot(ns, shaker,   marker="^", label="Shaker sort")
plt.plot(ns, std_sort, marker="d", label="std::sort")

plt.xlabel("Размер массива, элементов")
plt.ylabel("Время сортировки, мкс")
plt.title("Сравнение сортировок")
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig("plot.png", dpi=120)
plt.show()