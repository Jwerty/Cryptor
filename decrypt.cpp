#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int getBytes(const char *str, int number) {
	int bytes_array[8];
	int all_bytes = atoi(str);
	int j;
	for (int i = 7; i >= 0; i--) {
		j = all_bytes % 10;
		bytes_array[i] = j;
		all_bytes = (all_bytes - j) / 10;
	}
	return bytes_array[number];
}

int getInteger(const char *string_bytes) {
	int number = 0;
	int n = 7;
	for (int i = 0; i < 8; i++) {
		number += getBytes(string_bytes, i) * pow(2, n);
		n--;
	}
	return number;
}

int main(int argc, char *argv[]) {
	if (argc != 2)
		return 1;
	string file_name = argv[1];
	ifstream in(file_name, ios_base::in);
	char bytes[8];
	string buffer = "";
	while (in >> bytes)
		buffer += static_cast<char>(getInteger(bytes));
	in.close();
	ofstream out(file_name, ios_base::trunc);
	out << buffer;
	out.close();
}
