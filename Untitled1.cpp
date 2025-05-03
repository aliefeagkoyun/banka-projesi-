#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
 #include <locale.h> 

void  borcOdeme(int id);
void krediCekme(int id);
 	setlocale(LC_ALL,"Turkish"); 
void dosyaya_yaz();
void faturaKaydet(int id,const char *detay);
void fatura_odeme(int id);

void girisMenu();
void anasayfa(int id);
void sigorta_islem(int id);

void paraIslemleri(int id);
void paraYatirma(int id);
void paraCekme(int id);
void havale(int id);

void kullaniciOku();
void kullaniciYaz();
void girisYap();
void kayitOl();

void arac_sigorta_dosyala(int id);

void sigorta_islem(int id);
void sigortaIslemleri();
void saglikSigortasi(int id);
void konutSigortasi(int id);
void aracSigortasi(int id);



void admin();
void bilgiDegistir(int kullaniciId);
void verileriOku();
void silineneler();
void kayit_sil(int silinecek_id);


void yatirimIslemleri(int id);
void Dovizlerim(int id);

void hisseSenediAl(int id);
void hisseSenediSat(int id);
void hisseSenetlerim(int id);
void hisseSenediYaz();
void hisseSenediOku();
void hisseSenediTemizle(); 


void DolarYaz();
void DolarOku();
void DolarSat(int id);
void DolarSatinAl(int id);
void Dolarlarim(int id);
void DolarTemizle();
void DolarGuncelle(int yenifiyat);
void DolarIslemleri(int id);



void EuroOku();
void EuroYaz();
void EuroSat(int id);
void EuroAl(int id);
void Eurolarim(int id);
void EuroTemizle();
void EuroGuncelle(int yenifiyat);
void EuroIslemleri(int id);


void AltinOku();
void AltinYaz();
void Altinlarim(int id);
void AltinTemizle();
void AltinGuncelle(float yenifiyat);
void AltinSat(int id);
void AltinAl(int id);
void AltinIslemleri(int id);


struct kullanici {
    int id;
    char kullaniciAdi[50];
    char kullaniciSoyisim[50];
    char tc[12];
    char TelNo[11];
    char sifre[50];
    float bakiye;
    int odeme_durumu;
    double borc;
};

struct HisseSenedi {
    int hisseSahipId;
    char hisseAdi[50];
    float hisseFiyati;
    float hisseMiktari;
} hisseSenedi;


struct fatura {
    int faturaSahipId;
    int faturaFiyati;
    char FTelNo[11];

} faturalar;

struct sigorta{
	int fiyat,sigortaSahipId;
    char kayitlisigortalar[50][50],
	  arac_sigorta[10],	 
      plaka[11],


      saglik_sigorta[11],

	  ev_mahalle_sigorta[20],
	   ev_ilce_sigorta[20];
       // float sigortaFiyati = 550; 	
}sigorta;

struct Dolar {
    int DolarSahipId;
    float DolarFiyati;
    float DolarMiktari;
} dolar;

struct Euro {
    int EuroSahipId;
    float EuroFiyati;
    float EuroMiktari;
} Euro;

struct Altin {
    int AltinSahipId;
    float AltinFiyati;
    float AltinMiktari;
} Altin;

char kayitlisigortalar[50][50], saglik_sigorta[11], arac_sigorta[10], ev_mahalle_sigorta[20], ev_ilce_sigorta[20];
	float kayitliborclar[100];

int kullaniciSayisi = 0;
struct kullanici kullanicilar[50];
struct HisseSenedi hisseSenetleri[100];
struct Dolar dolarlar[100];
struct Euro eurolar[100];
struct Altin altinlar[100];

FILE  *sigortabilgileri, *faturabilgileri;

int main() {
    kullaniciOku();
    hisseSenediOku();
    EuroOku();
    DolarOku();
    AltinOku();
    
    girisMenu();
    return 0;
}


void girisMenu() {
     	setlocale(LC_ALL,"Turkish"); 
    printf("1. Kayýt Ol\n");
    printf("2. Giriþ Yap\n");
    printf("3. Çýkýþ\n");
    int secim;
    scanf("%d", &secim);
    switch (secim) {
        case 1:
                    kayitOl();

            break;
        case 2:
                    girisYap();

            break;
        case 3:
            exit(0);
        default:
            printf("Hatalý seçim yaptýnýz.\n");
            girisMenu();
            break;
    }
}
 	setlocale(LC_ALL,"Turkish"); 
void anasayfa(int id) {
    hisseSenediTemizle();
    int cikis = 1;
    while (cikis == 1) {
        kullaniciOku();
        for (int i = 0; i < 100; i++) {
            if (kullanicilar[i].id == id) {
                printf("Bakiyeniz: %.1f TL\n\n", kullanicilar[i].bakiye);
            }
        }

        printf("+----------------------+\n");
        printf("|       Anasayfa       |\n");
        printf("+----------------------+\n");
        printf("| 1. Para Ýþlemleri    |\n");
        printf("| 2. Yatýrým Ýþlemleri |\n");
        printf("| 3. Sigorta Ýþlemleri |\n");
        printf("| 4. Fatura Ödeme      |\n");
        printf("| 5. banka iþlemleri   |\n");
        printf("| 6. Çýkýþ             |\n");
        printf("+----------------------+\n");

        int secim;
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                paraIslemleri(id);
                break;
            case 2:
                yatirimIslemleri(id);
                break;
            case 3:
                sigorta_islem(id);
                break;
            case 4:
                fatura_odeme(id);
                break;
            case 5:
                printf("1.kredi cekimi \n Borc ödeme");
                 int islem;
        scanf("%d", &islem);
        switch (islem) {
        	case 1:
              krediCekme( id);
                break;
            case 2:
               borcOdeme( id);
                break;
        	default:
                printf("Hatalý seçim yaptýnýz.\n");
                anasayfa(id);
                break;
        }
                break;
                case 6:
                cikis = 0;
                break;
            default:
                printf("Hatalý seçim yaptýnýz.\n");
                anasayfa(id);
                break;
        }
    }
}
 	setlocale(LC_ALL,"Turkish"); 
void faturaKaydet(int id, const char *detay) {
    FILE *dosya = fopen("fatura.txt", "a");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    fprintf(dosya, "%d %s\n", id, detay);
    fclose(dosya);
}


void kullaniciOku() {
    FILE *dosya = fopen("kullanicilar.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    
    int i = 0;
    while (fscanf(dosya, "%d %s %s %s %s %s %f %d %lf\n", &kullanicilar[i].id, kullanicilar[i].kullaniciAdi, kullanicilar[i].kullaniciSoyisim, kullanicilar[i].tc, kullanicilar[i].TelNo, kullanicilar[i].sifre, &kullanicilar[i].bakiye, &kullanicilar[i].odeme_durumu, &kullanicilar[i].borc) == 9   ) {
        i++;
        kullaniciSayisi++;
    }
    
    fclose(dosya);
}



void kullaniciYaz() {
	 	setlocale(LC_ALL,"Turkish"); 
    FILE *dosya = fopen("kullanicilar.txt", "w");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }

    for (int i = 0; i < kullaniciSayisi+1; i++) {

        if (kullanicilar[i].id != 0) {
            fprintf(dosya, "%d %s %s %s %s %s %f %d %lf\n",
                kullanicilar[i].id,
                kullanicilar[i].kullaniciAdi,
                kullanicilar[i].kullaniciSoyisim,
                kullanicilar[i].tc,
                kullanicilar[i].TelNo,
                kullanicilar[i].sifre,
                kullanicilar[i].bakiye,
                kullanicilar[i].odeme_durumu,
				kullanicilar[i].borc);
        }
    }

    fclose(dosya);
}



void kayitOl() {
	 	setlocale(LC_ALL,"Turkish"); 
    kullaniciOku();
    int id;
    char kullaniciAdi[50];
    char kullaniciSoyisim[50];
    char Telno[11];
    char tc[12];
    char sifre[50];

    printf("Kullanýcý Adý: ");
    scanf("%s", kullaniciAdi);
    printf("Kullanýcý Soyisim: ");
    scanf("%s", kullaniciSoyisim);
    printf("TC Numaranýz: ");
    scanf("%s", tc);
    printf("Telefon Numaranýz: ");
    scanf("%s", Telno);
    printf("Þifre: ");
    scanf("%s", sifre);


    for (int i = 0; i < 100; i++) {
        if (strcmp(kullanicilar[i].kullaniciAdi, kullaniciAdi) == 0) {
            printf("Kullanýcý adý zaten mevcut.\n");
            girisMenu();
            return;
        }
        if (kullanicilar[i].id == 0) {
            
            id = i + 1;
            kullanicilar[i].id = id;
            strcpy(kullanicilar[i].kullaniciAdi, kullaniciAdi);
            strcpy(kullanicilar[i].kullaniciSoyisim,kullaniciSoyisim);
            strcpy(kullanicilar[i].tc,tc);
            strcpy(kullanicilar[i].TelNo,Telno);
            strcpy(kullanicilar[i].sifre, sifre);
            kullanicilar[i].bakiye = 0;
            break;
        }
    }
    
    printf("Kayýt baþarýlý.\n");
    kullaniciYaz();
    girisMenu();
}

void girisYap() {
    char kullaniciAdi[50];
    char sifre[50];
    printf("Kullanýcý Adý: ");
    scanf("%s", kullaniciAdi);
    printf("Þifre: ");
    scanf("%s", sifre);
      if (strcmp(kullaniciAdi, "admin") == 0 && strcmp(sifre, "0000") == 0) {
        printf("Giriþ baþarýlý. Admin sayfasýna yönlendiriliyorsunuz...\n");
        admin();
        return;
    }
    for (int i = 0; i < 100; i++) {
        if (strcmp(kullanicilar[i].kullaniciAdi, kullaniciAdi) == 0 && strcmp(kullanicilar[i].sifre, sifre) == 0) {
            printf("Giriþ baþarýlý.\n");
            anasayfa(kullanicilar[i].id);
            return;
        }
    }
    printf("Kullanýcý adý veya þifre hatalý.\n");
    girisMenu();
}

void paraIslemleri(int id) {
    kullaniciOku();
    printf("+-------------------+\n");
    printf("|  Para Ýþlemleri   |\n");
    printf("+-------------------+\n");
    printf("| 1. Para Yatýrma   |\n");
    printf("| 2. Para Çekme     |\n");
    printf("| 3. Havale         |\n");
    printf("| 4. banka iþlemleri|\n");
    printf("| 5. Geri           |\n");
    printf("+-------------------+\n");
    int secim;
    scanf("%d", &secim);
    switch (secim) {
        case 1:
            paraYatirma(id);
            break;
        case 2:
            paraCekme(id);
            break;
        case 3:
            havale(id);
            break;
        case 4:
            anasayfa(id);
            break;
        default:
            printf("Hatalý seçim yaptýnýz.\n");
            paraIslemleri(id);
            break;
    }
}

void paraYatirma(int id) {
    double miktar;
    printf("Yatýrýlacak miktar: ");
    scanf("%lf", &miktar);
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
            kullanicilar[i].bakiye += miktar;
            kullaniciYaz();
            printf("Para yatýrma iþlemi baþarýlý.\n");
            break;
        }
    }
}

void paraCekme(int id) {
    kullaniciOku();
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
            printf("Bakiyeniz: %.1f TL\n",kullanicilar[i].bakiye);
        }
    }double miktar;
    printf("Çekilecek miktar: ");
    scanf("%lf", &miktar);
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
            if (kullanicilar[i].bakiye >= miktar) {
                kullanicilar[i].bakiye -= miktar;
                kullaniciYaz();
                printf("Para çekme iþlemi baþarýlý.\n");
                printf("Yeni Bakiyeniz: %.1f TL\n",kullanicilar[i].bakiye);
                break;
            } else {
                printf("Yetersiz bakiye.\n");
                break;
            }
        }
    }
}

void havale(int id) {
    double miktar;
    int aliciId;
    printf("Alýcý ID: ");
    scanf("%d", &aliciId);
    printf("Gönderilecek miktar: ");
    scanf("%lf", &miktar);
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == aliciId) {
            for (int j = 0; j < 100; j++) {
                if (kullanicilar[j].id == id) {
                    if (kullanicilar[j].bakiye >= miktar) {
                        kullanicilar[j].bakiye -= miktar;
                        kullanicilar[i].bakiye += miktar;
                        kullaniciYaz();
                        printf("Havale iþlemi baþarýlý.\n");
                        return;
                    } else {
                        printf("Yetersiz bakiye.\n");
                        return;
                    }
                }
            }
        }
    }
}

void yatirimIslemleri(int id) {
    hisseSenediOku();

    int secim;
    kullaniciOku();

    printf("+------------------------+\n");
    printf("|   Yatýrým Ýþlemleri    |\n");
    printf("+------------------------+\n");
    printf("| 1. Hisse Senedi Al/Sat |\n");
    printf("| 2. Döviz Al/Sat        |\n");
    printf("| 9. Geri Dön            |\n");
    printf("+------------------------+\n");

    scanf("%d", &secim);
    switch (secim) {
        case 1:
            // Hisse senedi iþlemleri
            hisseSenetlerim(id);
            kullaniciOku();
            for (int i = 0; i < 100; i++) {
                if (kullanicilar[i].id == id) {
                    printf("Bakiyeniz: %.1f TL\n", kullanicilar[i].bakiye);
                }
            }
            printf("1. Hisse Senedi Al\n");
            printf("2. Hisse Senedi Sat\n");
            printf("9. Geri\n");
            scanf("%d", &secim);
            switch (secim) {
                case 1:
                    hisseSenediAl(id);
                    break;
                case 2:
                    hisseSenediSat(id);
                    break;
                case 9:
                    yatirimIslemleri(id);
                    break;
                default:
                    printf("Hatalý seçim yaptýnýz.\n");
                    yatirimIslemleri(id);
                    break;
            }
            break;
        case 2:
            // Döviz iþlemleri
            printf("1. Dolar iþlemler\n");
            printf("2. Euro iþlemler\n");
            printf("3. Altýn iþlemler\n");  
            printf("4. Dövizlerim\n");
            printf("9. Geri\n");
            scanf("%d", &secim);
            switch (secim) {
                case 1:
                    // Dolar iþlemleri
                    DolarIslemleri(id);
                    break;
                case 2:
                    // Euro iþlemleri
                    EuroIslemleri(id);
                    break; 
                case 3:
                    // Altýn iþlemleri
                    AltinIslemleri(id);
                    break;
                case 4:
                    // Dövizlerim
                    Dovizlerim(id);
                    break;
              
                case 9:
                    yatirimIslemleri(id);
                    break;
                default:
                    printf("Hatalý seçim yaptýnýz.\n");
                    yatirimIslemleri(id);
                    break;
            }
            break;
        
        case 9:
            anasayfa(id);
            break;
        default:
            printf("Hatalý seçim yaptýnýz.\n");
            yatirimIslemleri(id);
            break;
    }
}




void hisseSenediYaz() {
    FILE *dosya = fopen("hisseSenedi.txt", "w");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    for (int i = 0; i < 100; i++) {
        if (hisseSenetleri[i].hisseSahipId != 0) {
            fprintf(dosya, "%d %s %.1f %.1f\n", hisseSenetleri[i].hisseSahipId, hisseSenetleri[i].hisseAdi, hisseSenetleri[i].hisseFiyati, hisseSenetleri[i].hisseMiktari);
        }
    }
    fclose(dosya);
}

void hisseSenediOku() {
    FILE *dosya = fopen("hisseSenedi.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(dosya, "%d %s %f %f\n", &hisseSenetleri[i].hisseSahipId, hisseSenetleri[i].hisseAdi, &hisseSenetleri[i].hisseFiyati, &hisseSenetleri[i].hisseMiktari) == 4) {
        i++;
    }
    fclose(dosya);
}

void hisseSenediSat(int id) {
    hisseSenediOku();
    hisseSenetlerim(id);
    int sayac = 0;
    for (int i = 0; i < 100; i++) {
        if (hisseSenetleri[i].hisseSahipId == id) {
            if(hisseSenetleri[i].hisseMiktari > 0) {
                printf("%d. %s - %.1f TL - %.1f adet\n", i + 1, hisseSenetleri[i].hisseAdi, hisseSenetleri[i].hisseFiyati, hisseSenetleri[i].hisseMiktari);
                sayac++;
            }
        }
    }
    int secim;
    if(sayac == 0) {
        printf("Satýlacak hisse senedi bulunamadý.\n");
        return;
    }
    printf("Satýlacak hisse senedi: ");
    scanf("%d", &secim);
    int miktar;
    printf("Satýlacak miktar: ");
    scanf("%d", &miktar);
    printf("Onaylýyor musunuz? (E/H)\n");
    char onay;
    scanf(" %c", &onay);
    if (onay == 'E' || onay == 'e') {
        for (int i = 0; i < 100; i++) {
            if (hisseSenetleri[i].hisseSahipId == id) {
                if (secim == i + 1 && hisseSenetleri[i].hisseMiktari >= miktar) {
                    for (int j = 0; j < 100; j++) {
                        if (kullanicilar[j].id == id) {
                            kullanicilar[j].bakiye += miktar * hisseSenetleri[i].hisseFiyati;
                            hisseSenetleri[i].hisseMiktari -= miktar;
                            kullaniciYaz();
                            hisseSenediYaz();
                            printf("Hisse senedi satýþý baþarýlý.\n");
                            return;
                        }
                    }
                }
            }
        }
    } else {
        printf("Ýþlem iptal edildi.\n");
    }


}

void hisseSenediAl(int id) {
    kullaniciOku();
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
    printf("Bakiyeniz: %.1f TL\n",kullanicilar[i].bakiye);
        }
    }
    int secim;
            printf("\n----------------------\n");
            printf("| Google - 100 TL    |\n");
            printf("| Apple - 200 TL     |\n");
            printf("| Facebook - 300 TL  |\n");
            printf("| Amazon - 400 TL    |\n");
            printf("| Microsoft - 500 TL |\n");
            printf("----------------------\n");
            scanf("%d", &secim);
    int miktar;
    printf("Alýnacak miktar: ");
    scanf("%d", &miktar);
    switch (secim) {
        case 1:
            printf("Google hisse senedi alýnacak.\n");
            printf("Alýnacak miktar: %d\n", miktar);
            printf("Toplam tutar: %d\n", miktar * 100);
            break;
        case 2:
            printf("Apple hisse senedi alýnacak.\n");
            printf("Alýnacak miktar: %d\n", miktar);
            printf("Toplam tutar: %d\n", miktar * 200);
            break;
        case 3:
            printf("Facebook hisse senedi alýnacak.\n");
            printf("Alýnacak miktar: %d\n", miktar);
            printf("Toplam tutar: %d\n", miktar * 300);
            break;
        case 4:
            printf("Amazon hisse senedi alýnacak.\n");
            printf("Alýnacak miktar: %d\n", miktar);
            printf("Toplam tutar: %d\n", miktar * 400);
            break;
        case 5:
            printf("Microsoft hisse senedi alýnacak.\n");
            printf("Alýnacak miktar: %d\n", miktar);
            printf("Toplam tutar: %d\n", miktar * 500);
            break;
        default:
            printf("Hatalý seçim yaptýnýz.\n");
            hisseSenediAl(id);
            return;
    }
    printf("Onaylýyor musunuz? (E/H)\n");
    char onay;
    scanf(" %c", &onay);
    if (onay == 'E' || onay == 'e') {
        for (int i = 0; i < 100; i++) {
            if (kullanicilar[i].id == id) {
                if (kullanicilar[i].bakiye >= miktar * secim * 100) {
                    kullanicilar[i].bakiye -= miktar * secim * 100;
                    for (int j = 0; j < 100; j++) {
                        if (hisseSenetleri[j].hisseSahipId == 0) {
                            hisseSenetleri[j].hisseSahipId = id;
                            switch (secim) {
                                case 1:
                                    strcpy(hisseSenetleri[j].hisseAdi, "Google");
                                    hisseSenetleri[j].hisseFiyati = 100;
                                    hisseSenetleri[j].hisseMiktari = miktar;
                                    break;
                                case 2:
                                    strcpy(hisseSenetleri[j].hisseAdi, "Apple");
                                    hisseSenetleri[j].hisseFiyati = 200;
                                    hisseSenetleri[j].hisseMiktari = miktar;
                                    break;
                                case 3:
                                    strcpy(hisseSenetleri[j].hisseAdi, "Facebook");
                                    hisseSenetleri[j].hisseFiyati = 300;
                                    hisseSenetleri[j].hisseMiktari = miktar;
                                    break;
                                case 4:
                                    strcpy(hisseSenetleri[j].hisseAdi, "Amazon");
                                    hisseSenetleri[j].hisseFiyati = 400;
                                    hisseSenetleri[j].hisseMiktari = miktar;
                                    break;
                                case 5:
                                    strcpy(hisseSenetleri[j].hisseAdi, "Microsoft");
                                    hisseSenetleri[j].hisseFiyati = 500;
                                    hisseSenetleri[j].hisseMiktari = miktar;
                                    break;
                                default:
                                    break;
                            }
                            break;
                        }
                    }

                    kullaniciYaz();
                    hisseSenediYaz();
                    printf("Hisse senedi alýmý baþarýlý.\n");
                    return;
                } else {
                    printf("Yetersiz bakiye.\n");
                    return;
                }

            }
        }
    } else {
        printf("Ýþlem iptal edildi.\n");
    }
}

void hisseSenetlerim(int id) {
    hisseSenediOku();
    printf("+------------------------------+------------+------------+\n");
    printf("| Hisse Adý                    | Fiyat (TL) | Miktar     |\n");
    printf("+------------------------------+------------+------------+\n");
    for (int i = 0; i < 100; i++) {
        if (hisseSenetleri[i].hisseSahipId == id) {
            printf("| %-28s | %10.2f | %10.2f |\n", 
                hisseSenetleri[i].hisseAdi, 
                hisseSenetleri[i].hisseFiyati, 
                hisseSenetleri[i].hisseMiktari);

        } 

    }
    printf("+------------------------------+------------+------------+\n\n");
}

void hisseSenediTemizle() {

    hisseSenediOku();
    for (int i = 0; i < 100; i++) {
        if (hisseSenetleri[i].hisseMiktari == 0) {
            hisseSenetleri[i].hisseSahipId = 0;
            strcpy(hisseSenetleri[i].hisseAdi, "");
            hisseSenetleri[i].hisseFiyati = 0;
            hisseSenetleri[i].hisseMiktari = 0;
        }
    }
    hisseSenediYaz();
}


void dolarYaz() {
    FILE *dosya = fopen("dolar.txt", "w");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    for (int i = 0; i < 100; i++) {
        if (dolarlar[i].DolarSahipId != 0) {
            fprintf(dosya, "%d %.1f %.1f\n", dolarlar[i].DolarSahipId, dolarlar[i].DolarFiyati, dolarlar[i].DolarMiktari);
        }
    }
    fclose(dosya);
}

void DolarOku() {
    FILE *dosya = fopen("dolar.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(dosya, "%d %f %f\n", &dolarlar[i].DolarSahipId, &dolarlar[i].DolarFiyati, &dolarlar[i].DolarMiktari) == 3) {
        i++;
    }
    fclose(dosya);
}

void DolarSat(int id) {
	kullaniciOku();
    DolarOku();
    for (int i = 0; i < 100; i++) {
        if (dolarlar[i].DolarSahipId == id) {
            printf("Dolar miktarýnýz: %.1f\n", dolarlar[i].DolarMiktari);
        }
    }
    float miktar;
    printf("Satýlacak miktar: ");
    scanf("%f", &miktar);
    printf("Onaylýyor musunuz? (E/H)\n");
    char onay;
    scanf(" %c", &onay);
    if (onay == 'E' || onay == 'e') {
        for (int i = 0; i < 100; i++) {
            if (dolarlar[i].DolarSahipId == id) {
                if (dolarlar[i].DolarMiktari >= miktar) {
                    for (int j = 0; j < 100; j++) {
                        if (kullanicilar[j].id == id) {
                            kullanicilar[j].bakiye += miktar * dolarlar[i].DolarFiyati;
                            dolarlar[i].DolarMiktari -= miktar;
                            kullaniciYaz();
                            dolarYaz();
                            printf("Dolar satýþý baþarýlý.\n");
                            return;
                        }
                    }
                } else {
                    printf("Yetersiz dolar miktarý.\n");
                    return;
                }
            }
        }
    } else {
        printf("Ýþlem iptal edildi.\n");
    }
}
void DolarSatinAl(int id) {
    kullaniciOku();
    DolarOku();
    double miktar;
    double dolarFiyati = 32.0; // Varsayýlan dolar fiyatý

    // Kullanýcýnýn mevcut bakiyesini göster
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
            printf("Bakiyeniz: %.1f TL\n", kullanicilar[i].bakiye);
            break;
        }
    }

    // Alýnacak dolar miktarýný kullanýcýdan al
    printf("Alýnacak miktar (Dolar): ");
    scanf("%lf", &miktar);
    printf("Onaylýyor musunuz? (E/H): ");
    char onay;
    scanf(" %c", &onay);

    if (onay == 'E' || onay == 'e') {
        for (int i = 0; i < 100; i++) {
            if (kullanicilar[i].id == id) {
                double toplamTutar = miktar * dolarFiyati;
                if (kullanicilar[i].bakiye >= toplamTutar) {
                    kullanicilar[i].bakiye -= toplamTutar;

                    // Dolar bilgilerini güncelle
                    int dolarIndex = -1;
                    for (int j = 0; j < 100; j++) {
                        if (dolarlar[j].DolarSahipId == id) {
                            dolarIndex = j;
                            break;
                        }
                    }

                    if (dolarIndex == -1) {
                        // Yeni dolar kaydý ekle
                        for (int j = 0; j < 100; j++) {
                            if (dolarlar[j].DolarSahipId == 0) {
                                dolarlar[j].DolarSahipId = id;
                                dolarlar[j].DolarFiyati = dolarFiyati;
                                dolarlar[j].DolarMiktari = miktar;
                                break;
                            }
                        }
                    } else {
                        // Mevcut dolar kaydýný güncelle
                        dolarlar[dolarIndex].DolarMiktari += miktar;
                    }

                    kullaniciYaz();
                    dolarYaz();
                    printf("Dolar alýmý baþarýlý.\n");
                    return;
                } else {
                    printf("Yetersiz bakiye.\n");
                    return;
                }
            }
        }
    } else {
        printf("Ýþlem iptal edildi.\n");
    }
}
void Dolarlarim(int id) {
    DolarOku();
    printf("+-----------------+------------+------------+\n");
    printf("| %-15s | %-10s | %-10s |\n", "Döviz", "Fiyat (TL)", "Miktar");
    printf("+-----------------+------------+------------+\n");
    for (int i = 0; i < 100; i++) {
        if (dolarlar[i].DolarSahipId == id) {
            printf("| %-15s | %10.2f | %10.2f |\n", "Dolar", dolarlar[i].DolarFiyati, dolarlar[i].DolarMiktari);
        }
    }
    printf("+-----------------+------------+------------+\n\n");
}

void DolarTemizle() {
    DolarOku();
    for (int i = 0; i < 100; i++) {
        if (dolarlar[i].DolarMiktari == 0) {
            dolarlar[i].DolarSahipId = 0;
            dolarlar[i].DolarFiyati = 0;
            dolarlar[i].DolarMiktari = 0;
        }
    }
    dolarYaz();
}

void DolarGuncelle(int yenifiyat) {
    DolarOku();
    for (int i = 0; i < 100; i++) {
        if (dolarlar[i].DolarSahipId != 0) {
            dolarlar[i].DolarFiyati = yenifiyat;
        }
    }
    dolarYaz();
}

void DolarIslemleri(int id) {
    printf("1. Dolar Al\n");
    printf("2. Dolar Sat\n");
    printf("3. Dolarlarim\n");
    printf("9. Geri\n");
    int secim;
    scanf("%d", &secim);
    switch (secim) {
        case 1:
            DolarSatinAl(id);
            break;
        case 2:
            DolarSat(id);
            break;
        case 3:
            Dolarlarim(id);
            break;
        case 9:
            yatirimIslemleri(id);
            break;
        default:
            printf("Hatalý seçim yaptýnýz.\n");
            DolarIslemleri(id);
            break;
    }
}





void EuroYaz() {
    FILE *dosya = fopen("euro.txt", "w");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    for (int i = 0; i < 100; i++) {
        if (eurolar[i].EuroSahipId != 0) {
            fprintf(dosya, "%d %.1f %.1f\n", eurolar[i].EuroSahipId, eurolar[i].EuroFiyati, eurolar[i].EuroMiktari);
        }
    }
    fclose(dosya);
}

void EuroOku() {
    FILE *dosya = fopen("euro.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(dosya, "%d %f %f\n", &eurolar[i].EuroSahipId, &eurolar[i].EuroFiyati, &eurolar[i].EuroMiktari) == 3) {
        i++;
    }
    fclose(dosya);
}

void EuroSat(int id) {
	kullaniciOku();
    EuroOku();
    for (int i = 0; i < 100; i++) {
        if (eurolar[i].EuroSahipId == id) {
            printf("Euro miktarýnýz: %.1f\n", eurolar[i].EuroMiktari);
        }
    }
    float miktar;
    printf("Satýlacak miktar: ");
    scanf("%f", &miktar);
    printf("Onaylýyor musunuz? (E/H)\n");
    char onay;
    scanf(" %c", &onay);
    if (onay == 'E' || onay == 'e') {
        for (int i = 0; i < 100; i++) {
            if (eurolar[i].EuroSahipId == id) {
                if (eurolar[i].EuroMiktari >= miktar) {
                    for (int j = 0; j < 100; j++) {
                        if (kullanicilar[j].id == id) {
                            kullanicilar[j].bakiye += miktar * eurolar[i].EuroFiyati;
                            eurolar[i].EuroMiktari -= miktar;
                            kullaniciYaz();
                            EuroYaz();
                            printf("Euro satýþý baþarýlý.\n");
                            return;
                        }
                    }
                } else {
                    printf("Yetersiz euro miktarý.\n");
                    return;
                }
            }
        }
    } else {
        printf("Ýþlem iptal edildi.\n");
    }
}
void EuroAl(int id) {
    kullaniciOku();
    EuroOku();
    double miktar;
    double EuroFiyati = 38.0; // Örnek fiyat

    // Kullanýcýnýn mevcut bakiyesini göster
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
            printf("Bakiyeniz: %.1f TL\n", kullanicilar[i].bakiye);
            break;
        }
    }

    // Alýnacak Euro miktarýný kullanýcýdan al
    printf("Alýnacak miktar: ");
    scanf("%lf", &miktar);
    printf("Onaylýyor musunuz? (E/H): ");
    char onay;
    scanf(" %c", &onay);

    if (onay == 'E' || onay == 'e') {
        for (int i = 0; i < 100; i++) {
            if (kullanicilar[i].id == id) {
                double toplamTutar = miktar * EuroFiyati;
                if (kullanicilar[i].bakiye >= toplamTutar) {
                    kullanicilar[i].bakiye -= toplamTutar;

                    // Euro bilgilerini güncelle
                    int euroIndex = -1;
                    for (int j = 0; j < 100; j++) {
                        if (eurolar[j].EuroSahipId == id) {
                            euroIndex = j;
                            break;
                        }
                    }

                    if (euroIndex == -1) {
                        // Yeni euro kaydý ekle
                        for (int j = 0; j < 100; j++) {
                            if (eurolar[j].EuroSahipId == 0) {
                                eurolar[j].EuroSahipId = id;
                                eurolar[j].EuroFiyati = EuroFiyati;
                                eurolar[j].EuroMiktari = miktar;
                                break;
                            }
                        }
                    } else {
                        // Mevcut euro kaydýný güncelle
                        eurolar[euroIndex].EuroMiktari += miktar;
                    }

                    kullaniciYaz();
                    EuroYaz();
                    printf("Euro alýmý baþarýlý.\n");
                    return;
                } else {
                    printf("Yetersiz bakiye.\n");
                    return;
                }
            }
        }
    } else {
        printf("Ýþlem iptal edildi.\n");
    }
}

void Eurolarim(int id) {
    EuroOku();
    printf("+-----------------+------------+------------+\n");
    printf("| %-15s | %-10s | %-10s |\n", "Döviz", "Fiyat (TL)", "Miktar");
    printf("+-----------------+------------+------------+\n");
    for (int i = 0; i < 100; i++) {
        if (eurolar[i].EuroSahipId == id) {
            printf("| %-15s | %10.2f | %10.2f |\n", "Euro", eurolar[i].EuroFiyati, eurolar[i].EuroMiktari);
        }
    }
    printf("+-----------------+------------+------------+\n\n");
}

void EuroTemizle() {
    EuroOku();
    for (int i = 0; i < 100; i++) {
        if (eurolar[i].EuroMiktari == 0) {
            eurolar[i].EuroSahipId = 0;
            eurolar[i].EuroFiyati = 0;
            eurolar[i].EuroMiktari = 0;
        }
    }
    EuroYaz();
}

void EuroGuncelle(int yenifiyat) {
    EuroOku();
    for (int i = 0; i < 100; i++) {
        if (eurolar[i].EuroSahipId != 0) {
            eurolar[i].EuroFiyati = yenifiyat;
        }
    }
    EuroYaz();
}

void EuroIslemleri(int id) {
    printf("1. Euro Al\n");
    printf("2. Euro Sat\n");
    printf("3. Eurolarim\n");
    printf("9. Geri\n");
    int secim;
    scanf("%d", &secim);
    switch (secim) {
        case 1:
            EuroAl(id);
            break;
        case 2:
            EuroSat(id);
            break;
        case 3:
            Eurolarim(id);
            break;
        case 9:
            yatirimIslemleri(id);
            break;
        default:
            printf("Hatalý seçim yaptýnýz.\n");
            EuroIslemleri(id);
            break;
    }
}




void AltinYaz() {
    FILE *dosya = fopen("altin.txt", "w");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    for (int i = 0; i < 100; i++) {
        if (altinlar[i].AltinSahipId != 0) {
            fprintf(dosya, "%d %.1f %.1f\n", altinlar[i].AltinSahipId, altinlar[i].AltinFiyati, altinlar[i].AltinMiktari);
        }
    }
    fclose(dosya);
}

void AltinOku() {
    FILE *dosya = fopen("altin.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(dosya, "%d %f %f\n", &altinlar[i].AltinSahipId, &altinlar[i].AltinFiyati, &altinlar[i].AltinMiktari) == 3) {
        i++;
    }
    fclose(dosya);
}

void Altinlarim(int id) {
    AltinOku();
    printf("+-----------------+------------+------------+\n");
    printf("| %-15s | %-10s | %-10s |\n", "Döviz", "Fiyat (TL)", "Miktar");
    printf("+-----------------+------------+------------+\n");
    for (int i = 0; i < 100; i++) {
        if (altinlar[i].AltinSahipId == id) {
            printf("| %-15s | %10.2f | %10.2f |\n", "Altin", altinlar[i].AltinFiyati, altinlar[i].AltinMiktari);
        }
    }
    printf("+-----------------+------------+------------+\n\n");
}

void AltinTemizle() {
    AltinOku();
    for (int i = 0; i < 100; i++) {
        if (altinlar[i].AltinMiktari == 0) {
            altinlar[i].AltinSahipId = 0;
            altinlar[i].AltinFiyati = 0;
            altinlar[i].AltinMiktari = 0;
        }
    }
    AltinYaz();
}

void AltinGuncelle(float yenifiyat) {
    AltinOku();
    for (int i = 0; i < 100; i++) {
        if (altinlar[i].AltinSahipId != 0) {
            altinlar[i].AltinFiyati = yenifiyat;
        }
    }
    AltinYaz();
}

void AltinSat(int id) {
	kullaniciOku();
    AltinOku();
    for (int i = 0; i < 100; i++) {
        if (altinlar[i].AltinSahipId == id) {
            printf("Altýn miktarýnýz: %.1f\n", altinlar[i].AltinMiktari);
        }
    }
    float miktar;
    printf("Satýlacak miktar: ");
    scanf("%f", &miktar);
    printf("Onaylýyor musunuz? (E/H)\n");
    char onay;
    scanf(" %c", &onay);
    if (onay == 'E' || onay == 'e') {
        for (int i = 0; i < 100; i++) {
            if (altinlar[i].AltinSahipId == id) {
                if (altinlar[i].AltinMiktari >= miktar) {
                    for (int j = 0; j < 100; j++) {
                        if (kullanicilar[j].id == id) {
                            kullanicilar[j].bakiye += miktar * altinlar[i].AltinFiyati;
                            altinlar[i].AltinMiktari -= miktar;
                            kullaniciYaz();
                            AltinYaz();
                            printf("Altýn satýþý baþarýlý.\n");
                            return;
                        }
                    }
                } else {
                    printf("Yetersiz altýn miktarý.\n");
                    return;
                }
            }
        }
    } else {
        printf("Ýþlem iptal edildi.\n");
    }
}

void AltinAl(int id) {
	kullaniciOku();
    AltinOku();
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
            printf("Bakiyeniz: %.1f TL\n", kullanicilar[i].bakiye);
        }
    }
    float miktar;
    printf("Alýnacak miktar: ");
    scanf("%f", &miktar);
    printf("Onaylýyor musunuz? (E/H)\n");
    char onay;
    scanf(" %c", &onay);
    if (onay == 'E' || onay == 'e') {
        for (int i = 0; i < 100; i++) {
            if (kullanicilar[i].id == id) {
                if (kullanicilar[i].bakiye >= miktar * altinlar[i].AltinFiyati) {
                    kullanicilar[i].bakiye -= miktar * altinlar[i].AltinFiyati;
                    for (int j = 0; j < 100; j++) {
                        if (altinlar[j].AltinSahipId == 0) {
                            altinlar[j].AltinSahipId = id;
                            altinlar[j].AltinFiyati = 500; // Örnek fiyat
                            altinlar[j].AltinMiktari = miktar;
                            break;
                        }
                    }
                    kullaniciYaz();
                    AltinYaz();
                    printf("Altýn alýmý baþarýlý.\n");
                    return;
                } else {
                    printf("Yetersiz bakiye.\n");
                    return;
                }
            }
        }
    } else {
        printf("Ýþlem iptal edildi.\n");
    }
}

void AltinIslemleri(int id) {
    printf("1. Altýn Al\n");
    printf("2. Altýn Sat\n");
    printf("3. Altýnlarim\n");
    printf("9. Geri\n");
    int secim;
    scanf("%d", &secim);
    switch (secim) {
        case 1:
            AltinAl(id);
            break;
        case 2:
            AltinSat(id);
            break;
        case 3:
            Altinlarim(id);
            break;
        case 9:
            yatirimIslemleri(id);
            break;
        default:
            printf("Hatalý seçim yaptýnýz.\n");
            AltinIslemleri(id);
            break;
    }
}



void Dovizlerim(int id) {
    printf("+-----------------+------------+------------+\n");
    printf("| %-15s | %-10s | %-10s |\n", "Döviz", "Fiyat (TL)", "Miktar");
    printf("+-----------------+------------+------------+\n");

    DolarOku();
    for (int i = 0; i < 100; i++) {
        if (dolarlar[i].DolarSahipId == id) {
            printf("| %-15s | %10.2f | %10.2f |\n", "Dolar", dolarlar[i].DolarFiyati, dolarlar[i].DolarMiktari);
        }
    }

    EuroOku();
    for (int i = 0; i < 100; i++) {
        if (eurolar[i].EuroSahipId == id) {
            printf("| %-15s | %10.2f | %10.2f |\n", "Euro", eurolar[i].EuroFiyati, eurolar[i].EuroMiktari);
        }
    }

    AltinOku();
    for (int i = 0; i < 100; i++) {
        if (altinlar[i].AltinSahipId == id) {
            printf("| %-15s | %10.2f | %10.2f |\n", "Altýn", altinlar[i].AltinFiyati, altinlar[i].AltinMiktari);
        }
    }

    printf("+-----------------+------------+------------+\n\n");
}



void sigorta_islem(int id)
{
	for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {

            int islem, secim, x, j, a;
            int fatura = 550;
            char arac_sigorta[20];
            char ev_ilce_sigorta[50];
            char ev_mahalle_sigorta[50];
            char saglik_sigorta[12];
            char kayitlisigortalar[100][50];

            kullaniciOku();  // Mevcut kullanýcýlarý oku

            int k = 0;
            FILE *sigortabilgileri = fopen("sigortabilgileri.txt", "a");
            fclose(sigortabilgileri);
            sigortabilgileri = fopen("sigortabilgileri.txt", "r");
            while (fscanf(sigortabilgileri, "%s", kayitlisigortalar[k]) != EOF) {
                k++;
            }
            fclose(sigortabilgileri);

            printf("\n1.Arac Sigortasi\n2.Konut Sigortasi\n3.Saglik Sigortasi\n4.Ana Menu\n");
            while (1) {
                scanf("%d", &secim);
                if (secim == 1) {
                    printf("Lutfen arac plakanizi birlesik sekilde giriniz. Ana Menuye donmek icin '0'a basiniz...\n");
                    while (1) {
                        scanf("%s", arac_sigorta);
                        x = strlen(arac_sigorta) - 1;
                        for (j = 0; j < k; j++) {
                            if (strcmp(kayitlisigortalar[j], arac_sigorta) == 0) {
                                printf("Bu plakali araca ait zaten bir sigorta bulunmaktadir.\n");
                                sleep(2);
                                anasayfa(kullanicilar[i].id);
                            }
                        }

                        if (arac_sigorta[0] == '0' && strlen(arac_sigorta) == 1) {
                            anasayfa(kullanicilar[i].id);
                        } else {
                            // Plaka doðrulama kontrolleri
                            if (strlen(arac_sigorta) < 5) {
                                printf("Arac plakasinin minimum uzunlugu 5 karakterdir. Tekrar deneyin veya ana menuye donmek icin '0'a basiniz...\n");
                            } else if (!(arac_sigorta[0] >= '0' && arac_sigorta[0] <= '9') || !(arac_sigorta[1] >= '0' && arac_sigorta[1] <= '9')) {
                                printf("Plakanizin ilk 2 karakteri il kodu olan sayiyi icermelidir. Tekrar deneyin veya ana menuye donmek icin '0'a basiniz...\n");
                            } else if ((arac_sigorta[2] >= '0' && arac_sigorta[2] <= '9') || (arac_sigorta[0] > '8') || (arac_sigorta[0] == '8' && arac_sigorta[1] > '1')) {
                                printf("Il kodu maksimum '81' olmadlidir. Tekrar deneyin veya ana menuye donmek icin '0'a basiniz...\n");
                            } else if (!(arac_sigorta[x] >= '0' && arac_sigorta[x] <= '9') || !(arac_sigorta[x - 1] >= '0' && arac_sigorta[x - 1] <= '9')) {
                                printf("Plakanin son 2 kisminda bir harf bulunamaz. Tekrar deneyin veya ana menuye donmek icin '0'a basiniz...\n");
                            } else if ((arac_sigorta[5] >= 'a' && arac_sigorta[5] <= 'z') || (arac_sigorta[5] >= 'A' && arac_sigorta[5] <= 'Z')) {
                                printf("Plakanizin harf kismi 3'ten uzun olmamalidir. Tekrar deneyin veya ana menuye donmek icin '0'a basiniz...\n");
                            } else if ((arac_sigorta[x - 1] >= 'a' && arac_sigorta[x - 1] <= 'z') || (arac_sigorta[x - 1] >= 'A' && arac_sigorta[x - 1] <= 'Z')) {
                                printf("Plakanizin sayi kismi minimum '10' olabilir. Tekrar deneyin veya ana menuye donmek icin '0'a basiniz...\n");
                            } else if ((arac_sigorta[x - 4] >= '0' && arac_sigorta[x - 4] <= '9') && strlen(arac_sigorta) > 6) {
                                printf("Plakanizin sayi kismi maksimum '9999' olabilir. Tekrar deneyin veya ana menuye donmek icin '0'a basiniz...\n");
                            } else if (strlen(arac_sigorta) > 9) {
                                printf("Arac plakasinin maksimum uzunlugu 9 karakterdir. Tekrar deneyin veya ana menuye donmek icin '0'a basiniz...\n");
                            } else {
                                printf("Aracinizin 1 yillik sigortasi icin odemeniz gereken tutar: %dTL 'dir\n1.Ode\n2.Ana Menuye Don\n", fatura);
                                while (1) {
                                    scanf("%d", &islem);
                                    if (islem == 1) {
                                        if (kullanicilar[i].bakiye < fatura) {
                                            printf("Bu islemi yapmak icin yeterli bakiyeniz bulunmamaktadir.\n");
                                            sleep(2);
                                            anasayfa(kullanicilar[i].id);
                                        } else {
                                            kullanicilar[i].bakiye -= fatura;  // Bakiye düþürme
                                            kullaniciYaz();  // Kullanýcý bilgilerini güncelle ve dosyaya yaz
                                            printf("Isleminiz gerceklestiriliyor...\n");
                                            sigortabilgileri = fopen("sigortabilgileri.txt", "a");
                                            fprintf(sigortabilgileri, "%s\n", arac_sigorta);
                                            fclose(sigortabilgileri);
                                            sleep(1);
                                            printf("Isleminiz basariyla gerceklestirilmistir.\n");
                                            sleep(1);
                                            anasayfa(kullanicilar[i].id);
                                        }
                                    } else if (islem == 2) {
                                        anasayfa(kullanicilar[i].id);
                                    } else {
                                        printf("Lutfen belirtilen araliklarda bir deger giriniz\n");
                                    }
                                }
                            }
                        }
                    }
                } else if (secim == 2) {
                    printf("Lutfen sigortalatmak istediginiz konutun bulundugu ilceyi giriniz. Ana Menuye donmek icin '0'a basiniz...\n");
                    scanf("%s", ev_ilce_sigorta);
                    if (ev_ilce_sigorta[0] == '0' && strlen(ev_ilce_sigorta) == 1) {
                        anasayfa(kullanicilar[i].id);
                    }
                    printf("Lutfen sigortalatmak istediginiz konutun bulundugu mahalleyi giriniz. Ana Menuye donmek icin '0'a basiniz...\n");
                    scanf("%s", ev_mahalle_sigorta);
                    strcat(ev_ilce_sigorta, ev_mahalle_sigorta);
                    for (j = 0; j < k; j++) {
                        if (strcmp(kayitlisigortalar[j], ev_ilce_sigorta) == 0) {
                            printf("Bu adrese ait zaten bir sigorta bulunmaktadir.\n");
                            sleep(2);
                            anasayfa(kullanicilar[i].id);
                        }
                    }
                    if (ev_mahalle_sigorta[0] == '0' && strlen(ev_mahalle_sigorta) == 1) {
                        anasayfa(kullanicilar[i].id);
                    } else {
                        printf("Konutunuzun 1 yillik sigortasi icin odemeniz gereken tutar: %dTL 'dir\n1.Ode\n2.Ana Menuye Don\n", fatura);
                        while (1) {
                            scanf("%d", &islem);
                            if (islem == 1) {
                                if (kullanicilar[i].bakiye < fatura) {
                                    printf("Bu islemi yapmak icin yeterli bakiyeniz bulunmamaktadir.\n");
                                    sleep(2);
                                    anasayfa(kullanicilar[i].id);
                                } else {
                                    kullanicilar[i].bakiye -= fatura;  // Bakiye düþürme
                                    kullaniciYaz();  // Kullanýcý bilgilerini güncelle ve dosyaya yaz
                                    printf("Isleminiz gerceklestiriliyor...\n");
                                    sigortabilgileri = fopen("sigortabilgileri.txt", "a");
                                    fprintf(sigortabilgileri, "%s\n", ev_ilce_sigorta);
                                    fclose(sigortabilgileri);
                                    sleep(1);
                                    printf("Isleminiz basariyla gerceklestirilmistir.\n");
                                    sleep(1);
                                    anasayfa(kullanicilar[i].id);
                                }
                            } else if (islem == 2) {
                                anasayfa(kullanicilar[i].id);
                            } else {
                                printf("Lutfen belirtilen araliklarda bir deger giriniz\n");
                            }
                        }
                    }
                } else if (secim == 3) {
                    printf("Lutfen sigortalatmak icin TCKN numaranizi giriniz. Ana Menuye donmek icin '0'a basiniz...\n");
                    while (1) {
                        a = 1;
                        scanf("%s", saglik_sigorta);
                        for (j = 0; j < k; j++) {
                            if (strcmp(kayitlisigortalar[j], saglik_sigorta) == 0) {
                                printf("Bu TCKN'ye ait zaten bir sigorta bulunmaktadir.\n");
                                sleep(2);
                                anasayfa(kullanicilar[i].id);
                            }
                        }
                        if (saglik_sigorta[0] == '0' && strlen(saglik_sigorta) == 1) {
                            anasayfa(kullanicilar[i].id);
                        } else if (strlen(saglik_sigorta) != 11) {
                            printf("TCKN'si 11 karakter uzunlugunda olmalidir. Tekrar deneyiniz veya ana menuye donmek icin '0'a basiniz\n");
                        } else if (!(saglik_sigorta[0] >= '0' && saglik_sigorta[0] <= '9') || !(saglik_sigorta[1] >= '0' && saglik_sigorta[1] <= '9') || !(saglik_sigorta[2] >= '0' && saglik_sigorta[2] <= '9') || !(saglik_sigorta[3] >= '0' && saglik_sigorta[3] <= '9') || !(saglik_sigorta[4] >= '0' && saglik_sigorta[4] <= '9') || !(saglik_sigorta[5] >= '0' && saglik_sigorta[5] <= '9') || !(saglik_sigorta[6] >= '0' && saglik_sigorta[6] <= '9') || !(saglik_sigorta[7] >= '0' && saglik_sigorta[7] <= '9') || !(saglik_sigorta[8] >= '0' && saglik_sigorta[8] <= '9') || !(saglik_sigorta[9] >= '0' && saglik_sigorta[9] <= '9') || !(saglik_sigorta[10] >= '0' && saglik_sigorta[10] <= '9')) {
                            printf("TCKN sadece rakamlardan olusmaktadir. Tekrar deneyiniz veya ana menuye donmek icin '0'a basiniz\n");
                        } else {
                            printf("1 yillik saglik sigortasi icin odemeniz gereken tutar: %dTL 'dir\n1.Ode\n2.Ana Menuye Don\n", fatura);
                            while (1) {
                                scanf("%d", &islem);
                                if (islem == 1) {
                                    if (kullanicilar[i].bakiye < fatura) {
                                        printf("Bu islemi yapmak icin yeterli bakiyeniz bulunmamaktadir.\n");
                                        sleep(2);
                                        anasayfa(kullanicilar[i].id);
                                    } else {
                                        kullanicilar[i].bakiye -= fatura;  // Bakiye düþürme
                                        kullaniciYaz();  // Kullanýcý bilgilerini güncelle ve dosyaya yaz
                                        printf("Isleminiz gerceklestiriliyor...\n");
                                        sigortabilgileri = fopen("sigortabilgileri.txt", "a");
                                        fprintf(sigortabilgileri, "%s\n", saglik_sigorta);
                                        fclose(sigortabilgileri);
                                        sleep(1);
                                        printf("Isleminiz basariyla gerceklestirilmistir.\n");
                                        sleep(1);
                                        anasayfa(kullanicilar[i].id);
                                    }
                                } else if (islem == 2) {
                                    anasayfa(kullanicilar[i].id);
                                } else {
                                    printf("Lutfen belirtilen araliklarda bir deger giriniz\n");
                                }
                            }
                        }
                    }
                } else if (secim == 4) {
                    anasayfa(kullanicilar[i].id);
                } else {
                    printf("Lutfen belirtilen araliklarda bir secim yapiniz\n");
                }
            }
        }
    }
}

void fatura_odeme(int id) {
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
            kullaniciOku();
            int secim, islem;
            char telNo[12];
            int fatura = 300;
            char detay[50];

            printf("\n1.Telekomunikasyon\n2.Elektrik/Su/Dogalgaz\n3.Ana Menu\n");
            while (1) {
                scanf("%d", &secim);
                if (secim == 1) {
                    printf("Kendi numaranizin faturasini mi yoksa baskasinin numarasinin faturasini mi odeyeceksiniz?\n");
                    printf("1.Kendi Numaram\n2.Baskasinin Numarasi\n");
                    scanf("%d", &islem);

                    if (islem == 1) {
                        sprintf(detay, "%d %s", id, kullanicilar[i].TelNo);
                        FILE *dosya = fopen("fatura.txt", "r");
                        int odenmis = 0;
                        char satir[50];

                        while (fgets(satir, sizeof(satir), dosya)) {
                            if (strstr(satir, detay) != NULL) {
                                odenmis = 1;
                                break;
                            }
                        }
                        fclose(dosya);

                        if (odenmis) {
                            printf("Odenecek bir faturaniz bulunmamaktadir.\n");
                            sleep(2);
                            anasayfa(kullanicilar[i].id);
                        } else {
                            printf("Odeyeceginiz tutar: 300TL. Onayliyor musunuz? (1.Evet 2.Hayir)\n");
                            scanf("%d", &islem);
                            if (islem == 1) {
                                if (kullanicilar[i].bakiye < fatura) {
                                    printf("Bu islemi yapmak icin yeterli bakiyeniz bulunmamaktadir.\n");
                                    sleep(2);
                                    anasayfa(kullanicilar[i].id);
                                } else {
                                    kullanicilar[i].bakiye -= fatura;
                                    kullaniciYaz();
                                    faturaKaydet(id, kullanicilar[i].TelNo);
                                    printf("Isleminiz basariyla gerceklestirilmistir.\n");
                                    sleep(2);
                                    anasayfa(kullanicilar[i].id);
                                }
                            } else {
                                anasayfa(kullanicilar[i].id);
                            }
                        }
                    } else if (islem == 2) {
    printf("Faturasini odeyeceginiz numarayi giriniz:\n");
    scanf("%s", telNo);

    // Girilen numaranýn dosyada olup olmadýðýný kontrol etmek için dosyayý aç
    FILE *dosya = fopen("fatura.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    // Dosyayý satýr satýr oku ve girilen numaranýn olup olmadýðýný kontrol et
    int odenmis = 0;
    char satir[50];
    while (fgets(satir, sizeof(satir), dosya)) {
        if (strstr(satir, telNo) != NULL) {
            odenmis = 1;
            break;
        }
    }
    fclose(dosya);

    // Girilen numaranýn dosyada olup olmadýðýný kontrol et
    if (odenmis) {
        printf("Odenecek bir faturaniz bulunmamaktadir.\n");
        sleep(2);
        anasayfa(kullanicilar[i].id);
    } else {
        printf("Odeyeceginiz tutar: 300TL. Onayliyor musunuz? (1.Evet 2.Hayir)\n");
        scanf("%d", &islem);
        if (islem == 1) {
            if (kullanicilar[i].bakiye < fatura) {
                printf("Bu islemi yapmak icin yeterli bakiyeniz bulunmamaktadir.\n");
                sleep(2);
                anasayfa(kullanicilar[i].id);
            } else {
                kullanicilar[i].bakiye -= fatura;
                kullaniciYaz();
                faturaKaydet(id, telNo);
                printf("Isleminiz basariyla gerceklestirilmistir.\n");
                sleep(2);
                anasayfa(kullanicilar[i].id);
            }
        } else {
            anasayfa(kullanicilar[i].id);
        }
    }
} else {
    printf("Lutfen gecerli bir secim yapiniz.\n");
}
} else if (secim == 2) {
    printf("Faturasini odeyeceginiz faturayi seciniz:\n");
    printf("1. Elektrik\n");
    printf("2. Su\n");
    printf("3. Dogalgaz\n");
    scanf("%d", &islem);

    char fatura_turu[20]; // Fatura türü
    if (islem == 1)
        strcpy(fatura_turu, "Elektrik");
    else if (islem == 2)
        strcpy(fatura_turu, "Su");
    else if (islem == 3)
        strcpy(fatura_turu, "Doðalgaz");
    else {
        printf("Lutfen gecerli bir secim yapiniz.\n");
        continue;
    }

    if (kullanicilar[i].odeme_durumu >= 3) {
        printf("Butun faturalarinizi odediniz.\n");
        sleep(2);
        anasayfa(kullanicilar[i].id);
    } else if (kullanicilar[i].odeme_durumu >= islem) {
        printf("%s faturanizi zaten odediniz.\n", fatura_turu);
        sleep(2);
        anasayfa(kullanicilar[i].id);
    } else {
        printf("Odeyeceginiz tutar: 300TL. Onayliyor musunuz? (1.Evet 2.Hayir)\n");
        scanf("%d", &islem);
        if (islem == 1) {
            if (kullanicilar[i].bakiye < fatura) {
                printf("Bu islemi yapmak icin yeterli bakiyeniz bulunmamaktadir.\n");
                sleep(2);
                anasayfa(kullanicilar[i].id);
            } else {
                kullanicilar[i].bakiye -= fatura;
                kullanicilar[i].odeme_durumu += 1;
                kullaniciYaz();
                faturaKaydet(id, fatura_turu);
                printf("%s faturaniz basariyla odendi.\n", fatura_turu);
                sleep(2);
                anasayfa(kullanicilar[i].id);
            }
        } else {
            anasayfa(kullanicilar[i].id);
        }
    }
}
 else if (secim == 3) {
                    anasayfa(kullanicilar[i].id);
                } else {
                    printf("Lutfen gecerli bir secim yapiniz.\n");
                }
            }
        }
    }
}
void kayit_sil(int silinecek_id) {
    int found = 0;
    
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == silinecek_id) {
            kullanicilar[i].id = 0; // Kullanýcýyý silmek için id'yi sýfýrla
            found = 1;
            break;
        }
    }

    if (found) {
        silineneler(); // Güncellenmiþ kullanýcý listesini dosyaya yaz
        printf("Kullanýcý baþarýyla silindi.\n");
    } else {
        printf("Kullanýcý bulunamadý.\n");
    }
    return;
}

void verileriOku() {
    FILE *dosya = fopen("kullanicilar.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        return;
    }

    printf("Kullanýcýlar:\n");
    printf("| ID | Kullanýcý Adý       | Soyisim        | TC           | Telefon       | Þifre          | Bakiye    |\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    while (!feof(dosya)) {
        int id;
        char kullaniciAdi[50];
        char kullaniciSoyisim[50];
        char tc[11];
        char TelNo[15];
        char sifre[50];
        float bakiye;
        if (fscanf(dosya, "%d %s %s %s %s %s %f\n", &id, kullaniciAdi, kullaniciSoyisim, tc, TelNo, sifre, &bakiye) == 7) {
            printf("| %-2d | %-18s | %-14s | %-11s | %-12s | %-14s | %-8.1f |\n", id, kullaniciAdi, kullaniciSoyisim, tc, TelNo, sifre, bakiye);
        }
    }
    printf("-------------------------------------------------------------------------------------------------------\n");

    fclose(dosya);
}

void bilgiDegistir(int kullaniciId) {

    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == kullaniciId) {
            printf("Kullanýcý Adý (%s): ", kullanicilar[i].kullaniciAdi);
            scanf("%s", kullanicilar[i].kullaniciAdi);
            printf("Soyisim (%s): ", kullanicilar[i].kullaniciSoyisim);
            scanf("%s", kullanicilar[i].kullaniciSoyisim);
            printf("TC (%s): ", kullanicilar[i].tc);
            scanf("%s", kullanicilar[i].tc);
            printf("Telefon (%s): ", kullanicilar[i].TelNo);
            scanf("%s", kullanicilar[i].TelNo);
            printf("Þifre (%s): ", kullanicilar[i].sifre);
            scanf("%s", kullanicilar[i].sifre);
            printf("Bakiye (%.1f): ", kullanicilar[i].bakiye);
            scanf("%f", &kullanicilar[i].bakiye);
            kullaniciYaz();
            printf("Kullanýcý bilgileri baþarýyla güncellendi.\n");
            return;
        }
    }
    printf("Kullanýcý bulunamadý.\n");
}
 void admin() {
 	int islem;
       printf("Yapýlacak iþlemi seçiniz:\n");
            printf("1. Kullanýcýlarý listele\n");
            printf("2. Kullanýcý sil\n");
            printf("3. Bilgi Düzenleme\n");
            printf("4. Çýkýþ\n");
            printf("Seçim: ");
         
        scanf("%d", &islem);

        switch (islem) {
            case 1:
              verileriOku();
                break;
            case 2:
            	 verileriOku();
               int silinecek_id;
            printf("Silinecek kullanýcý ID'si: ");
            scanf("%d", &silinecek_id);
            kayit_sil(silinecek_id);
                break;
            
            case 3:
            verileriOku();
               int kullaniciId;
            printf("Bilgilerini deðiþtirmek istediðiniz kullanýcý ID'si: ");
            scanf("%d", &kullaniciId);
            bilgiDegistir(kullaniciId);            
                break;
            case 4:
            	DolarGuncelle();
                // Çýkýþ
                return;
            default:
                break;
        }
    }
void silineneler() {
    FILE *dosya = fopen("kullanicilar.txt", "w");
    if (dosya == NULL) {
        printf("Dosya açýlamadý.\n");
        return;
    }

    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id != 0) { // Silinmiþ kullanýcýlarý yazma
            fprintf(dosya, "%d %s %s %s %s %s %.1f\n",
                    kullanicilar[i].id,
                    kullanicilar[i].kullaniciAdi,
                    kullanicilar[i].kullaniciSoyisim,
                    kullanicilar[i].tc,
                    kullanicilar[i].TelNo,
                    kullanicilar[i].sifre,
                    kullanicilar[i].bakiye);
        }
    }

    fclose(dosya);
}


void krediCekme(int id) {
    double miktar;
    printf("Çekilecek kredi miktarý: ");
    scanf("%lf", &miktar);
    double faizli_miktar = miktar * 1.2; // %20 faiz
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
            kullanicilar[i].bakiye += miktar;
            kullanicilar[i].borc -= faizli_miktar;
            kullaniciYaz();
            printf("Kredi çekme iþlemi baþarýlý.\n");
            printf("Yeni Bakiyeniz: %.1f TL\n", kullanicilar[i].bakiye);
            printf("Toplam Borcunuz: %.1f TL\n", kullanicilar[i].borc);
            break;
        }
    }
}

void borcOdeme(int id) {
    double miktar;
    printf("Ödenecek borç miktarý: ");
    scanf("%lf", &miktar);
    for (int i = 0; i < 100; i++) {
        if (kullanicilar[i].id == id) {
            if (kullanicilar[i].bakiye >= miktar) {
                kullanicilar[i].bakiye -= miktar;
                kullanicilar[i].borc += miktar;
                kullaniciYaz();
                printf("Borç ödeme iþlemi baþarýlý.\n");
                printf("Yeni Bakiyeniz: %.1f TL\n", kullanicilar[i].bakiye);
                printf("Kalan Borcunuz: %.1f TL\n", kullanicilar[i].borc);
                break;
            } else {
                printf("Yetersiz bakiye veya borç miktarý.\n");
                break;
            }
        }
    }
}

