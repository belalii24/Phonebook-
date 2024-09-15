#include <stdio.h>
#include <string.h>

#define MAX 100 // Maksimum kayýt sayýsý
#define NAME_LEN 50 // Ýsim uzunluðu

// Kayýt yapýsýný tanýmlýyoruz
struct Contact {
    char name[NAME_LEN];
    char phone[15];
};

// Kayýtlarýn tutulacaðý dizi
struct Contact phonebook[MAX];
int contactCount = 0; // Rehberdeki kayýt sayýsý

// Kayýt ekleme fonksiyonu
void addContact() {
    if (contactCount >= MAX) {
        printf("Rehber dolu! Yeni kayýt eklenemiyor.\n");
        return;
    }
    printf("Ýsim: ");
    scanf(" %[^\n]", phonebook[contactCount].name);
    printf("Telefon numarasý: ");
    scanf(" %s", phonebook[contactCount].phone);
    contactCount++;
    printf("Kayýt baþarýyla eklendi!\n");
}

// Kayýtlarý listeleme fonksiyonu
void listContacts() {
    if (contactCount == 0) {
        printf("Rehberde kayýt bulunmuyor.\n");
        return;
    }
    printf("Telefon Rehberi:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

// Ýsim ile kayýt arama fonksiyonu
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
    printf("Kayýt bulunamadý.\n");
}

// Kayýt silme fonksiyonu
void deleteContact() {
    char deleteName[NAME_LEN];
    printf("Silinecek isim: ");
    scanf(" %[^\n]", deleteName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            // Kayýtý silmek için son kaydý bu pozisyona taþýyoruz
            phonebook[i] = phonebook[contactCount - 1];
            contactCount--;
            printf("Kayýt baþarýyla silindi.\n");
            return;
        }
    }
    printf("Kayýt bulunamadý.\n");
}

// Kayýt güncelleme fonksiyonu
void updateContact() {
    char updateName[NAME_LEN];
    printf("Güncellenecek isim: ");
    scanf(" %[^\n]", updateName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, updateName) == 0) {
            printf("Yeni isim: ");
            scanf(" %[^\n]", phonebook[i].name);
            printf("Yeni telefon numarasý: ");
            scanf(" %s", phonebook[i].phone);
            printf("Kayýt baþarýyla güncellendi.\n");
            return;
        }
    }
    printf("Kayýt bulunamadý.\n");
}

// Ana menü
int main() {
    int choice;

    while (1) {
        printf("\nTelefon Rehberi Uygulamasý\n");
        printf("1. Kayýt Ekle\n");
        printf("2. Kayýt Listele\n");
        printf("3. Kayýt Ara\n");
        printf("4. Kayýt Sil\n");
        printf("5. Kayýt Güncelle\n");
        printf("6. Çýkýþ\n");
        printf("Seçiminiz: ");
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
                printf("Programdan çýkýlýyor...\n");
                return 0;
            default:
                printf("Geçersiz seçim. Tekrar deneyin.\n");
        }
    }

    return 0;
}
