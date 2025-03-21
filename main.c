#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listMahasiswa.h"

// Fungsi untuk menampilkan menu
void menu() {
    printf("\n===== MENU UTAMA =====\n");
    printf("1. Insert data mahasiswa ke List L1 (sorted ascending berdasarkan nama)\n");
    printf("2. Tampilkan List L1 (ascending berdasarkan nama)\n");
    printf("3. Tampilkan List L1 (descending berdasarkan nilai)\n");
    printf("4. Tampilkan jumlah elemen di List L1\n");
    printf("5. Copy elemen dengan nilai > 70 ke List L2\n");
    printf("6. Tampilkan List L2\n");
    printf("7. Hapus duplikat nama di List L2\n");
    printf("8. Tampilkan List L2 (setelah duplikat dihapus)\n");
    printf("9. Hapus seluruh List L1 dan L2\n");
    printf("0. Keluar\n");
    printf("Pilihan anda: ");
}

int main() {
    address L1 = NULL, L2 = NULL;
    int pilihan;
    Mahasiswa m;
    
    do {
        menu();
        scanf("%d", &pilihan);
        getchar(); // menangkap newline
        
        switch(pilihan) {
            case 1:
                printf("Masukkan Nama Mahasiswa: ");
                fgets(m.nama, MAX_NAMA, stdin);
                m.nama[strcspn(m.nama, "\n")] = '\0'; // Hilangkan newline
                printf("Masukkan Nilai UTS SDA: ");
                scanf("%d", &m.nilai);
                getchar();
                insertSorted(&L1, m);
                printf("Data berhasil ditambahkan ke L1.\n");
                break;
            case 2:
                printf("Isi List L1 (ascending berdasarkan nama):\n");
                tampilList(L1);
                break;
            case 3:
                tampilListDescendingByNilai(L1);
                break;
            case 4:
                printf("Jumlah elemen di L1: %d\n", countElements(L1));
                break;
            case 5:
                // Jika L2 sudah ada, bersihkan terlebih dahulu agar tidak menumpuk
                if(L2 != NULL) {
                    freeList(&L2);
                    L2 = NULL;
                }
                L2 = copyElementsGreaterThan70(L1);
                printf("Elemen dengan nilai > 70 telah dicopy ke L2.\n");
                break;
            case 6:
                printf("Isi List L2:\n");
                tampilList(L2);
                break;
            case 7:
                L2 = removeDuplicates(L2);
                printf("Duplikat nama di L2 telah dihapus.\n");
                break;
            case 8:
                printf("Isi List L2 (setelah duplikat dihapus):\n");
                tampilList(L2);
                break;
            case 9:
                freeList(&L1);
                freeList(&L2);
                printf("Seluruh L1 dan L2 telah dihapus.\n");
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while(pilihan != 0);
    
    return 0;
}
