#include <iostream>
typedef struct Poly {
	float a = 0;
	float b = 0;
	float c = 0;
}Poly;

typedef struct Answer {
	float x1 = 0;
	float x2 = 0;
	float Error = 0;
}Answer;

Poly GetPoly() {
	struct Poly poly;

	std::cin >> poly.a >> poly.b >> poly.c;

	return poly;
}



float Discriminant(Poly poly);
Answer QuadraticEquation(Poly poly);
void PrintAnswer(Answer answer);