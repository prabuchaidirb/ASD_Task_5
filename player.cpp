#include "player.h"
#include <ctime>

int randomInt(int  max_int) {
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L) {
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */

    address Q = first(L);
    do {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    } while(Q!=first(L));
    cout<<"==============================================="<<endl;
}


void playMusic(address P) {
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L) {
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //-------------your code here-------------
    address addr = first(L);
	address place;
	int repeat = randomInt(10);
	for (int i = 0; i < repeat; i++)
    {
		addr = next(addr);
	}
	deleteAfter(L, addr, place);
	insertFirst(L, place);
    //----------------------------------------
}

void sortListByID(List &L) {
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan ID
    * FS : isi (elemen) dari list L terurut
    */
    //-------------your code here-------------
    address addr = first(L);
	address place;
	while (addr->info.ID > addr->next->info.ID) {
		deleteAfter(L, prev(addr), place);
		insertAfter(L, next(addr), place);
	}
    //----------------------------------------

}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //-------------your code here-------------
    address addr = first(L);
	for (int i = 0; i < n; i++) {
		while (next(addr) != first(L))
		{
			playMusic(addr);
			addr = next(addr);
		}
	}
    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x) {
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //-------------your code here-------------
    if (L.first != NULL)
    {
		address addr = first(L);
		address del;
		bool found = false;
		while (next(addr) != first(L) && !found)
		{
			if (addr->info.ID == x.ID)
			{
				deleteAfter(L, prev(addr), del);
				deallocate(del);
			}
		}
	}
    //----------------------------------------

}
