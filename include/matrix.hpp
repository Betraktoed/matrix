#include <iostream>
#include <fstream>
#include<cassert>
using namespace std;
class CMatrix {
private:
    unsigned int height, width;
    int **space;

	void swap( CMatrix & other )
	{
		std::swap( height, other.height );
		std::swap( width, other.width );
		std::swap( space, other.space );
	}
		

public:
    CMatrix();
    CMatrix(const CMatrix& M);
    CMatrix(unsigned int n, unsigned int m);
	CMatrix(unsigned int n, unsigned int m, int **arr);
    ~CMatrix();
	int getHeight() const {return height;};
	int getWidth() const {return width;};
	int getelem(const int a, const int b) const;
    bool operator>>(std::fstream &file);
    std::ostream& operator<<(std::ostream &output) const;

    CMatrix& operator=(const CMatrix& M);
	bool operator==(const CMatrix& M) const;
    CMatrix operator*(const CMatrix& M) const;
    CMatrix operator+(const CMatrix& M) const;
};

