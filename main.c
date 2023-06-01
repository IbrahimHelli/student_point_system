#include <stdio.h>
#include <stdlib.h>

enum Sube {a1 = 1,b1 ,c1 ,d1 } ; enum  Cinsiyet { Erkek = 1,kadin} ;


struct ogrenci {
    size_t TCKN;
    enum Sube sube;
    char  Adi[10];
    char  Soyadi[10];
    enum  Cinsiyet cinsiyet;
    float DersOrtalamasi;

};

void BilgiYaz (struct ogrenci );
struct ogrenci OkuSirala(int );

int main() {
    struct ogrenci DiziOgrenci;
    struct ogrenci **ptrogr ;
    ptrogr = (struct ogrenci **) malloc(4 * sizeof(struct ogrenci *));
    for (int i = 0; i < 4; ++i) {
        *(ptrogr+i) = (struct ogrenci *) malloc(10 * sizeof(struct ogrenci));

    }

    for (int i = 0; i <1; ++i) {
        printf("lutfen TCKN, Sube, Adi, Soyadi, Cinsiyet( Erkek=1,Kadin=2), Ders Ortalamasi sekleide enter basarak giriniz  :");
        scanf("%ld %d %s %s %d %f", &DiziOgrenci.TCKN, &DiziOgrenci.sube,&DiziOgrenci.Adi,
              &DiziOgrenci.Soyadi, &DiziOgrenci.cinsiyet, &DiziOgrenci.DersOrtalamasi);

        BilgiYaz(DiziOgrenci);

    }
    struct ogrenci eyp;
    for (int i = 0; i < 4; ++i) {
       eyp= OkuSirala(i+1)  ;
        printf("\n%d. subesindeki %s %s  en yuksek puani : %.2f",i+1,eyp.Adi,eyp.Soyadi,eyp.DersOrtalamasi);

    }


    return 0;
}

void BilgiYaz (struct ogrenci ogr){

    FILE *dg = fopen("ogrenci.db","ab");
    if (dg == NULL){
        printf("dosya olusturamadi");
        exit(1);

    }
    fprintf(dg,"%ld %d %s %s %d %f",ogr.TCKN,ogr.sube,ogr.Adi,ogr.Soyadi,ogr.cinsiyet,ogr.DersOrtalamasi);
    fclose(dg);

}
struct ogrenci OkuSirala(int sube){

    FILE *dg = fopen("ogrenci.db","rb");
    if (dg == NULL){
        printf("dosya okunamadi");
        exit(1);
    }
    struct ogrenci eyp ;
    struct ogrenci ogr;
    eyp.DersOrtalamasi=-1;
    while (!feof(dg)){
        fscanf(dg,"%ld %d %s %s %d %f",&ogr.TCKN,&ogr.sube,&ogr.Adi,&ogr.Soyadi,&ogr.cinsiyet,&ogr.DersOrtalamasi);
        if(ogr.sube == sube){
            if(ogr.DersOrtalamasi > eyp.DersOrtalamasi){
                eyp=ogr;

            }
        }
    }
    fclose(dg);
    return eyp;
}
