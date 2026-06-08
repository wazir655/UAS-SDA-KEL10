# UAS-SDA-KEL10
# Data Analysis & Optimization System (DAOS)

## Optimasi Distribusi Energi Listrik untuk Efisiensi Konsumsi Rumah Tangga

### Praktikum Struktur Data dan Algoritma B

### UAS Semester Genap 2025/2026

---

## Anggota Kelompok 10

| Nama                 | NPM             |
| -------------------- | --------------- |
| Abdan Syakura        | 250810701100017 |
| Asy Syifa Zahra      | 150810701100027 |
| Ahmad Wazir Sahfikri | 250810701100050 |
| Zaw Thein Htet       | 250810701100118 |

---

## SDGs yang Dipilih

### SDG 7 – Affordable and Clean Energy

Proyek ini dibuat untuk membantu pengguna mengelola penggunaan energi listrik secara lebih efisien. Sistem menganalisis perangkat listrik berdasarkan daya dan prioritas penggunaan, kemudian memberikan rekomendasi perangkat yang dapat digunakan tanpa melebihi batas daya yang tersedia.

---

## Deskripsi Proyek

Data Analysis & Optimization System (DAOS) adalah aplikasi berbasis Command Line Interface (CLI) yang menerapkan konsep Struktur Data dan Algoritma untuk mengelola data perangkat listrik dan melakukan optimasi penggunaan energi.

### Fitur Utama

* Menyimpan data perangkat listrik secara dinamis
* Menampilkan data perangkat
* Mengurutkan perangkat berdasarkan prioritas penggunaan
* Mencari perangkat berdasarkan daya listrik
* Menampilkan perangkat secara terurut berdasarkan daya
* Mensimulasikan penggunaan perangkat menggunakan Queue
* Memberikan rekomendasi penggunaan perangkat sesuai batas daya rumah

---

## Struktur Data yang Digunakan

### 1. Linked List

Digunakan untuk menyimpan data perangkat listrik secara dinamis.

Data yang disimpan:

* Nama perangkat
* Daya listrik (Watt)
* Prioritas penggunaan

Kompleksitas:

* Insert : O(n)

### 2. Queue

Digunakan untuk mensimulasikan antrean penggunaan perangkat listrik menggunakan konsep FIFO (First In First Out).

Kompleksitas:

* Enqueue : O(1)
* Dequeue : O(1)

### 3. Binary Search Tree (BST)

Digunakan untuk:

* Menyimpan data berdasarkan daya listrik
* Mempermudah pencarian perangkat
* Menampilkan data secara terurut berdasarkan daya

Kompleksitas rata-rata:

* Insert : O(log n)
* Search : O(log n)

---

## Algoritma yang Digunakan

### 1. Merge Sort

Digunakan untuk mengurutkan perangkat berdasarkan prioritas penggunaan dari yang tertinggi ke terendah.

Kompleksitas:

O(n log n)

### 2. BST Search

Digunakan untuk mencari perangkat berdasarkan daya listrik.

Kompleksitas rata-rata:

O(log n)

### 3. Greedy Algorithm

Digunakan untuk menentukan perangkat yang direkomendasikan agar total daya tidak melebihi batas daya rumah.

Kompleksitas:

O(n)

---

## Alur Sistem

1. User memasukkan data perangkat listrik.
2. Data disimpan ke Linked List.
3. Data ditampilkan sebagai data awal.
4. Data dikonversi ke Array.
5. Merge Sort mengurutkan data berdasarkan prioritas.
6. Data dimasukkan ke Queue.
7. Data dimasukkan ke BST.
8. User memasukkan batas daya rumah.
9. Sistem melakukan optimasi menggunakan Greedy Algorithm.
10. Sistem menampilkan rekomendasi perangkat yang dapat digunakan.
11. Sistem mensimulasikan penggunaan perangkat menggunakan Queue.
12. Sistem menampilkan data BST menggunakan inorder traversal.
13. User dapat mencari perangkat berdasarkan daya listrik.

---

## Struktur File

```text
DAOS/
│
├── main.c
├── energy.h
├── datamanager.h
├── datamanager.c
├── analisis.h
├── analisis.c
├── optimasi.h
└── optimasi.c
```

---

## Cara Compile

### Linux / macOS

```bash
gcc main.c datamanager.c analisis.c optimasi.c -o daos
```

Jalankan program:

```bash
./daos
```

### Windows (MinGW)

```bash
gcc main.c datamanager.c analisis.c optimasi.c -o daos.exe
```

Jalankan program:

```bash
daos.exe
```

---

## Contoh Input

```text
Jumlah perangkat: 3

Perangkat 1
Nama perangkat : Lampu
Daya (Watt) : 10
Prioritas : 3

Perangkat 2
Nama perangkat : TV
Daya (Watt) : 80
Prioritas : 2

Perangkat 3
Nama perangkat : Kulkas
Daya (Watt) : 150
Prioritas : 5

Masukkan batas daya rumah : 200
```

---

## Contoh Output

```text
=== HASIL MERGE SORT ===

Kulkas | 150 Watt | Priority 5
Lampu  | 10 Watt  | Priority 3
TV     | 80 Watt  | Priority 2

=== REKOMENDASI PERANGKAT ===

Kulkas (150 Watt)
Lampu (10 Watt)

Total Daya Digunakan : 160 Watt
Batas Daya Rumah     : 200 Watt
```

---

## Analisis Kompleksitas

| Operasi               | Kompleksitas |
| --------------------- | ------------ |
| Insert Linked List    | O(n)         |
| Linked List Traversal | O(n)         |
| Queue Enqueue         | O(1)         |
| Queue Dequeue         | O(1)         |
| Merge Sort            | O(n log n)   |
| BST Insert            | O(log n)     |
| BST Search            | O(log n)     |
| Inorder Traversal     | O(n)         |
| Greedy Optimization   | O(n)         |

---

## Pembagian Tugas Anggota

### Anggota 1 – Data Management (Asy Syifa Zahra)

File:

* datamanager.h
* datamanager.c

Tugas:

* Implementasi Linked List
* Penyimpanan data perangkat
* Konversi Linked List ke Array

### Anggota 2 – Analysis Module (Zaw Thein Htet)

File:

* analisis.h
* analisis.c

Tugas:

* Merge Sort
* Binary Search Tree (BST)
* Searching
* Traversal

### Anggota 3 – Optimization Module (Abdan Syakura)

File:

* optimasi.h
* optimasi.c

Tugas:

* Queue
* Greedy Algorithm
* Simulasi penggunaan perangkat

### Anggota 4 – Integration & Documentation (Ahmad Wazir Sahfikri)

File:

* main.c
* energy.h

Tugas:

* Integrasi seluruh modul
* CLI Program
* Pengujian program
* Dokumentasi proyek

---

## Kesimpulan

Program DAOS berhasil mengimplementasikan tiga struktur data utama yaitu Linked List, Queue, dan Binary Search Tree (BST), serta tiga algoritma yaitu Merge Sort, BST Search, dan Greedy Algorithm.

Sistem mampu melakukan penyimpanan data perangkat listrik, pengurutan berdasarkan prioritas, pencarian berdasarkan daya, simulasi penggunaan perangkat, dan rekomendasi penggunaan energi sesuai batas daya yang tersedia. Implementasi ini mendukung tujuan SDG 7 yaitu Affordable and Clean Energy melalui pemanfaatan algoritma dan struktur data untuk pengelolaan energi yang lebih efisien.
