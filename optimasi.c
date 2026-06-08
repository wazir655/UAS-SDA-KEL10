#include <stdio.h>
#include <stdlib.h>
#include "optimasi.h"

void initQueue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, Device d)
{
    QueueNode* temp =
    (QueueNode*)malloc(sizeof(QueueNode));

    temp->data = d;
    temp->next = NULL;

    if(q->rear == NULL)
    {
        q->front = temp;
        q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void processQueue(Queue* q)
{
    printf("\n=== SIMULASI PENGGUNAAN PERANGKAT ===\n");

    while(q->front)
    {
        QueueNode* temp = q->front;

        printf("%s digunakan\n",
               temp->data.name);

        q->front = q->front->next;

        free(temp);
    }

    q->rear = NULL;
}

void optimizeEnergy(Device arr[],
                    int n,
                    int maxPower)
{
    int totalPower = 0;
    float totalCost = 0;

    const float TARIF = 1444.70;

    printf("\n====================================\n");
    printf("      LAPORAN AUDIT ENERGI\n");
    printf("====================================\n");

    for(int i = 0; i < n; i++)
    {
        arr[i].dailyKwh =
            (arr[i].power * arr[i].hoursPerDay) / 1000.0;

        arr[i].monthlyCost =
            arr[i].dailyKwh * 30 * TARIF;

        totalCost += arr[i].monthlyCost;

        printf("\nPerangkat : %s\n", arr[i].name);
        printf("Daya      : %d Watt\n",
               arr[i].power);
        printf("Pemakaian : %d Jam/Hari\n",
               arr[i].hoursPerDay);
        printf("Konsumsi  : %.2f kWh/Hari\n",
               arr[i].dailyKwh);
        printf("Biaya     : Rp %.0f/Bulan\n",
               arr[i].monthlyCost);
    }

    printf("\n====================================\n");
    printf("TOTAL ESTIMASI TAGIHAN : Rp %.0f\n",
           totalCost);

    printf("\n====================================\n");
    printf("REKOMENDASI PENGGUNAAN DAYA\n");
    printf("====================================\n");

    for(int i = 0; i < n; i++)
    {
        if(totalPower + arr[i].power <= maxPower)
        {
            printf("%s (%d Watt)\n",
                   arr[i].name,
                   arr[i].power);

            totalPower += arr[i].power;
        }
    }

    printf("\nTotal Daya Digunakan : %d Watt\n",
           totalPower);

    printf("Batas Daya Rumah     : %d Watt\n",
           maxPower);

    printf("\n====================================\n");
    printf("SARAN PENGHEMATAN\n");
    printf("====================================\n");

    for(int i = 0; i < n; i++)
    {
        if(arr[i].hoursPerDay > 4)
        {
            float hemat =
            ((arr[i].power * 2) / 1000.0)
            * 30 * TARIF;

            printf("- Kurangi penggunaan %s 2 jam/hari\n",
                   arr[i].name);

            printf("  Potensi hemat Rp %.0f/bulan\n",
                   hemat);
        }
    }
}


