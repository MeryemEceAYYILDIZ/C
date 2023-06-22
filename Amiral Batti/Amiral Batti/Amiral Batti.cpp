#include <iostream>
#include <string>
using namespace std;

void matris (char matris[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matris[i][j] = 'O';
        }
    }
}

void matrisyazdir(char matris[10][10]){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matris[i][j] << " ";
        }
        cout << "\n";
    }
}

int bosmu(char matris[10][10], int satir, int sutun, int yon, int kapladıgıalan) {
    int sayac = 0;
    if (yon == 1) {
        for (int i = satir - 1; i < satir; i++) {
            for (int j = sutun - 1; j < sutun + kapladıgıalan-1; j++) {
                if (matris[i][j] != 'O') {
                    sayac++;
                }
            }
        }
    }
    else if (yon == 2) {
        for (int i = satir - 1; i < satir + kapladıgıalan - 1; i++) {
            for (int j = sutun - 1; j < sutun; j++) {
                if (matris[i][j] != 'O') {
                    sayac++;
                }
            }
        }
    }
    return sayac;
}

void yatayyerlestirme(char matris[10][10], char harf, int satir, int sutun, int kapladıgıalan) {
    for (int i = satir - 1; i < satir; i++) {
        for (int j = sutun - 1; j < sutun + kapladıgıalan - 1; j++) {
            matris[i][j] = harf;
        }
    }
}

void dikeyyerlestirme(char matris[10][10], char harf, int satir, int sutun, int kapladıgıalan) {
    for (int i = satir - 1; i < satir + kapladıgıalan - 1; i++) {
        for (int j = sutun - 1; j < sutun; j++) {
            matris[i][j] = harf;
        }
    }
}

int gemiyerlestirme(char matris[10][10], int kapladıgıalan, char harf) {
    int satir, sutun, yon;

        cout << "Yatay mi dikey mi yerlestirmek istediğinizi seciniz:\n1: Yatay       2: Dikey\n";
        cin >> yon;
        cout << "Lutfen geminin koordinatlarini giriniz:\n";
        cout << "satir numarasi:\n";
        cin >> satir;
        cout << "sutun numarasi:\n";
        cin >> sutun;
    if (bosmu(matris, satir, sutun, yon, kapladıgıalan) == 0) {
        if (yon==1) {
            yatayyerlestirme(matris, harf, satir, sutun, kapladıgıalan);
        }else if (yon == 2) {
            dikeyyerlestirme(matris, harf, satir, sutun, kapladıgıalan);
        }else {
            cout << "Hatali giris yaptiniz";
        }
    }
    else {
        cout << "Sectiginiz aralikta baska bir gemi var!";
        return 0;
    }
}

void gemisecmeveyerlestirme(char matris[10][10]) {
    char harf;
    int Amiral = 1, Kruvazor = 2, Muhrip = 3, Denizalti = 4, gemi, kapladıgıalan;
    do{
        cout << "Yerlestirmek istediginiz gemiyi seciniz:\n 1:Amiral\n 2:Kruvazor\n 3:Muhrip\n 4:Denizalti\n";
        cin >> gemi;
        switch (gemi){
            case 1:
                if (Amiral == 0) {
                    cout << "Daha fazla Amiral gemisi yerlestiremezsiniz\n";
                    break;
                }
                else if (gemiyerlestirme == 0) {
                    break;
                } else {
                    harf = 'A';
                    kapladıgıalan = 4;
                    gemiyerlestirme(matris, kapladıgıalan, harf);
                    Amiral--;
                }
                break;
            case 2:
                if (Kruvazor == 0) {
                    cout << "Daha fazla Kruvazor gemisi yerlestiremezsiniz\n";
                    break;
                }
                else if (gemiyerlestirme == 0) {
                    break;
                } else {
                    harf = 'K';
                    kapladıgıalan = 3;
                    gemiyerlestirme(matris, kapladıgıalan, harf);
                    Kruvazor--;
                }
                break;
            case 3:
                if (Muhrip == 0) {
                    cout << "Daha fazla Muhrip gemisi yerlestiremezsiniz\n";
                    break;
                } 
                else if (gemiyerlestirme == 0) {
                    break;
                } else {
                    harf = 'M';
                    kapladıgıalan = 2;
                    gemiyerlestirme(matris, kapladıgıalan, harf);
                    Muhrip--;
                }
                break;
            case 4:
                if (Denizalti == 0) {
                    cout << "Daha fazla Denizalti yerlestiremezsiniz\n";
                    break;
                }
                else if (gemiyerlestirme == 0) {
                    break;
                } else{
                    harf = 'D';
                    kapladıgıalan = 1;
                    gemiyerlestirme(matris, kapladıgıalan, harf);
                    Denizalti--;
                }
                break;
            default:
                cout << "Hatali giris yaptiniz\n";
                break;
        }
    } while (Amiral != 0 || Kruvazor != 0 || Muhrip != 0 || Denizalti != 0);
}

void kontrol1(char matris[10][10], char atismatrisi[10][10], int i, int j) {
    switch (matris[i-1][j-1]){
        case 'O':
            cout << "Isabetsiz atıs";
            break;
        case 'X':
            cout << "Isabetsiz atis";
            break;
        case 'A':
            cout << "Amiral yara aldi!";
            break;
        case 'K':
            cout << "Kruvazor yara aldi!";
            break;
        case 'M':
            cout << "Muhrip yara aldi!";
            break;
        case 'D':
            cout << "Denizalti yara aldi!";
            break;
    }
    matris[i-1][j-1] = 'X';
    atismatrisi[i - 1][j - 1] = 'X';
}

int kontrol2(char matris[10][10]) {
    int sayac = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matris[i][j] != 'X' && matris[i][j] != 'O') {
                sayac++;
            }
        }
    }
    if (sayac == 0) {
        cout << "Tebrikler oyunu kazandiniz!";
        return 1;
    } else {
        return 0;
    }
}

void tahminalma(char matris[10][10], char atismatrisi[10][10]) {
    for (int i = 0; i < 3; i++) {
        int satir, sutun;
        cout << i << ". tahminizi giriniz:\n";
        cout << "satir numarasi:\n";
        cin >> satir;
        cout << "sutun numarasi:\n";
        cin >> sutun;
        kontrol1(matris, atismatrisi, satir, sutun);
        matrisyazdir(atismatrisi);
        if (kontrol2(matris) == 1) {
            break;
        }
    }
}

int main()
{
    string oyuncu1, oyuncu2;
    cout << "Amiral Batti oyununa hos geldiniz. bu oyun icin iki oyuncu gerekmektedir.\n";
    cout << "Lutfen birinci oyuncunun ismini giriniz:\n";
    getline(cin, oyuncu1);
    cout << "lutfen ikinci oyuncunun ismini giriniz:\n";
    getline(cin, oyuncu2);
    cout << "AMIRAL BATTI NASIL OYNANIR?\n";
    cout << "Oyun 10x10'luk bir matriste oynanir. Her bir satir ve sutun 1'den 10'a kadar sayilarla ifade edilir.\n";
    cout << "Oyuncularin farkli buyukluklerde toplam 10 adet gemisi vardir.\n";
    cout << "kareler yan yana olacak sekilde dikey veya yatay olarak yerlestirilmelidir.\n";
    cout << " 1 adet amiral gemisi; 4 kare alan kaplar.\n 2 adet kruvazor gemisi; 3'er kare alan kaplar.\n 3 adet muhrip gemisi; 2'ser kare alan kaplar.\n 4 adet denizalti 1'er kare yer kaplar.\n";
    cout << "Gemileri yerlestirirken yatay mi yoksa dikey mi yerlestirmek istedigini secmeniz gerekmektedir. Bundan sonra gireceginiz satir ve sutun sayisina gore gemileriniz kapladigi alan kadar saga dogru ya da asagiya dogru yerlestirilecektir.";
    cout << "Amiral batti oyununda amac; rakip tarafin gemilerini, rakibinden once batirmaktir.\n";
    cout << "Her oyuncu sirayla 3 adet tahmin yapar. Ornegin, 1 1, 5 3, 9 6 diyebilir.\n";
    cout << "Eger soyledigi rakamlara denk gelen karede rakip oyuncunun bir gemisi varsa gemiyi batirmis ya da yaralamis ve puan kazanmis olur.\n";
    cout << "Her gemi, boyutu kadar isabetli atisla batar. Yani amiral gemisinin batirilmasi icin 4 isabetli atis gerekirken, denizalti tek atista batmis olur.\n";
    cout << "Rakibinden once karsi tarafin butun gemilerini batiran oyuncu, oyunu kazanmis olur.\n";
    char matris1[10][10];
    matris(matris1);
    char atismatrisi1[10][10];
    matris(atismatrisi1);
    char matris2[10][10];
    matris(matris2);
    char atismatrisi2[10][10];
    matris(atismatrisi2);
    cout << oyuncu1 << " ";
    gemisecmeveyerlestirme(matris1);
    cout << oyuncu2 << " ";
    gemisecmeveyerlestirme(matris2);
    int x = kontrol2(matris2), y = kontrol2(matris1);
    do {
        cout << oyuncu1 << " ";
        tahminalma(matris2, atismatrisi2);
        cout << oyuncu2 << " ";
        tahminalma(matris1, atismatrisi1);
    } while (x==0 && y== 0);
}
