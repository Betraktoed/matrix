#include <iostream>
#include "matrix.hpp"
CMatrix::CMatrix() {
    height = width = 0;
    space = NULL;
}
int CMatrix::getelem(const int a, const int b) const{
	return space[a][b];
}
CMatrix::CMatrix(const CMatrix& M) {
    if ( M.height && M.width ) {
        unsigned int i, j;

        height = M.height;
        width = M.width;
        space = new int*[height];

        for(i = 0; i < height; i++) {
            space[i] = new int[width];

            for(j = 0; j < width; j++)
                space[i][j] = M.space[i][j];
        }
    } else {
        height = 0;
        width = 0;
        space = NULL;
    }
}

CMatrix::CMatrix(unsigned int n, unsigned int m) {
    if ( n && m ) {
        unsigned int i, j;

        height = n;
        width = m;
        space = new int*[n];

        for(i = 0; i < n; i++) {
            space[i] = new int[m];

            for(j = 0; j < m; j++)
                space[i][j] = 0;
        }
    } else {
        height = 0;
        width = 0;
        space = NULL;
    }
}

CMatrix::~CMatrix() {
    for(unsigned int i = 0; i < height; i++)
        delete space[i];

    delete space;
}

CMatrix& CMatrix::operator=(const CMatrix& M) {
    for(unsigned int i = 0; i < height; i++)
        delete space[i];

    delete space;

    if ( M.height && M.width ) {
        unsigned int i, j;

        height = M.height;
        width = M.width;
        space = new int*[height];

        for(i = 0; i < height; i++) {
            space[i] = new int[width];

            for(j = 0; j < width; j++)
                space[i][j] = M.space[i][j];
        }
    } else {
        height = 0;
        width = 0;
        space = NULL;
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
}

CMatrix CMatrix::operator+(const CMatrix& M) const {
    CMatrix res;

    if ( height == M.height && width == M.width ) {
        unsigned int i, j;

        res.height = M.height;
        res.width = M.width;
        res.space = new int*[res.height];

        for(i = 0; i < res.height; i++) {
            res.space[i] = new int[res.width];

            for(j = 0; j < res.width; j++)
                res.space[i][j] = space[i][j] + M.space[i][j];
        }
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
            res.space[i] = new int[res.width];

            for(j = 0; j < res.width; j++)
                for(k = 0, res.space[i][j] = 0; k < M.height; k++)
                res.space[i][j] += space[i][k] * M.space[k][j];
        }
    }

    return res;
}

void CMatrix::operator>>(std::fstream &file) {
    for(unsigned int i = 0; i < height; i++)
        delete space[i];

    delete space;

    file >> height >> width;
    space = new int*[height];

    if ( height && width ) {
        unsigned int i, j;

        for(i = 0; i < height; i++) {
            space[i] = new int[width];

            for(j = 0; j < width; j++)
                file >> space[i][j];
        }
    } else {
        height = width = 0;
        space = NULL;
    }
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

