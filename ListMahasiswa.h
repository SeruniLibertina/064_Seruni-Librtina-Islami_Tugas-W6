#ifndef LISTMAHASISWA_H
#define LISTMAHASISWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMA 50

// Definisi tipe boolean
typedef enum { false, true } boolean;

// Struktur data Mahasiswa
typedef struct {
    char nama[MAX_NAMA];
    int nilai;
} Mahasiswa;

// Struktur node untuk Single Linked List
typedef struct tElmtList *address;
typedef struct tElmtList {
    Mahasiswa data;
    address next;
} ElmtList;

// Prototipe fungsi ADT
boolean isEmpty(address p);
void createNode(address *p);
void isiNode(Mahasiswa m, address *p);
void insertSorted(address *head, Mahasiswa m); // Insert node secara ascending berdasarkan nama
void tampilList(address head);                 // Tampilkan list sesuai urutan linked list
void tampilListDescendingByNilai(address head); // Tampilkan list descending berdasarkan nilai
int countElements(address head);               // Hitung jumlah elemen dalam list
address copyElementsGreaterThan70(address head); // Copy elemen dengan nilai > 70 ke list baru
address removeDuplicates(address head);        // Hapus duplikat berdasarkan nama (simpan kemunculan pertama)
void freeList(address *head);                  // Dealokasi seluruh list

#endif
