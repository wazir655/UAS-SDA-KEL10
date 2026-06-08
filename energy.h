#ifndef ENERGY_H
#define ENERGY_H

#define MAX_NAME 50

typedef struct
{
    char name[MAX_NAME];

    int power;          // Daya perangkat (Watt)
    int hoursPerDay;    // Jam pemakaian per hari
    int priority;       // Prioritas penggunaan

    float dailyKwh;     // Konsumsi listrik per hari
    float monthlyCost;  // Estimasi biaya per bulan

} Device;

#endif
