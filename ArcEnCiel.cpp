//
// Created by François Caillet on 29/02/2016.
//

#include "ArcEnCiel.h"


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


void ArcEnCiel::creer( Contexte ctxt, int num, int M, int T ){
    this->_X.resize( M );

    this->_numero = num;
    this->_M = M;
    this->_T = T;

    uint64 indexTemp;

    for (int i = 0; i < M; ++i) {
        this->_X[i].idx1 = ctxt.randIndex();
        indexTemp = this->_X[i].idx1;
        for (int j = 1; j < T-1; ++j) {
            indexTemp = ctxt.i2i(j,indexTemp);
        }
        this->_X[i].idxT = ctxt.i2i(T-1,indexTemp);
    }
}

void ArcEnCiel::displayChaine() {
    for (int i = 0; i < this->_M ; ++i) {
        printf("%lld -i2i(1)-> ... ",this->_X[i].idx1);
        printf("-i2i(%d)-> %lld\n", this->_T-1, this->_X[i].idxT);
    }

}

bool sort_chaine(Chaine const& c1,Chaine const& c2){
    return c1.idxT < c2.idxT;
}

void ArcEnCiel::trier(){
    sort(this->_X.begin(), this->_X.end(), &sort_chaine);
}

void ArcEnCiel::save( std::string name ){
    fstream myfile (name, ios::out | ios::trunc );
    if (myfile.is_open()) {
        myfile << this->_M << endl;
        myfile << this->_T << endl;
        for (int i = 0; i < this->_M; ++i) {
            myfile << this->_X[i].idx1;
            myfile << "-" << this->_X[i].idxT << endl;
        }

        myfile.close();
    } else cerr << "Impossible de creer le fichier" << endl;

}

void ArcEnCiel::load( std::string name ){
    string line;

    ifstream myfile (name);
    if (myfile.is_open())
    {
        getline (myfile,line);
        int m = stoi(line);
        this->_M = m;
        getline (myfile,line);
        int t = stoi(line);
        this->_T = t;
        this->_X.resize( this->_M );
        for (int i = 0; i < this->_M ; ++i) {
            getline(myfile, line);
            vector<string> x = split(line, '-');
            this->_X[i].idx1 = stoul(x[0]);
            this->_X[i].idxT = stoul(x[1]);
        }
        myfile.close();
    }

    else cerr << "Unable to open file";

}