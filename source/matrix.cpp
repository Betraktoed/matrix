#include <iostream>
#include "matrix.hpp"

CMatrix::CMatrix() {
    height = width = 0;
    space = nullptr;
}
int CMatrix::getelem(const int a, const int b) const{
	if (a < height && b < width) {
        return space[a][b];
    }else{
        return 1;
	}
}
CMatrix::CMatrix(const CMatrix& M) : CMatrix() {
    if ( M.height && M.width ) {

        height = M.height;
        width = M.width;
        space = new int*[height];

        for(unsigned int i = 0; i < height; i++) {
            space[i] = new int[width];

            for(unsigned int j = 0; j < width; j++)
                space[i][j] = M.space[i][j];
        }
    }
}

CMatrix::CMatrix(unsigned int n, unsigned int m, int **arr) : CMatrix(){
	height = n;
	width = m;
	space = arr;
}

CMatrix::CMatrix(unsigned int n, unsigned int m) : CMatrix() {
    if ( n && m ) {


        height = n;
        width = m;
        space = new int*[n];

        for(unsigned int i = 0; i < n; i++) {
            space[i] = new int[m];

            for(unsigned int j = 0; j < m; j++)
                space[i][j] = 0;
        }
    } 
}

CMatrix::~CMatrix() {
    for(unsigned int i = 0; i < height; i++) {
        delete space[i];
	}
    delete space;
}

CMatrix& CMatrix::operator=(const CMatrix& M) {

	if (this != &M){    
		CMatrix(M).swap(*this);
	}

    return *this;
}

bool CMatrix::operator==(const CMatrix& M) const {
	
	if (height == M.height && width == M.width){
		unsigned int i, j;
		for (i = 0; i < height; i++){
			for (j = 0; j < width; j++){
				if (M.space[i][j] != space[i][j]){
					return false;
				}
			}
		}
	}else{
		return false;
	}
	return true;
}

CMatrix CMatrix::operator+(const CMatrix& M) const {

    assert ( height == M.height && width == M.width );

    CMatrix res;
	res.height = M.height;
    res.width = M.width;
    res.space = new int*[res.height];
    unsigned int i, j;

    for(i = 0; i < res.height; i++) {
        res.space[i] = new int[res.width];

        for(j = 0; j < res.width; j++)
            res.space[i][j] = space[i][j] + M.space[i][j];
    }

    return res;
}

CMatrix CMatrix::operator*(const CMatrix& M) const {
    CMatrix res;

    if ( height && M.height == width && width && M.width ) {
        unsigned int i, j, k;

        res.height = height;
        res.width = M.width;
        res.space = new int*[res.height];

        for(i = 0; i < res.height; i++) {
            res.space[i] = new int[res.width]{};

            for(j = 0; j < res.width; j++)
                for(k = 0, res.space[i][j] = 0; k < M.height; k++)
                res.space[i][j] += space[i][k] * M.space[k][j];
        }
    }

    return res;
}

bool CMatrix::operator>>(std::fstream &file) {
    for(unsigned int i = 0; i < height; i++)
        delete space[i];

    delete space;

	unsigned int new_width;
	unsigned int new_height;

    if( file >> new_height >> new_width ) {
		int ** new_data = new int *[new_height];
		bool success = true;
		for( unsigned int i = 0; success && i < new_height; ++i ) {
			new_data[i] = new int[new_width];
			for( unsigned int j = 0; j < new_width; ++j ) {
				if( !(file >> new_data[i][j]) ) {
					success = false;
					break;
				}
			}	
		}
		
		if( success ) {
			CMatrix( new_height, new_width, new_data ).swap( *this );
			return true;
		}
	}

	return false;
}

std::ostream& CMatrix::operator<<(std::ostream &output) const {
    if ( height && width ) {
        unsigned int i, j;

        for(i = 0; i < height; i++) {
            for(j = 0; j < width; j++)
                output << space[i][j] << ' ';

            output << std::endl;
        }
    } else
        output << "NAM";

    return output;
}

