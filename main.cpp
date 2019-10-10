#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	string buffer;
	bool flag_sentence = false;
	char prev;
	int count = 0;

	try{
		ifstream fin("C://Users//Nikita//Desktop//Мои работы//4-5 семестр - Технология программирования (С++)//Files for Lab2//Text.dat", ios::in);
		if (!fin)
			throw exception("Файл не открыт!");


		while (!fin.eof()) {
			getline(fin, buffer);
			if (buffer.length() == 0)
				continue;

			buffer.resize(buffer.length() + 1);
			++count;
			prev = ' ';

			for (int i = 0; i < buffer.length() - 2; ++i) {
				if (prev == ' ' && buffer[i] > '0' && buffer[i] <= '9' && buffer[i + 1] >= '0' && buffer[i + 1] <= '9' && (buffer[i + 2] == ' ' || buffer[i + 2] == '\0' || buffer[i + 2] == '.' || buffer[i + 2] == ',')) {
					flag_sentence = true;
					cout << "Строка " << count << ": " << buffer << endl << endl;
					break;
				}
				prev = buffer[i];
			}
		}

		if (!flag_sentence)
			cout << "Нужных предложений нет!" << endl << endl;
	}
	catch (exception &ex) {
		cout << ex.what() << endl << endl;
	}

	system("pause");
	return 0;
}