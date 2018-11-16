/* Ini adalah header untuk menyimpan semua variabel dalam permainan */

#ifndef kamusvar_H
#define kamusvar_H

#include "boolean.h"
#include <string.h>
#include <stdlib.h>
/* Definisi variabel untuk Engi's Kitchen Expansion*/

/*Bentukan si player*/
typedef struct{
	int life;
	int money;
    char name[20];
} PLAYER;

#define Life(P) (P).life
#define Money(P) (P).money
#define Nama(P) (P).name

/* Untuk ADT JAM -> Waktu game  */
typedef struct {
    int SS; /* buat simpan waktu permainan kalau jadi di save */
} JAM;
/*Definisi pemanggilan Time */
#define Time(J) (J).SS


/*Untuk ADT POINT */
typedef struct {
	int X; /* absis */
	int Y; /* ordinat*/
	int ID; /*penunjuk lokasi di mana player berada, misal Room 1, Room 2, Dapur*/
} POINT;
/*Definisi pemanggilan Point */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define Lokasi(P) (P).lokasi


/*Untuk ADT ARRAY -> <makanan,nomormeja,kesabaran>*/
typedef int IdxType;  /* type indeks */
typedef struct{
  int nomormeja;
  int kesabaran;
  char makanan;
} infotypeArr;

typedef struct {
    infotypeArr TI[30];
    int Neff;
} TabInt;
/*Definisi pemanggilan Point */
#define Nomormeja(T,i) (T).TI[(i)].nomormeja
#define Kesabaran(T,i) (T).TI[(i)].kesabaran
#define Makanan(T,i) (T).TI[(i)].makanan  /*coba deh bisa di string atau engga */

/*Untuk ADT Matriks*/
typedef int indeks; /* indeks baris, kolom */
typedef int ElType;
typedef struct {
	ElType Mem[20+1][20+1];
  int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

/*Untuk ADT Mesin Karakter dan Karakter*/
/* Definisi elemen dan address */

/*Untuk ADT Queue*/
#define MaxElQ 30

typedef struct {
        int wktantri;/* waktu antrean si pelanggan */
				int jumlahorang; /*antrian per grup, kan antriannya ga harus sendiri (per kelomppok)*/
                } infotypeQ;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotypeQ T [MaxElQ];  /*panjang antrian maksimal*/
                 address HEAD;  /* alamat penghapusan */
                 address TAIL;  /* alamat penambahan */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah Queue, maka akses elemen : */
#define WktAntriHead(Q)     (Q).T[(Q).HEAD].wktantri
#define JumlahOrangHead(e) (Q).T[(Q).HEAD].jumlahorang
#define WktAntriTail(Q)     (Q).T[(Q).TAIL].wktantri
#define JumlahOrangTail(e) (Q).T[(Q).TAIL].jumlahorang
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL


typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	infotype T[5]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]


#endif
