#include <iostream>
#include "QE.hpp"
using namespace std;

struct Student { 
	int score = 0;
	string name;
};

void PrintTable(struct Student* students,int size) {

	for (int i = 0; i < size; i++) {
		cout << students[i].name << " : " << students[i].score << endl;
	}

}

struct Student* GetAnswers(struct Student* students,int* size) {

	string name; 
	string nameSecond;
	Student* studentsTmp = new Student[*size];
	float studentAnswer; 
	bool IsRight = false;
	bool IsEx = false;
	Poly poly = GetPoly(); //Gets polinomial coefficients
	Answer answer = QuadraticEquation(poly); // gets answers
	cin >> studentAnswer; // getting student answer
	if(studentAnswer == 0 && answer.x1 != studentAnswer){ //checking if student answer is correct
		IsRight = false;
	}
	else if (studentAnswer == answer.x1) {
		cin >> studentAnswer;
		if (studentAnswer == answer.x2) {
			IsRight = true;
		}
		else {
			IsRight = false;
		}
	}
	else if (studentAnswer == answer.x2) {
		cin >> studentAnswer;
		if (studentAnswer == answer.x1) {
			IsRight = true;
		}
		else {
			IsRight = false;
		}
	}
	else {
		IsRight = false;
	}

	cin >> name; //getting student name
	cin >> nameSecond;

	for (int i = 0; i < *size; i++) { //if this student already in array +1 to his score
		if (students[i].name == name + " " + nameSecond) {
			if (IsRight) {
				students[i].score++;
				IsEx = true;
			}
		}
	}

	if (!IsEx) { //if student not in array, add him and his score = 1
		(*size)++;
		studentsTmp = new Student[*size];
		studentsTmp[*size - 1].name = name + " " + nameSecond;

		if (IsRight) {
			studentsTmp[*size-1].score++;
		}
		for (int i = 0; i < *size - 1; i++) {
			studentsTmp[i].name = students[i].name;
			studentsTmp[i].score = students[i].score;
		}
		return studentsTmp;
	}
	return students;

}

void Offset() { // just called from main
	struct Student* students; //creating array of students
	int size = 0;
	students = new Student[size];
	char c;
	while (1) { //ends when all students checked
		students = GetAnswers(students, &size);
		c = getchar();
		if (c != '\n' || c == ' ')
			break;
	}
	PrintTable(students,size);

}

int main(void) {

	Offset();

	return 0;
}
