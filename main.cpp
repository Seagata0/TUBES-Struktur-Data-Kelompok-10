#include "tubes.h"

using namespace std;

int main(){
    list_film lfilm;
    list_actor lactor;
    createListFilm(lfilm);
    createListActor(lactor);
    int Pilihan = 0, N;
    Pilihan = selectMenu();
    char answer;
    while (Pilihan != 0){
        switch(Pilihan){
        case 1:
            {
                actor data;
                adr_actor p;
                cout<<"Jumlah Actor yang akan ditambahkan : ";
                cin>>N;
                cout<<endl;
                for(int i=1;i<=N;i++){
                    cout<<"Data Ke : "<< i <<endl;
                    cout<<"Masukkan data baru "<<endl;
                    cout<<"Masukkan Nama : ";
                    cin.ignore();
                    getline(cin, data.name);
                    cout<<"Masukkan Kebangsaan : ";
                    cin>>data.nation;
                    cout<<"Masukkan Tanggal Lahir(DD/MM/YYYY) : ";
                    cin>>data.tl;
                    cout<<"Masukkan Jenis Kelamin(L/P)";
                    data.jk = '0';
                    while (data.jk!='L' && data.jk!='P'){
                        cin>>data.jk;
                    }
                    p = createElementActor(data);
                    insertLastActor(lactor,p);
                    cout<<endl;
                }
            }
            break;
        case 2:
            {
                film data2;
                adr_film q;
                cout<<"Jumlah Film yang akan ditambahkan : ";
                cin>>N;
                cout<<endl;
                for(int i=1;i<=N;i++){
                    int x = 0;
                    cout<<"Data Ke : "<< i <<endl;
                    cout<<"Masukkan data baru "<<endl;
                    cout<<"Masukkan Judul : ";
                    cin.ignore();
                    getline(cin, data2.judul);
                    cout<<"Masukkan ID : ";
                    cin>>data2.id;
                    cout<<"Masukkan Genre(a,b,c) : ";
                    cin>>data2.genre;
                    cout<<"Masukkan Sutradara : ";
                    cin.ignore();
                    getline(cin, data2.sutradara);
                    q = createElementFilm(data2);
                    cout<<"Dimana anda ingin memasukkan film?"<<endl;
                    cout<<"1. Menambahkan data film didepan"<<endl;
                    cout<<"2. Menambahkan data film dibelakang"<<endl;
                    cout<<"Input : ";
                    while (x!=1 && x!=2){
                        cin>>x;
                    }
                    if(x==1){
                        insertFirstFilm(lfilm,q);
                    }else if(x==2){
                        insertLastFilm(lfilm,q);
                    }
                }
            }
            break;
        case 3:
            printActorDanFilm(lactor);
            break;
        case 4:
            {
                string nama;
                cout<<"Nama : ";
                cin.ignore();
                getline(cin, nama);
                printFilmDariActor(lactor,nama);
            }
            break;
        case 5:
            {
                string nama,judul;
                cout<<"Nama Actor : ";
                cin.ignore();
                getline(cin, nama);
                cout<<"Nama Film : ";
                cin.ignore();
                getline(cin, judul);
                connect(lactor,lfilm,nama,judul);
                break;
            }
        case 6:
            {
                string nama,judul;
                cout<<"Nama Actor : ";
                cin.ignore();
                getline(cin, nama);
                cout<<"Nama Film : ";
                cin.ignore();
                getline(cin, judul);
                disconnect(lactor,nama,judul);
                break;
            }
        case 7:
            {
                string nama;
                cout<<"Nama Actor : ";
                cin.ignore();
                getline(cin, nama);
                adr_actor p = searchActor(lactor,nama);
                cout<<"Name : "<<p->info.name<<endl;
                cout<<"Kebangsaan : "<<p->info.nation<<endl;
                cout<<"Tanggal Lahir : "<<p->info.tl<<endl;
                cout<<"Jenis Kelamin(L/P) : "<<p->info.jk<<endl;
                break;
            }
        case 8:
            {
                string judul;
                cout<<"Nama Film : ";
                cin.ignore();
                getline(cin, judul);
                adr_film p = searchFilm(lfilm,judul);
                cout<<"Judul : "<<p->info.judul<<endl;
                cout<<"ID : "<<p->info.id<<endl;
                cout<<"Genre : "<<p->info.genre<<endl;
                break;
            }
        case 9:
            {
                string nama;
                cout<<"Nama Actor : ";
                cin.ignore();
                getline(cin, nama);
                printFilmDariActor(lactor,nama);
            }
        case 10:
            {
                string nama;
                cout<<"Nama Actor : ";
                cin.ignore();
                getline(cin, nama);
                jumlahFilm(lactor,nama);
            }
        case 11:
            {
                string nama;
                cout<<"Nama Actor : ";
                cin.ignore();
                getline(cin, nama);
                adr_actor p = searchActor(lactor,nama);
                delActorFilm(lactor,lfilm,p);
            }
        case 12:
            {
                string nama,judul;
                cout<<"Nama Actor : ";
                cin.ignore();
                getline(cin, nama);
                cout<<"Nama Film : ";
                cin.ignore();
                getline(cin, judul);
                disconnectdel(lactor,lfilm,nama,judul);
            }
        case 13:
            cout<<last(lfilm)->info.judul<<endl;
            adr_film s = first(lfilm);
            cout<<s->info.judul<<endl;
            s = s->next;
            while (s != first(lfilm)){
                cout<<s->info.judul<<endl;
                s = s->next;
            }
        }
        cout<<endl;
        cout<<"Kembali ke menu utama? (Y/N) : ";
        cin>>answer;
        cout<<endl;
        system("CLS");
        if (answer == 'Y' || answer == 'y'){
            Pilihan = selectMenu();
        }else{
            break;
        }
    }
    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;
    return 0;
}
