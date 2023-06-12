/*
  Çift yönlü bağlantılı liste kullanarak 50 kişilik bir sınıfın öğrencinin
  numarası, adı, soyadı, aldığı dersler ve bölümü bilgileri tutulacak bir yapı
  oluşturunuz.. a)Öğrencileri listeleyecek kod kümesini yazınız. b)Sadece veri
  yapıları dersini alan öğrencileri listeleyip kodunu yazınız. c) Öğrencileri
  ismlerine göre a-z şeklinde sırayıp kodunu yazınız. d) Quick sort
  algoritmasıyla veri yapıları ve algoritma analizi derslerini alan öğrencileri
  numaralarına göre sıralayınız. e)Kümeleme sıralama algoritmasını kullanarak
  Veri yapılarını alan öğrencileri numaralarına göre sıralayınız. e)Program
  fonksiyonlarının çalıştığını gösteren ekran çıktılarını ödevinize ekleyiniz.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ogrenci_boyut 50

// öğrenci düğüm yapısı
struct ogrenci {
  int no;
  char ad[ogrenci_boyut];
  char soyad[ogrenci_boyut];
  char dersler[ogrenci_boyut];
  char bolum[ogrenci_boyut];
  struct ogrenci *onceki;
  struct ogrenci *sonraki;
};

typedef struct ogrenci ogrenciPtr;
int ogrenci_adedi = 0;
ogrenciPtr *ogrenci_array[ogrenci_boyut];
ogrenciPtr *baslangic = NULL;
ogrenciPtr *son = NULL;
void ogrenci_bilgi(ogrenciPtr *);
void ogrenci_ekle(int, char[], char[], char[], char[]);
void tum_ogrenci_listele();
void sadece_istenen_dersi_listele(char ders[]);
void sadece_istenen_dersleri_sirala(char dersler[]);
void isme_gore_siralama();
void hizli_siralama(ogrenciPtr[], int, int);
int bolme(ogrenciPtr *, int, int);
void yer_degis(ogrenciPtr *, ogrenciPtr *);
void kumeleriSiralama(ogrenciPtr[], int);
void sadece_istenen_dersleri_kumele(char[]);
int main(int argc, char *argv[]) {
  ogrenci_ekle(1034, "Ali", "Yılmaz", "Veri Yapıları, Algoritma Analizi",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(2345, "Ayşe", "Demir", "Veri Yapıları",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(3456, "Mehmet", "Yıldız", "C Programlama, İşletim Sistemleri",
               "Elektrik-Elektronik Mühendisliği");
  ogrenci_ekle(4567, "Fatma", "Kaya", "Algoritma Analizi, Sayısal Analiz",
               "Matematik");
  ogrenci_ekle(5678, "Ahmet", "Çelik", "C Programlama, Veri Yapıları",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(6789, "Aylin", "Acar", "Sayısal Analiz, İşletim Sistemleri",
               "Endüstri Mühendisliği");
  ogrenci_ekle(7890, "Merve", "Toprak",
               "Veritabanı Yönetimi, Yazılım Mühendisliği",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(8901, "Murat", "Şimşek", "Algoritma Analizi, Sayısal Analiz",
               "Matematik");
  ogrenci_ekle(9012, "Zeynep", "Bakır", "C Programlama, Veri Yapıları",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(1122, "Ayşenur", "Kara", "Mikroişlemciler, Elektrik Devreleri",
               "Elektrik-Elektronik Mühendisliği");
  ogrenci_ekle(2233, "Selin", "Yılmaz", "Yapay Zeka, Veri Madenciliği",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(3344, "Emre", "Gül",
               "C Programlama, Nesne Yönelimli Programlama",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(4455, "Esra", "Doğan", "İşletim Sistemleri, Ağ Programlama",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(5566, "Kadir", "Aktaş", "Veri Yapıları, Algoritma Analizi",
               "Matematik");
  ogrenci_ekle(6677, "Özge", "Öztürk", "Sayısal Analiz, Veri Yapıları",
               "Matematik");
  ogrenci_ekle(7788, "Deniz", "Sarı", "Bilgisayar Ağları, Veritabanı Yönetimi",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(8899, "Yasin", "Yıldırım", "Veri Yapıları",
               "Bilgisayar Mühendisliği");
  ogrenci_ekle(9900, "Nihal", "Arslan", "İşletim Sistemleri, Mikroişlemciler",
               "Elektrik-Elektronik Mühendisliği");
  ogrenci_ekle(1122, "Ayşenur", "Kara", "Mikroişlemciler, Elektrik Devreleri",
               "Elektrik-Elektronik Mühendisliği");
  ogrenci_ekle(2233, "Mehmet", "Yılmaz", "C Programlama, Veri Yapıları",
               "Bilgisayar Mühendisliği");
  // sadece_istenen_dersleri_sirala("Veri Yapıları, Algoritma Analizi");
  sadece_istenen_dersleri_kumele("Veri Yapıları");
  // isme_gore_siralama();
  // tum_ogrenci_listele();
  return 1;
}
void ogrenci_bilgi(ogrenciPtr *ogrenci) {
  printf("Numara: %d\n", ogrenci->no);
  printf("Ad: %s\n", ogrenci->ad);
  printf("Soyad: %s\n", ogrenci->soyad);
  printf("Dersler: %s\n", ogrenci->dersler);
  printf("Bölüm: %s\n", ogrenci->bolum);
  printf("--------------------\n");
}
void ogrenci_ekle(int numara, char ad[], char soyad[], char dersler[],
                  char bolum[]) {
  if (ogrenci_adedi >= 50)
    return;
  ogrenciPtr *yeni_ogrenci = (ogrenciPtr *)malloc(sizeof(struct ogrenci));
  yeni_ogrenci->no = numara;
  strcpy(yeni_ogrenci->ad, ad);
  strcpy(yeni_ogrenci->soyad, soyad);
  strcpy(yeni_ogrenci->dersler, dersler);
  strcpy(yeni_ogrenci->bolum, bolum);
  yeni_ogrenci->onceki = NULL;
  yeni_ogrenci->sonraki = NULL;

  ogrenci_array[ogrenci_adedi] = yeni_ogrenci;
  if (baslangic == NULL) {
    baslangic = yeni_ogrenci;
    son = yeni_ogrenci;
  } else {
    son->sonraki = yeni_ogrenci;
    yeni_ogrenci->onceki = son;
    son = yeni_ogrenci;
  }
  ogrenci_adedi++;
}
void tum_ogrenci_listele() {
  ogrenciPtr *gecici = baslangic;

  while (gecici != NULL) {
    ogrenci_bilgi(gecici);
    gecici = gecici->sonraki;
  }
}
void isme_gore_siralama() {
  ogrenciPtr *gecici;
  ogrenciPtr *i;
  ogrenciPtr *j;

  for (i = baslangic; i != NULL; i = i->sonraki) {
    for (j = i->sonraki; j != NULL; j = j->sonraki) {
      if (strcmp(i->ad, j->ad) > 0) {
        // Eğer i'nin adı j'nin adından büyük ise yer değiştirme işlemi yapılır.
        if (i == baslangic) {
          // i başlangıç düğümü ise, j onun önüne yerleştirilir.
          j->onceki->sonraki = j->sonraki;
          if (j->sonraki != NULL) {
            j->sonraki->onceki = j->onceki;
          }
          j->sonraki = i;
          i->onceki = j;
          j->onceki = NULL;
          baslangic = j;
        } else {
          // i başlangıç düğümü değil ise, i ve j arasındaki düğümler yer
          // değiştirilir.
          j->onceki->sonraki = j->sonraki;
          if (j->sonraki != NULL) {
            j->sonraki->onceki = j->onceki;
          }
          j->sonraki = i;
          j->onceki = i->onceki;
          i->onceki->sonraki = j;
          i->onceki = j;
        }
        // Yer değiştirme işlemi yapıldıktan sonra i ve j düğümleri
        // değiştirilir.
        gecici = i;
        i = j;
        j = gecici;
      }
    }
  }
}
void sadece_istenen_dersleri_sirala(char dersler[]) {
  ogrenciPtr *ogrenci = baslangic;
  ogrenciPtr gecici_ogrenci_array[ogrenci_adedi];
  int adet = 0;
  while (ogrenci != NULL) {
    if (strstr(ogrenci->dersler, dersler) &&
        strlen(ogrenci->dersler) == strlen(dersler)) {
      gecici_ogrenci_array[adet] = *ogrenci;
      adet++;
    }
    ogrenci = ogrenci->sonraki;
  }
  hizli_siralama(gecici_ogrenci_array, 0, adet - 1);
  int i;
  for (i = 0; i < adet; i++) {
    ogrenci_bilgi(&gecici_ogrenci_array[i]);
  }
}
void sadece_istenen_dersleri_kumele(char dersler[]) {
  ogrenciPtr *ogrenci = baslangic;
  ogrenciPtr gecici_ogrenci_array[ogrenci_adedi];
  int adet = 0;
  while (ogrenci != NULL) {
    if (strstr(ogrenci->dersler, dersler) &&
        strlen(ogrenci->dersler) == strlen(dersler)) {
      gecici_ogrenci_array[adet] = *ogrenci;
      adet++;
    }
    ogrenci = ogrenci->sonraki;
  }
  kumeleriSiralama(gecici_ogrenci_array, adet - 1);
  int i;
  for (i = 0; i < adet; i++) {
    ogrenci_bilgi(&gecici_ogrenci_array[i]);
  }
}
void yer_degis(ogrenciPtr *a, ogrenciPtr *b) {
  int t = a->no;
  a->no = b->no;
  b->no = t;
}
int bolme(ogrenciPtr baslangic[], int low, int high) {
  int pivot = baslangic[high].no;
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (baslangic[j].no < pivot) {
      i++;
      yer_degis(&baslangic[i], &baslangic[j]);
    }
  }
  yer_degis(&baslangic[i + 1], &baslangic[high]);
  return (i + 1);
}
void hizli_siralama(ogrenciPtr baslangic[], int low, int high) {
  if (low < high) {
    int pi = bolme(baslangic, low, high);
    hizli_siralama(baslangic, low, pi - 1);
    hizli_siralama(baslangic, pi + 1, high);
  }
}
void sadece_istenen_dersi_listele(char ders[]) {
  ogrenciPtr *ogrenci = baslangic;
  while (ogrenci != NULL) {
    if (strstr(ogrenci->dersler, ders) &&
        strlen(ogrenci->dersler) == strlen(ders)) {
      printf("%d %s %s %s %s\n", ogrenci->no, ogrenci->ad, ogrenci->soyad,
             ogrenci->dersler, ogrenci->bolum);
    }
    ogrenci = ogrenci->sonraki;
  }
}
void kumeleriSiralama(ogrenciPtr baslangic[], int boyut) {
  int max = baslangic[0].no, min = baslangic[0].no;
  int i, j, k;
  int *kumeSayisi;
  int *kumeBasi;

  for (i = 1; i < boyut; i++) {
    if (baslangic[i].no > max) {
      max = baslangic[i].no;
    }
    if (baslangic[i].no < min) {
      min = baslangic[i].no;
    }
  }

  kumeSayisi = (int *)malloc(sizeof(int) * (max - min + 1));
  kumeBasi = (int *)malloc(sizeof(int) * (max - min + 1));

  for (i = 0; i <= max - min; i++) {
    kumeSayisi[i] = 0;
  }

  for (i = 0; i < boyut; i++) {
    kumeSayisi[baslangic[i].no - min]++;
  }

  kumeBasi[0] = 0;
  for (i = 1; i <= max - min; i++) {
    kumeBasi[i] = kumeBasi[i - 1] + kumeSayisi[i - 1];
  }

  ogrenciPtr *geciciDizi = (ogrenciPtr *)malloc(sizeof(struct ogrenci) * boyut);

  for (i = 0; i < boyut; i++) {
    int kume = baslangic[i].no - min;
    geciciDizi[kumeBasi[kume]] = baslangic[i];
    kumeBasi[kume]++;
  }

  for (i = 0; i < boyut; i++) {
    baslangic[i] = geciciDizi[i];
    printf("%s\n", baslangic[i].ad);
  }

  free(geciciDizi);
  free(kumeBasi);
  free(kumeSayisi);
}
