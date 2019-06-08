#include "main.h"
#include <locale>

int main(int argc, char** args) {
	setlocale(LC_ALL, "rus");
	unsigned int histogram[256] = { 0 };
	fstream * f = new fstream();
	//проверка наличия файла
	if (argc == 1) {
		cout << "Отсутствует входящий файл!" << endl;
		system("pause");
		return 1;
	}
	//проверка открытия файла
	f->open(args[1], ios::binary | ios::in);
	if (f->is_open() != 1) return 1;
	//вызываем наши функции
	if (PGM_detector(f) == 1) return 1;
	int w = 0, h = 0;
	w = read_pgm_file(f, 0x20);
	h = read_pgm_file(f, 0x0A);
	build_histogram(f, histogram,w,h);
	print_in_file(histogram,w, h, args);
	f->close();
	delete f;
	system("pause");
	return 0;
}