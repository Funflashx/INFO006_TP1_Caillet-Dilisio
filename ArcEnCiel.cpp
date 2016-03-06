//
// Created by François Caillet on 29/02/2016.
//

#include "ArcEnCiel.h"

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

/**
 *  Sépare un text en fonction d'un charatère
 *  SOURCE = http://stackoverflow.com/questions/236129/split-a-string-in-c
 *  @param s : texte à découper
 *  @param delim : le charatère de séparation
 *  @return le texte découpé
 */
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


void ArcEnCiel::create(Contexte ctxt, int num, int M, int T){
    this->_X.resize((unsigned long) M);

    this->_numero = num;
    this->_M = M;
    this->_T = T;

    uint64 indexTemp;

    for (int i = 0; i < M; ++i) {
        //printf("i- %d\n", i);
        this->_X[i].idx1 = ctxt.randIndex();
        indexTemp = this->_X[i].idx1;
        for (int j = 1; j < T-1; ++j) {
            indexTemp = ctxt.i2i((uint64) j, indexTemp);
        }
        this->_X[i].idxT = ctxt.i2i((uint64) (T - 1), indexTemp);
    }

    printf("\n");


}

void ArcEnCiel::displayChaine() {
    for (int i = 0; i < this->_M ; ++i) {
        printf("%lld -i2i(1)-> ... ",this->_X[i].idx1);
        printf("-i2i(%d)-> %lld\n", this->_T-1, this->_X[i].idxT);
    }

}

/**
 *  fonction de comparaison de deux Chaines
 *  @param c1, c2 : les chaine à comparer en fonction de leur idxT
 */
bool sort_chaine(Chaine const& c1,Chaine const& c2){
    return c1.idxT < c2.idxT;
}

void ArcEnCiel::sort_by_idTx(){
    sort(this->_X.begin(), this->_X.end(), &sort_chaine);
}

void ArcEnCiel::save( string name ){
    fstream savedTable(name, ios::out | ios::trunc );
    if (savedTable.is_open()) {
        savedTable << this->_M << endl;
        savedTable << this->_T << endl;
        for (int i = 0; i < this->_M; ++i) {
            savedTable << this->_X[i].idx1;
            savedTable << "-" << this->_X[i].idxT << endl;
        }

        savedTable.close();
    } else cerr << "This file cannot be create" << endl;

}

void ArcEnCiel::load( string name ){
    string line;

    ifstream loadedTable(name);
    if (loadedTable.is_open())
    {
        getline (loadedTable, line);
        int m = stoi(line);
        this->_M = m;

        getline (loadedTable, line);
        int t = stoi(line);
        this->_T = t;

        this->_X.resize((unsigned long) this->_M);

        for (int i = 0; i < this->_M ; ++i) {
            getline(loadedTable, line);
            vector<string> x = split(line, '-');
            this->_X[i].idx1 = stoul(x[0]);
            this->_X[i].idxT = stoul(x[1]);
        }
        loadedTable.close();
    }

    else cerr << "Unable to open file";

}



bool ArcEnCiel::find(uint64 idx, Chaine *&p, Chaine *&q)
{
    int istart, iend, imid;
    bool found = false;
    istart = 0;
    iend = _M;
    imid = (istart + iend) / 2;

    while(!found && (istart <= iend ))
    {
        imid = (istart + iend) / 2;

        found = (_X[imid].idxT == idx);

        if(_X[imid].idxT > idx) iend = imid-1;
        else istart = imid+1;
    }
    if(found)
    {
        p=&_X[imid];
        q=&_X[imid];
        while ((p-1)->idxT == idx) p--;
        while ((q+1)->idxT == idx) q++;

        return true;
    }
    else return false;
}

