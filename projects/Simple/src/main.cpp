#include "../include/student.h"
#include <iostream>
#include <algorithm>
//std::vector<Student> students;

Student add_student(std::vector<Student>& students) {
	Student stud;
	std::cout << "Name: \n";
	std::cin >> stud.Name;
	std::cout << "Grade: \n";
	std::cin >> stud.grade;
	while (stud.grade <= 0) {
		std::cerr << "Grade can't be negative, please choose another number.";
		std::cin >> stud.grade;
	}

	students.emplace_back(stud);
	return stud;
}

float studentAverage(std::vector<Student>& students) {
	float avg;
	int sum{};
	for (auto& student: students) {
		sum += student.grade;
	}

	avg = (float)sum/students.size();

	return avg;
}


void print_student(std::vector<Student>& students) {
	for (auto& student: students) {
		std::cout << "Name: " << student.Name << " Grade: " << student.grade << "\n";
	}
}

Student findMax(std::vector<Student>& students) {
	auto it = std::max_element(students.begin(), students.end(),[](const Student& a, const Student&b){return a.grade < b.grade;});
	return *it;
}

Student findMin(std::vector<Student>& students) {
	auto it = std::min_element(students.begin(), students.end(), [](const Student& a, const Student&b){return a.grade < b.grade;});
	return *it;
}

int maxStud(std::vector<Student>& students) {
	int mx = 0;
	for (auto& student : students) {
		mx = std::max(mx, student.grade);
	}
	return mx;
}

int minStud(std::vector<Student>& students) {
	int mn = INT16_MAX;
	for (auto& student: students) {
		mn = std::min(mn, student.grade);
	}

	return mn;
}

int main() {
	std::vector<Student> students;
	while (true) {
		int input;
		std::cout << "Choose an option?\n" << "1. Add Student\n" << "2. Print Students\n"
		<< "3. Highest Grade\n" << "4. Lowest Grade\n" << "5. Quit\n";
		std::cin >> input;
		while (input > 5) {
			std::cerr << "Out of range, please choose a correct no." << std::endl;
			std::cin >> input;
		}
		switch (input) {
			case(1) : add_student(students); break;
				case (2): print_student(students); break;
				case (3) : findMax(students); break;
				case (4) : findMin(students); break;
				case (5) : return 0;
		}
	}

}


