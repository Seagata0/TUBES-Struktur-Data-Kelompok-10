#include "tubes.h"

//create list film, actor dan relasi
void createListActor(list_actor &A){
    first(A)= NULL;
}

void createListFilm(list_film &A){
    first(A)=NULL;
}

void createListRelasi(list_relation &A){
    first(A)=NULL;
}


//create element actor, film, relasi
adr_actor createElementActor(actor x){
    adr_actor p = new elm_actor;
    p->info = x;
    p->next = NULL;
    p->nextrelation = NULL;
    return p;
}

adr_film createElementFilm(film x){
    adr_film p=new elm_film;
    p->info=x;
    p->next=NULL;
    p->prev=NULL;
    return p;
}

adr_relation createElementRelation(){
    adr_relation p= new elm_relation;
    p->nextfilm = NULL;
    p->next = NULL;
    return p;
}


//insert actor SLL nomor 1
void insertLastActor(list_actor &A, adr_actor p){
    if(first(A)==NULL){
        first(A)=p;
    }else{
        adr_actor q=first(A);
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }
}


//show actor (nomor 2)
void showListActor(list_actor A){
    adr_actor p=first(A);
    while(p!=NULL){
        cout<<"Name : "<<p->info.name<<endl;
        cout<<"Nationality : "<<p->info.nation<<endl;
        cout<<"Tanggal Lahir : "<<p->info.tl<<endl;
        cout<<endl;
        p=p->next;
    }
}


//Hapus data aktor beserta film (nomor 3)
void delActorFilm(list_actor &a, list_film &f, adr_actor q){
    if(q==NULL){
        cout<<"Actor tidak ditemukan"<<endl;
    }else{
        adr_relation x = q->nextrelation;
        string judul;
        while(x!=NULL){
            judul = x->nextfilm->info.judul;
            deleteFilm(f,judul);
            adr_actor y = first(a);
            while(y!=NULL){
                disconnect(a,y->info.name,judul);
                y = y->next;
            }
            x = q->nextrelation;
        }
        q->nextrelation = NULL;
        if(q==first(a)){
            first(a) = q->next;
            q->next = NULL;
        }else{
            adr_actor y = first(a);
            while(y->next!=q){
                y = y->next;
            }
            if(q->next==NULL){
                y->next = NULL;
            }else{
                y->next = q->next;
                q->next = NULL;
            }
        }
    }
}


//search actor(nomor 4)
adr_actor searchActor(list_actor A,string name){
    adr_actor p=first(A);
    while(p!=NULL && p->info.name!=name){
        p=p->next;
    }
    return p;

}


//search film (nomor 5)
adr_film searchFilm(list_film A,string judul){
    adr_film p=first(A);
    while(p->next!=p && p->info.judul!=judul){
        p=p->next;
    }
    return p;
}


//insert film (nomor 6)
void insertFirstFilm(list_film &A, adr_film p){
    if(first(A)==NULL){
        first(A)=p;
        last(A)=p;
        p->next=p;
        p->prev=p;
    }else{
        insertAfterFilm(A,last(A),p);
        first(A)=p;
    }
}

void insertLastFilm(list_film &A, adr_film p){
    if(first(A)==NULL){
        insertFirstFilm(A,p);
    }else{
        insertAfterFilm(A,last(A),p);
        last(A)=p;
    }
}

void insertAfterFilm(list_film &A, adr_film prec, adr_film p){
    p->next=prec->next;
    p->prev=prec;
    prec->next->prev=p;
    prec->next=p;
}


//connect actor to film (nomor 7)
void connect(list_actor &a, list_film &f, string nama, string judul){
    adr_relation r = createElementRelation();
    adr_actor s = searchActor(a,nama);
    checkActor(a,s);
    adr_film t = searchFilm(f,judul);
    checkFilm(f,t);
    if (s->nextrelation == NULL){
        s->nextrelation = r;
        r->nextfilm = t;
        cout<<"Berhasil Menghubungkan Actor "<<nama<<" Dengan Film "<<judul;
    }else{
        adr_relation q = s->nextrelation;
        while(q->next!=NULL){
            q = q->next;
        }
        q->next = r;
        r->nextfilm = t;
        cout<<"Berhasil Menghubungkan Actor "<<nama<<" Dengan Film "<<judul;
    }
}

//print artist + film (nomor 8)
void printActorDanFilm(list_actor a){
    adr_actor p = first(a);
    adr_relation q;
    while (p!=NULL){
        cout<<"=====================ACTOR====================="<<endl;
        cout<<"Nama : "<<p->info.name<<endl;
        cout<<"Kebangsaan : "<<p->info.nation<<endl;
        cout<<"Tanggal Lahir : "<<p->info.tl<<endl;
        cout<<"Jenis Kelamin : "<<p->info.jk<<endl;
        cout<<"=====================FILM======================"<<endl;
        if(p->nextrelation!=NULL){
            q = p->nextrelation;
            while(q != NULL){
                cout<<"Judul : "<<q->nextfilm->info.judul<<endl;
                cout<<"ID : "<<q->nextfilm->info.id<<endl;
                cout<<"Genre : "<<q->nextfilm->info.genre<<endl;
                cout<<"Sutradara : "<<q->nextfilm->info.sutradara<<endl;
                cout<<endl;
                q = q->next;
            }
        }else{
            cout<<"-"<<endl;
        }
        cout<<"==============================================="<<endl;
        cout<<endl;
        cout<<endl;
        p = p->next;
    }
}

//print data film yang dimainkan suatu aktor (nomor 9)
void printFilmDariActor(list_actor a, string nama){
    adr_actor p = searchActor(a,nama);
    checkActor(a,p);
    if(p == NULL){
        cout<<"Nama Actor tidak ditemukan"<<endl;
    }else{
        adr_relation q = p->nextrelation;;
        if(q==NULL){
            cout<<"Actor tidak bermain dalam film apapun"<<endl;
        }else{
            int x = 1;
            while(q!=NULL){
                cout<<"====================FILM "<<x<<"====================="<<endl;
                cout<<"Judul : "<<q->nextfilm->info.judul<<endl;
                cout<<"ID : "<<q->nextfilm->info.id<<endl;
                cout<<"Genre : "<<q->nextfilm->info.genre<<endl;
                cout<<"Sutradara : "<<q->nextfilm->info.sutradara<<endl;
                q = q->next;
                x++;
                cout<<endl;
            }
            cout<<"==============================================="<<endl;
        }
    }
}

void disconnect(list_actor &a, string nama, string judul){
    adr_actor p = searchActor(a,nama);
    checkActor(a,p);
    adr_relation q = searchRelation(p,judul);
    if(q!=NULL){
        q->nextfilm=NULL;
        if(p->nextrelation==q){
            if(q->next==NULL){
                p->nextrelation=NULL;
            }else{
                p->nextrelation=q->next;
                q->next = NULL;
            }
        }else if(q->next==NULL){
            adr_relation r = p->nextrelation;
            while(r->next != q){
                r = r->next;
            }
            r->next = NULL;
        }else{
            adr_relation r = p->nextrelation;
            while(r->next != q){
                r = r->next;
            }
            r->next = q->next;
            q->next = NULL;
        }
    }
}

//disconnect+delete film(nomor 10)
void disconnectdel(list_actor &a,list_film &f,string nama, string judul){
    adr_actor p = searchActor(a,nama);
    checkActor(a,p);
    adr_relation q = searchRelation(p,judul);
    deleteFilm(f,judul);
    adr_actor y = first(a);
    while(y!=NULL){
        disconnect(a,y->info.name,judul);
        y = y->next;
    }
    q->nextfilm=NULL;
}

//tampilkan jumlah film yang punya aktor yang sama (nomor 11)
void jumlahFilm(list_actor a,string nama){
    adr_actor p = searchActor(a,nama);
    checkActor(a,p);
    adr_relation q = p->nextrelation;
    int i = 0;
    while(q!=NULL){
        i++;
        q = q->next;
    }
    cout<<"Actor "<<nama<<" Bermain Dalam "<<i<<" Film"<<endl;
}

//select menu
int selectMenu(){
    cout<<"================================MENU=================================="<<endl;
    cout<<"| 1. Menambah data Actor baru ke list                                |"<<endl;
    cout<<"| 2. Menambah data Film baru ke list                                 |"<<endl;
    cout<<"| 3. Menampilkan semua data Aktor beserta Filmnya                    |"<<endl;
    cout<<"| 4. Menampilkan semua data Film                                     |"<<endl;
    cout<<"| 5. Menampilkan data seorang Aktor/Aktris beserta filmnya           |"<<endl;
    cout<<"| 6. Menghubungkan Actor dan Film                                    |"<<endl;
    cout<<"| 7. Memutuskan Actor dan sebuah Film                                |"<<endl;
    cout<<"| 8. Mencari Data Actor                                              |"<<endl;
    cout<<"| 9. Mencari Data Film                                               |"<<endl;
    cout<<"| 10. Menampilkan Data semua Film yang diperankan oleh seorang Actor |"<<endl;
    cout<<"| 11. Menampilkan jumlah film yang diperankan oleh seorang Actor     |"<<endl;
    cout<<"| 12. Menghapus data actor beserta filmnya                           |"<<endl;
    cout<<"| 13. Menghapus film yang diperankan oleh seorang Actor              |"<<endl;
    cout<<"| 0. Exit                                                            |"<<endl;
    cout<<"======================================================================"<<endl;
    cout<<"Masukkan menu : ";
    int input = 0;
    cin >> input;
    return input;
}

//extra
void deleteFilm(list_film &f, string judul){
    adr_film q = searchFilm(f,judul);
    checkFilm(f,q);
    if(q==first(f)){
        first(f) = first(f)->next;
        q->next = NULL;
        last(f)->next = first(f);
    }else if(q==last(f)){
        last(f) = last(f)->prev;
        q->next = NULL;
        last(f)->next = first(f);
    }else{
        adr_film r = q->prev;
        r->next = q->next;
        q->next = NULL;
    }
}

adr_relation searchRelation(adr_actor q, string judul){
    adr_relation p = q->nextrelation;
    while(p!=NULL && p->nextfilm->info.judul != judul){
        p = p->next;
    }
    return p;
}

void deleteRelation(adr_actor q, string judul){
    adr_relation p = searchRelation(q,judul);
    if(p==NULL){
        cout<<"Actor yang anda masukkan tidak bermain di film tersebut"<<endl;
    }else{
        p->nextfilm = NULL;
        adr_relation s = q->nextrelation;
        while(s->next!=p){
            s = s->next;
        }
        s->next = NULL;
    }
}

void checkActor(list_actor a ,adr_actor &p){
    string nama;
    while(p==NULL){
        cout<<"Nama Actor Tidak Ditemukan Masukkan kembali"<<endl;
        cout<<"Nama Actor : ";
        cin.ignore();
        getline(cin, nama);
        p = searchActor(a,nama);
    }
}

void checkFilm(list_film f, adr_film &p){
    string judul;
    while(p==NULL){
        cout<<"Nama Film Tidak Ditemukan Masukkan kembali"<<endl;
        cout<<"Nama Film : ";
        cin.ignore();
        getline(cin, judul);
        p = searchFilm(f,judul);
    }
}
