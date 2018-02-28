#include <fstream>
#include <string>
using namespace std;

char bytes[9];
char *getBinary(char sym, bool endLine) {
	int n = 0;
	for (int i = 7; i >= 0; i--) {
		if (sym & (1 << i))
			bytes[n] = '1';
		else
			bytes[n] = '0';
		n++;
	}
	if (endLine == false)
		bytes[8] = ' ';
	else
		bytes[8] = '\n';
	return bytes;
}

int main(int argc, char *argv[]) {
	if (argc != 2)
		return 1;
	string file_name = argv[1];
	ifstream in(file_name, ios_base::in);
	string buffer = "";
	char sym;
	for (int n = 1; in.get(sym); n++) {
		if (n == 4) {
			buffer += getBinary(sym, true);
			n = 0;
		}
		else
			buffer += getBinary(sym, false);
	}
	in.close();
	ofstream out(file_name, ios_base::trunc);
	out << buffer;
	out.close();
}
