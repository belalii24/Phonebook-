#include <stdio.h>
#include <string.h>

#define MAX 100 // Maksimum kay�t say�s�
#define NAME_LEN 50 // �sim uzunlu�u

// Kay�t yap�s�n� tan�ml�yoruz
struct Contact {
    char name[NAME_LEN];
    char phone[15];
};

// Kay�tlar�n tutulaca�� dizi
struct Contact phonebook[MAX];
int contactCount = 0; // Rehberdeki kay�t say�s�

// Kay�t ekleme fonksiyonu
void addContact() {
    if (contactCount >= MAX) {
        printf("Rehber dolu! Yeni kay�t eklenemiyor.\n");
        return;
    }
    printf("�sim: ");
    scanf(" %[^\n]", phonebook[contactCount].name);
    printf("Telefon numaras�: ");
    scanf(" %s", phonebook[contactCount].phone);
    contactCount++;
    printf("Kay�t ba�ar�yla eklendi!\n");
}

// Kay�tlar� listeleme fonksiyonu
void listContacts() {
    if (contactCount == 0) {
        printf("Rehberde kay�t bulunmuyor.\n");
        return;
    }
    printf("Telefon Rehberi:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

// �sim ile kay�t arama fonksiyonu
void searchContact() {
    char searchName[NAME_LEN];
    printf("Aranacak isim: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Bulundu: %s - %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }
    printf("Kay�t bulunamad�.\n");
}

// Kay�t silme fonksiyonu
void deleteContact() {
    char deleteName[NAME_LEN];
    printf("Silinecek isim: ");
    scanf(" %[^\n]", deleteName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            // Kay�t� silmek i�in son kayd� bu pozisyona ta��yoruz
            phonebook[i] = phonebook[contactCount - 1];
            contactCount--;
            printf("Kay�t ba�ar�yla silindi.\n");
            return;
        }
    }
    printf("Kay�t bulunamad�.\n");
}

// Kay�t g�ncelleme fonksiyonu
void updateContact() {
    char updateName[NAME_LEN];
    printf("G�ncellenecek isim: ");
    scanf(" %[^\n]", updateName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, updateName) == 0) {
            printf("Yeni isim: ");
            scanf(" %[^\n]", phonebook[i].name);
            printf("Yeni telefon numaras�: ");
            scanf(" %s", phonebook[i].phone);
            printf("Kay�t ba�ar�yla g�ncellendi.\n");
            return;
        }
    }
    printf("Kay�t bulunamad�.\n");
}

// Ana men�
int main() {
    int choice;

    while (1) {
        printf("\nTelefon Rehberi Uygulamas�\n");
        printf("1. Kay�t Ekle\n");
        printf("2. Kay�t Listele\n");
        printf("3. Kay�t Ara\n");
        printf("4. Kay�t Sil\n");
        printf("5. Kay�t G�ncelle\n");
        printf("6. ��k��\n");
        printf("Se�iminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                updateContact();
                break;
            case 6:
                printf("Programdan ��k�l�yor...\n");
                return 0;
            default:
                printf("Ge�ersiz se�im. Tekrar deneyin.\n");
        }
    }

    return 0;
}
