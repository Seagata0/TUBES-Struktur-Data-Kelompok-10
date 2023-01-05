#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

#define last(A) (A).last
#define first(A) (A).first
#define nextrelation(p) (p)->nextrelation

struct film{
    string id;
    string judul;
    string sutradara;
    string genre;
};

struct actor{
    string name;
    char jk;
    string nation;
    string tl;
};

typedef struct film infotypefilm;
typedef struct actor infotypeactor;
typedef struct elm_film *adr_film;
typedef struct elm_actor *adr_actor;
typedef struct elm_relation *adr_relation;

struct elm_relation{
    adr_film nextfilm;
    adr_relation next;
};

struct elm_film{
    infotypefilm info;
    adr_film next;
    adr_film prev;
};

struct elm_actor{
    infotypeactor info;
    adr_actor next;
    adr_relation nextrelation;
};


struct list_relation{   //SLL
    adr_relation first;
};

struct list_film{    //DCLL
    adr_film first;
    adr_film last;
};

struct list_actor{   //SLL
    adr_actor first;
};

void createListActor(list_actor &A);
void createListFilm(list_film &A);
void createListRelasi(list_relation &A);
adr_actor createElementActor(actor x);
adr_film createElementFilm(film x);
adr_relation createElementRelation();
void showListActor(list_actor A);
adr_actor searchActor(list_actor A,string name);
adr_film searchFilm(list_film A,string judul);
void insertLastActor(list_actor &A,adr_actor p);
void insertFirstFilm(list_film &A, adr_film p);
void insertLastFilm(list_film &A, adr_film p);
void insertAfterFilm(list_film &A, adr_film prec, adr_film p);

void connect(list_actor &a, list_film &f, string nama, string judul);
void printActorDanFilm(list_actor a);
void printFilmDariActor(list_actor a, string nama);
void deleteFilm(list_film &f, string judul);
adr_relation searchRelation(adr_actor q, string judul);
void deleteRelation(adr_actor q, string judul);
void disconnectdel(list_actor &a,list_film &f,string nama, string judul);
void disconnect(list_actor &a, string nama, string judul);
void jumlahFilm(list_actor a,string nama);
void delActorFilm(list_actor &a, list_film &f, adr_actor p);
int selectMenu();

#endif // TUBES_H_INCLUDED
