#include "catch.hpp"
#include "matrix.hpp"
SCENARIO("matrix new w/o params","[new w/o params]"){
    CMatrix matrix;
    REQUIRE(matrix.getHeight() == 0);
    REQUIRE(matrix.getWidth() == 0);
}

SCENARIO("matrix new with params","[new with params]"){
    CMatrix matrix(3,3);
    REQUIRE(matrix.getHeight() == 3);
    REQUIRE(matrix.getWidth() == 3);
}

SCENARIO("matrix operator+","[oper+]"){
    std::fstream fileA, fileB;
	CMatrix A, B, C;
	fileA.open("A.txt");
	fileB.open("B.txt");
	A >> fileA;
	B >> fileB;
	C = A + B;
	REQUIRE(C.getelem(0, 0) == 10);
}


SCENARIO("matrix operator*", "[oper*]") {
    std::fstream fileA, fileB;
	CMatrix A, B, C;
	fileA.open("A.txt");
	fileB.open("B.txt");
	A >> fileA;
	B >> fileB;
	C = A*B;
    REQUIRE(C.getelem(0, 0) == 136);
}

SCENARIO("matrix operator==" , "[oper==]") {
    std::fstream fileA, fileB;
	CMatrix A, B;
	fileA.open("A.txt");
	fileB.open("A.txt");
	A >> fileA;
	B >> fileB;
	REQUIRE(A == B);

}

SCENARIO("matrix operator=" , "[oper=]") {
    std::fstream fileA, fileB;
	CMatrix A, B;
	fileA.open("A.txt");
	fileB.open("B.txt");
	A >> fileA;
	B >> fileB;
	A = B;
	REQUIRE( B.getelem(0, 0) == 1);

}
