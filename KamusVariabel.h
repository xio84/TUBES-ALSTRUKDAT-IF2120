/* Ini adalah header untuk menyimpan semua variabel dalam permainan */

#ifndef kamusvar_H
#define kamusvar_H

#include "boolean.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Definisi variabel untuk Engi's Kitchen Expansion*/

/*Bentukan si player*/
typedef struct{
	int life;
	int money;
	POINT position;
} PLAYER;

#define Life(P) (P).Life
#define Money(P) (P).Money
#define Position(P) (P).position

/* Untuk ADT JAM -> Waktu game  */
typedef struct {
    int SS; /* buat simpan waktu permainan kalau jadi di save */
} JAM;
/*Definisi pemanggilan Time */
#define Time(J) (J).SS


/*Untuk ADT POINT */
typedef struct {
	float X; /* absis */
	float Y; /* ordinat*/
	int ID /*penunjuk lokasi di mana player berada, misal Room 1, Room 2, Dapur*/
} POINT;
/*Definisi pemanggilan Point */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define Lokasi(P) (P).lokasi


/*Untuk ADT ARRAY -> <makanan,nomormeja,kesabaran>*/
typedef struct {
    int nomormeja;
    int kesabaran;
    char makanan[30];
} TabInt
/*Definisi pemanggilan Point */
#define Nomormeja(A) (A).nomormeja
#define Kesabaran(A) (A).kesabaran
#define Makanan(A) (A).makanan  /*coba deh bisa di string atau engga */

/*Untuk ADT Matriks*/
typedef int indeks; /* indeks baris, kolom */
typedef int ElType;
typedef struct {
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

/*Untuk ADT Mesin Karakter dan Karakter*/
/* Definisi elemen dan address */

/*Untuk ADT Queue*/
typedef struct {
                 int wktantri;/* waktu antrean si pelanggan */
				 int jumlahorang; /*antrian per grup, kan antriannya ga harus sendiri (per kelomppok)*/
               } infotype;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotype T [30];  /*panjang antrian maksimal*/
                 address HEAD;  /* alamat penghapusan */
                 address TAIL;  /* alamat penambahan */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah Queue, maka akses elemen : */
#define WktAntri(e)     (e).wktantri
#define Jumlahorang(e) (e).jumlahorang
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]


/*Definisi ADT Modstack*/
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	infotype T[5]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]



#endif
