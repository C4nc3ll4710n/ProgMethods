import csv
import random

FIRST = ["Ivan", "Petr", "Sergey", "Nikita", "Oleg", "Anatoly"]
LAST  = ["Ivanov", "Petrov", "Sidorov", "Smirnov", "Kuznetsov", "Popov", "Fedorov", "Mazievich"]
FAC   = ["Cybersec", "Math", "Physics", "Economics", "Biology", "Law"]

def random_name():
    return f"{random.choice(FIRST)} {random.choice(LAST)}"

def random_faculty():
    return random.choice(FAC)

def main():
    n = 1000 
    with open("students.csv", "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["name", "faculty", "group", "gpa"])

        for _ in range(n):
            name = random_name()
            faculty = random_faculty()
            group = random.randint(200, 260)
            gpa = round(random.uniform(4.0, 10.0), 2)
            writer.writerow([name, faculty, group, gpa])

if __name__ == "__main__":
    main()