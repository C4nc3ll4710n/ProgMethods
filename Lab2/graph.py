import csv
import matplotlib.pyplot as plt
 
n, lin, hsh, rb, bn, mm = [], [], [], [], [], []
with open('times.csv') as f:
    r = csv.DictReader(f)
    for row in r:
        n.append(int(row['n']))
        lin.append(int(row['lin']))
        hsh.append(int(row['hsh']))
        rb.append(int(row['rb']))
        bn.append(int(row['bn']))
        mm.append(int(row['mm']))
 
plt.figure(figsize=(9, 6))
plt.plot(n, lin, 'o-', label='Лин поиск')
plt.plot(n, bn,  's-', label='Бин Дерево')
plt.plot(n, rb,  '^-', label='КЧ Дерево')
plt.plot(n, hsh, 'd-', label='Хэш-таблица')
plt.plot(n, mm,  'v-', label='Мультимап')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('Размер выборки')
plt.ylabel('Время')
plt.legend()
plt.grid(True, which='both', alpha=0.4)
plt.tight_layout()
plt.savefig('times.png', dpi=130)
plt.close()
 
cn, colls = [], []
with open('colls.csv') as f:
    r = csv.DictReader(f)
    for row in r:
        cn.append(int(row['n']))
        colls.append(int(row['colls']))
 
plt.figure(figsize=(9, 6))
plt.plot(cn, colls, 'o-', label='Коллизий')
plt.xlabel('Размер массива')
plt.ylabel('Число коллизий')
plt.legend()
plt.grid(True, alpha=0.4)
plt.tight_layout()
plt.savefig('colls.png', dpi=130)
plt.close()
