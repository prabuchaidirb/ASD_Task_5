#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L)=NULL;
    last(L)=NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //-------------your code here-------------
    P = (address)malloc(sizeof(elmlist));
	info(P) = x;
	next(P) = NULL;
	prev(P) = NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete(P);
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if (first(L) == NULL)
    {
		first(L) = P;
		last(L) = P;
		next(first(L)) = last(L);
		prev(first(L)) = last(L);
		next(last(L)) = first(L);
		prev(last(L)) = first(L);
	}
	else
	{
		next(P) = first(L);
		prev(P) = last(L);
		prev(first(L)) = P;
		next(last(L)) = P;
		first(L) = P;
	}
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (first(L) != NULL)
    {
		if (first(L) == last(L))
		{
			last(L) = P;
			next(first(L)) = last(L);
			prev(first(L)) = last(L);
			next(last(L)) = first(L);
			prev(last(L)) = first(L);
		}
		else
		{
			prev(P) = last(L);
			next(P) = first(L);
			next(last(L)) = P;
			prev(first(L)) = P;
			last(L) = P;
		}
	}
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    if (first(L) != NULL)
    {
		address addr = first(L);
		if (addr->info.ID == x.ID)
		{
		    return addr;
		}
		else
        {
			addr = next(addr);
			while (addr != first(L))
			{
				if (addr->info.ID == x.ID)
					return addr;
				addr = next(addr);
			}
		}
	}
    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    if (first(L) != NULL)
    {
		address addr = first(L);
		if (addr->info.name == x.name)
		{
		    return addr;
		}
		else
        {
			addr = next(addr);
			while (addr != first(L))
			{
				if (addr->info.name == x.name)
					return addr;
				addr = next(addr);
			}
		}
	}
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (first(L) != NULL)
    {
		P = first(L);
		first(L) = next(first(L));
		next(last(L)) = first(L);
	}
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (first(L) != NULL && last(L) != NULL)
    {
		P = last(L);
		last(L) = prev(last(L));
		prev(first(L)) = last(L);
	}
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if (Prec != NULL && P != NULL)
    {
		if (Prec == last(L))
		{
		    L.last = P;
		}
		next(P) = next(Prec);
		prev(P) = Prec;
        prev(next(P))= P;
		next(Prec) = P;
	}
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (Prec != NULL)
    {
		if (next(Prec) == first(L))
        {
            L.first = next(first(L));
        }
		else if (next(Prec) == last(L))
        {
            last(L) = Prec;
        }
		P = next(Prec);
		next(Prec) = next(next(Prec));
		prev(next(Prec)) = Prec;
	}
    //----------------------------------------
}

