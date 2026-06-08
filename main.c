#include <stdio.h>
#include "energy.h"
#include "datamanager.h"
#include "analisis.h"
#include "optimasi.h"

int main()
{
    int pilihan;

    do
    {
        printf("\n====================================\n");
        printf(" SISTEM AUDIT ENERGI RUMAH TANGGA\n");
        printf("====================================\n");

        printf("1. Jalankan Analisis\n");
        printf("2. Keluar\n");
        printf("Pilih menu : ");
        scanf("%d", &pilihan);

        if(pilihan == 1)
        {
            Node* head = NULL;
            BSTNode* root = NULL;
            Queue q;

            initQueue(&q);

            int n;

            printf("\nJumlah perangkat: ");
            scanf("%d",&n);

            for(int i=0;i<n;i++)
            {
                Device d;

                printf("\nPerangkat %d\n", i+1);

                printf("Nama perangkat : ");
                scanf("%s", d.name);

                printf("Daya (Watt) : ");
                scanf("%d", &d.power);

                printf("Jam Pemakaian per Hari : ");
                scanf("%d", &d.hoursPerDay);

                printf("Prioritas (1-10) : ");
                scanf("%d", &d.priority);

                d.dailyKwh = 0;
                d.monthlyCost = 0;

                insertDevice(&head, d);
            }

            printf("\n====================================\n");
            printf("DATA PERANGKAT\n");
            printf("====================================\n");

            displayLinkedList(head);

            int size = countDevices(head);

            Device arr[size];

            linkedListToArray(head, arr);

            mergeSort(arr, 0, size - 1);

            printf("\n====================================\n");
            printf("HASIL SORT BERDASARKAN PRIORITAS\n");
            printf("====================================\n");

            for(int i=0;i<size;i++)
            {
                printf("%s | %d Watt | %d Jam/Hari | Priority %d\n",
                       arr[i].name,
                       arr[i].power,
                       arr[i].hoursPerDay,
                       arr[i].priority);
            }

            for(int i=0;i<size;i++)
            {
                root = insertBST(root, arr[i]);
                enqueue(&q, arr[i]);
            }

            int maxPower;

            printf("\nMasukkan batas daya rumah (Watt): ");
            scanf("%d", &maxPower);

            optimizeEnergy(arr, size, maxPower);

            processQueue(&q);

            printf("\n====================================\n");
            printf("DAFTAR PERANGKAT BERDASARKAN DAYA\n");
            printf("====================================\n");

            inorder(root);

            int searchPower;

            printf("\nCari perangkat berdasarkan daya: ");
            scanf("%d", &searchPower);

            BSTNode* found =
            searchBST(root, searchPower);

            if(found)
            {
                printf("\n=== DATA DITEMUKAN ===\n");
                printf("Nama      : %s\n",
                       found->data.name);
                printf("Daya      : %d Watt\n",
                       found->data.power);
                printf("Jam/Hari  : %d\n",
                       found->data.hoursPerDay);
                printf("Prioritas : %d\n",
                       found->data.priority);
            }
            else
            {
                printf("\nPerangkat tidak ditemukan.\n");
            }
        }
        else if(pilihan == 2)
        {
            printf("\nProgram selesai.\n");
        }
        else
        {
            printf("\nPilihan tidak valid.\n");
        }

    }
    while(pilihan != 2);

    return 0;
}
