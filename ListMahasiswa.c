#include "listMahasiswa.h"

// Cek apakah list kosong
boolean isEmpty(address p) {
    return (p == NULL);
}

// Membuat node baru
void createNode(address *p) {
    *p = (address) malloc(sizeof(ElmtList));
    if (*p == NULL) {
        printf("Alokasi gagal!\n");
        exit(1);
    }
}

// Mengisi node yang telah dialokasi dengan data mahasiswa
void isiNode(Mahasiswa m, address *p) {
    if (!isEmpty(*p)) {
        (*p)->data = m;
        (*p)->next = NULL;
    }
}

// Insert node ke list secara sorted (ascending berdasarkan nama)
void insertSorted(address *head, Mahasiswa m) {
    address baru, prev, curr;
    createNode(&baru);
    isiNode(m, &baru);
    // Jika list kosong atau nama baru lebih kecil dari head
    if (isEmpty(*head) || strcmp(m.nama, (*head)->data.nama) < 0) {
        baru->next = *head;
        *head = baru;
    } else {
        prev = *head;
        curr = (*head)->next;
        while (curr != NULL && strcmp(m.nama, curr->data.nama) >= 0) {
            prev = curr;
            curr = curr->next;
        }
        baru->next = curr;
        prev->next = baru;
    }
}

// Tampilkan list (nama dan nilai)
void tampilList(address head) {
    if (isEmpty(head)) {
        printf("List kosong.\n");
        return;
    }
    address p = head;
    while (p != NULL) {
        printf("Nama: %-20s Nilai: %d\n", p->data.nama, p->data.nilai);
        p = p->next;
    }
}

// Hitung jumlah elemen dalam list
int countElements(address head) {
    int count = 0;
    address p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

// Fungsi pembanding untuk qsort (descending berdasarkan nilai)
int compareDesc(const void *a, const void *b) {
    Mahasiswa *m1 = (Mahasiswa *) a;
    Mahasiswa *m2 = (Mahasiswa *) b;
    return (m2->nilai - m1->nilai);
}

// Tampilkan list descending berdasarkan nilai
// Metode: copy data ke array, sort dengan qsort, lalu tampilkan
void tampilListDescendingByNilai(address head) {
    int n = countElements(head);
    if (n == 0) {
        printf("List kosong.\n");
        return;
    }
    Mahasiswa *arr = (Mahasiswa *) malloc(n * sizeof(Mahasiswa));
    address p = head;
    int i = 0;
    while (p != NULL && i < n) {
        arr[i++] = p->data;
        p = p->next;
    }
    qsort(arr, n, sizeof(Mahasiswa), compareDesc);
    printf("Tampilan list (descending berdasarkan nilai):\n");
    for (i = 0; i < n; i++) {
        printf("Nama: %-20s Nilai: %d\n", arr[i].nama, arr[i].nilai);
    }
    free(arr);
}

// Copy elemen dengan nilai > 70 ke list baru (L2)
address copyElementsGreaterThan70(address head) {
    address L2 = NULL;
    address p = head;
    while (p != NULL) {
        if (p->data.nilai > 70) {
            address baru;
            createNode(&baru);
            isiNode(p->data, &baru);
            baru->next = NULL;
            if (L2 == NULL) {
                L2 = baru;
            } else {
                address temp = L2;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = baru;
            }
        }
        p = p->next;
    }
    return L2;
}

// Hapus data duplikat pada list berdasarkan nama (menyimpan kemunculan pertama)
address removeDuplicates(address head) {
    if (isEmpty(head))
        return head;
    address p = head;
    while (p != NULL) {
        address prev = p;
        address q = p->next;
        while (q != NULL) {
            if (strcmp(p->data.nama, q->data.nama) == 0) {
                // Hapus node q
                prev->next = q->next;
                free(q);
                q = prev->next;
            } else {
                prev = q;
                q = q->next;
            }
        }
        p = p->next;
    }
    return head;
}

// Dealokasi seluruh list
void freeList(address *head) {
    address temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
