#include <stdio.h>
#include <stdlib.h>

int binary_Arama(int bllk[], int sol, int sag, int favori_Eleman);

//qsort fonksiyonunu kullanmak icin cmpfunc fonksiyonu
int cmpfunc(const void *a, const void *b) {
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return (*ia - *ib);
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68}; //dizi
    printf("Soruda verilen dizi: 4, 8, 3, 84, 47, 76, 9, 24, 68");
    printf("\n \n");
    printf("Soruda bize Binary Search algoritmasi kullanarak sorunun cozulmesini istiyor");
	printf("\n \n"); 
	printf("Bu algoritmanin kullanilabilmesi icin dizi elemanlari sirali olmasi gerekiyor fakat bize verilen dizi sirali degil");
	printf("\n \n");
	printf("siralamak icin qsort algoritmasini kullanarak siraladim.");
	printf("\n \n");
	printf("Dizinin yeni hali: 3, 4, 8, 9, 24, 47, 68, 76, 84");
    printf("\n \n");
    int h = sizeof(dizi) / sizeof(dizi[0]); //dizinin eleman sayýsýný hesapla(sizeof(dizi): dizinin toplam boyutunu (bayt cinsinden) ; sizeof(dizi[0]) dizinin bir elemanýnýn boyutunu (bayt cinsinden) verir.)

   qsort(dizi, h, sizeof(int), cmpfunc); //qsort fonksiyonu ile verilen diziyi sýrala
   

    int favori_Eleman;
    printf("Verilen dizide aranacak elemani giriniz: ");
    scanf("%d", &favori_Eleman);          //kullanicidan aramak istedigi elemani al

    int index = binary_Arama(dizi, 0, h - 1, favori_Eleman);  //fonksiyonu çaðýrarak, dizide aranan elemanýn indeksini hesaplar ve index deðiþkenine atar.

    if (index != -1) {   //-1'e eþit olup olmadýðýný kontrol et.
        printf("Aranan eleman %d , aranan eleman dizinin %d. indexidir.", favori_Eleman, index); //dönen deðer -1 deðilse, bu demek oluyor ki aranan eleman dizide bulunmuþtur
    } else {
        printf("Aranan eleman %d, dizide bulunamadi.", favori_Eleman); // -1'e eþitse, aranan eleman dizide bulunamamýþtýr
    }

    return 0;
}

int binary_Arama(int bllk[], int sol, int sag, int favori_Eleman) { //fonksiyon olustur
    if (sol <= sag) {   // dizinin sýnýrý hala geçerli mi kontrol edilir
        int mid = (sol + sag) / 2; //dizinin ortasýndaki elemanýn indeksini bulur (mid)

        if (bllk[mid] == favori_Eleman) {  //bu eleman aranan elemanla eþleþirse
            return mid;    //bu elemanýn indeksini (mid) döndürür.
        } else if (bllk[mid] < favori_Eleman) {  //Eðer ortadaki eleman aranan elemandan küçükse
            return binary_Arama(bllk, mid + 1, sag, favori_Eleman); //fonksiyon sað yarýda (mid+1 ile sag arasýnda) tekrar çaðrýlýr
        } else {  //Eðer ortadaki eleman aranan elemandan büyükse
            return binary_Arama(bllk, sol, mid - 1, favori_Eleman);  //fonksiyon sol yarýda (sol ile mid-1 arasýnda) tekrar çaðrýlýr
        }
    }

    return -1;  //eger aranan eleman dizide bulunmazsa, fonksiyon -1 deðerini döndürür
}

