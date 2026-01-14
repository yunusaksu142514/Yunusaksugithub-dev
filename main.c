// Yunus AKSU
// 2420171037
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=7rptPvjrb0

#include <stdio.h>

void dizi_yazdir(int dizi[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%3d", dizi[i]);
    }
    printf("\n");
}

void takas(int *ap, int *bp) {
    int gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

int bolumle(int dizi[], int bas, int son) {
    int pivot = dizi[(bas + son) / 2];
    int i = bas, j = son;
    while (i <= j) {
        while (dizi[i] < pivot) i++;
        while (dizi[j] > pivot) j--;
        if (i <= j) {
            takas(&dizi[i], &dizi[j]);
            i++;
            j--;
        }
    }
    return i;
}

void hizli_sirala(int dizi[], int bas, int son) {
    int indis;
	if (bas < son) {
        indis = bolumle(dizi, bas, son);
        if (bas < indis - 1) {
        	hizli_sirala(dizi, bas, indis - 1);	
		}
        if (indis < son) {
        	hizli_sirala(dizi, indis, son);	
		}
    }
}

int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
	int orta_ind = (ilk_ind + son_ind) / 2;
	
	if (search == dizi[orta_ind]) {
		return orta_ind;
	}
	else if (search > dizi[orta_ind] && (son_ind-ilk_ind) > 0 ) {
		return ikili_arama(dizi, BOYUT, search, orta_ind+1, son_ind);
	} 
	else if (search < dizi[orta_ind] && (son_ind-ilk_ind) > 0) {
		return ikili_arama(dizi, BOYUT, search, ilk_ind, orta_ind-1);
	}
	else {
		return -1;
	}	
}

int main() {
    int A[] = {12, 47, 8, 7, 15, 3, 25, 44, 11, 1}; 
    int n = 10;
    int aranan_eleman;
	int sonuc;

    printf("Orijinal Dizi: ");
    dizi_yazdir(A, n);

    
    hizli_sirala(A, 0, n - 1);
    printf("Siralandiktan Sonra: ");
    dizi_yazdir(A, n);

    
    printf("\aramak istediginiz sayiyi girin: ");
    scanf("%d", &aranan_eleman);

    sonuc = ikili_arama(A, n, aranan_eleman, 0, n-1);
    
    if (sonuc == -1) {
		printf("Aradiginiz deger %d, dizide bulunamadi!\n", aranan_eleman);
	}
	else {
		printf("Aradiginiz deger %d, dizinin %d. indisinde bulundu!\n", aranan_eleman, sonuc);
	}

    return 0;
}
