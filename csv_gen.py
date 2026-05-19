import csv
import random

import csv
import random

gl = "aeiouy"
sogl = "bcdfghjklmnpqrstvwxz"
fac = ["Cybersec", "Reverse", "Forensics", "Pentest", "Pwn", "Teapotting"]

def random_word():
    length = random.randint(3, 10)
    letters = []
    for i in range(length):
        if i % 2 == 0:
            letters.append(random.choice(gl))
        else:
            letters.append(random.choice(sogl))
    return "".join(letters).capitalize()

def write_csv(n, path):
    with open(path, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["name", "faculty", "group", "gpa"])
        for _ in range(n):
            name = f"{random_word()} {random_word()}"
            faculty = random.choice(fac)
            group = random.randint(200, 260)
            gpa = round(random.uniform(4.0, 10.0), 2)
            writer.writerow([name, faculty, group, gpa])

def main():
    sizes = [100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 75000, 100000]
    for n in sizes:
        path = f"students_{n}.csv"
        write_csv(n, path)
        print(f"  written {path}: {n} rows")

if __name__ == "__main__":
    main()