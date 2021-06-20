#include <stdio.h>

typedef struct{
  
  int n; //n menyatakan jumlah barang elektronik//
  float p; //w menyatakan daya dari barang elektronik dalam satuan Watt//
  float t;//t menunjukkan waktu pemakaian dalam satuan jam//
  float w; //menunjukkan konsumsi listrik dalam satuan kwh//
} barang;

char namaBarang[100][100];
int i;
void kons_list(barang *ptrBarang, int jumlahBarang); //fungsi untuk mengkalkulasikan masing-masing kWh dari penggunaan barang elektronik//
void printOutput(barang *ptrBarang, int jumlahBarang); //fungsi untuk mengkalkulasikan total kwh dari seluruh barang elektronik//
float w_tot = 0;//variabel yang dipakai untuk nyimpan total energi

int main() 
{

  int m = 0;
  int gol;
  float fee = 0;
  float fee_tot;
  barang kumpulanBarang[100];

  printf("================SELAMAT DATANG PADA================\n");
  printf("===============SMART HOME CALCULATOR===============\n");
  printf("=============Alat Pengkalkulasi Biaya==============\n");
  printf("==========Konsumsi Listrik Rumah Tangga============\n\n");
  printf("\nProgram ini menjalankan sebuah fungsi untuk mengkalkulasi seberapa banyak biaya listrik dari total kWh berdasarkan data barang elektronik yang digunakan\n");
  printf("\nProgram ini akan meminta masukan dari pengguna berupa: \n - Nama barang elektronik \n - nilai konsumsi daya (watt) \n - jumlah barang (satuan) \n - lama waktu penggunaan (jam)\n");
  printf("\nCara kerja dari program ini adalah sebagai berikut:\n 1. Program akan meminta masukan dari pengguna; \n 2. Program akan mengkalkulasikan dan menampilkan kWh masing-masing barang elektronik dan menjumlahkan nilainya; \n 3. Program terakhir akan mengkalkulasikan dan menampilkan biaya listrik dari total kWh pada kalkulasi sebelumnya.\n\n");
  printf("\nCatatan:\n- Ketik angka 0 untuk menghentikan program dari mengambil masukan dari pengguna\n- Untuk input nama barang jika terdiri dari dua atau lebih kata menggunakan underscore sebagai spasi\n- untuk input nilai konsumsi daya, jumlah barang, lama waktu penggunaan menggunakan angka\n\n");
  printf("\n================================================================\n \n");
  
  while(1){
    
    printf("Masukkan nama barang elektronik: "); 
    scanf("%s", namaBarang[m]);
    if(namaBarang[m][0] == '0'){//untuk menghentikan program dari mengambil masukan dari pengguna// 
      printf("\n");
      break;
    }


    printf("Masukkan nilai konsumsi daya barang dalam watt: ");
    scanf("%f", &kumpulanBarang[m].p);

    printf("Masukkan jumlah barang: "); //barang dalam satuan//
    scanf("%d", &kumpulanBarang[m].n);
    printf("Masukkan lama waktu penggunaan barang dalam jam: "); //satuan berupa jam//
    scanf("%f", &kumpulanBarang[m].t);
    printf("\n");
    m += 1;
  }

  printf("\n================================================================\n\n");
  
  kons_list(kumpulanBarang, m);
  
  printOutput(kumpulanBarang, m);

  printf("================================================================ \n\n");

  printf("1.Golongan R-1/ Tegangan Rendah (TR) daya 900 VA, Rp 1.352 per kWh\n2.Golongan R-1/ TR daya 1.300 VA, Rp 1.444,70 per kWh \n3.Golongan R-1/ TR daya 2.200 VA, Rp 1.444,70 per kWh \n4.Golongan R-2/ TR daya 3.500-5.500 VA, Rp 1.444,70 per kWh \n5.Golongan R-3/ TR daya 6.600 VA ke atas, Rp 1.444,70 per kWh \n6.Golongan B-2/ TR daya 6.600 VA-200 kVA, Rp 1.444,70 per kWh \n");

  printf("\nMasukan angka untuk memilih golongan tarif sesuai daftar diatas untuk menampilkan biaya: ");
  scanf("%d", &gol);
  switch(gol){
    case 1:
      fee = 1352; 
      break;
    case 2:
      fee = 1444.70; 
    case 3:
      fee = 1444.70;
    case 4:
      fee = 1444.70;
    case 5:
      fee = 1444.70;
    case 6:
      fee = 1444.70;
      break;
    default:
      printf("Angka diluar 1-6!\n");
  }
  fee_tot = fee*w_tot;
  printf("\nBiaya total adalah Rp%.3f \n", fee_tot);
}

void kons_list(barang *ptrBarang, int jumlahBarang){
  for(i = 0; i<jumlahBarang; i++){
    ptrBarang[i].w = ptrBarang[i].p * (ptrBarang[i].t) * (ptrBarang[i].n) * 0.001;
    w_tot += ptrBarang[i].w;
  }
}

void printOutput(barang *ptrBarang, int jumlahBarang){
  for(i = 0; i<jumlahBarang; i++){
    printf("Energi yang digunakan %s adalah %.3f kWH \n", namaBarang[i],  ptrBarang[i].w);
  }
  printf("\nTotal energi yang digunakan adalah %.3f kWH \n\n", w_tot);
}


