#include "main.h"

int PGM_detector(fstream *f) {
	char pgm_hdr[2];
	f->read(pgm_hdr, 2);
	if (pgm_hdr[0] != 'P' || pgm_hdr[1] != '5') { 
		return 1;
	}
	else return 0;
}
int read_pgm_file(fstream * f, char symbol) {
	int c = 1, result = 0;
	char sym = 0;
	char alphabet[256];
	unsigned int digit_b = static_cast<unsigned int>(f->tellg()) + 1;
	do {
		f->read(&sym, 1);
	} while (sym != symbol);
	unsigned int digit_e = static_cast<unsigned int>(f->tellg()) - 2;
	for (int d = '0', j = 0; d < '9'; d++, j++) alphabet[d] = j;
	for (int i = digit_e; i >= digit_b; i--, c *= 10) {
		f->seekg(i);
		f->read(&sym, 1);
		result += alphabet[sym] * c;
	}
	f->seekg(digit_e + 1);
	return result;
}
void build_histogram(fstream *f, unsigned int  histogram[256], int width, int heigth) {
	char sym;
	for (int i = 0; i < (width*heigth); i++) {
		if (f->eof()) break;
		f->read(&sym, 1);
		histogram[static_cast<unsigned char>(sym)] += 1;
	}
}
void print_in_file(unsigned int *histogram, int width, int heigth, char** args) {
	ofstream* out = new ofstream("histogram.txt");
	*out << "Изображение в файле: " << args[1] << " обработано." << endl;
	*out << "Ширина: " << width << endl;
	*out << "Высота: " << heigth << endl;
	*out << "Гистограмма приведена ниже." << endl;
	for (int i = 0; i < 256; i++) {
		*out << "[" << i << "]";
		for (unsigned int c = 0; c < histogram[i]; c += 10) *out << "|";
		*out << endl;
	}
	out->close();
	delete out;
	ofstream* out_xls = new ofstream("histogram.xls");
	*out_xls << "Изображение в файле: " << args[1] << " обработано." << endl;
	*out_xls << "Ширина: " << width << endl;
	*out_xls << "Высота: " << heigth << endl;
	*out_xls << "Гистограмма приведена ниже." << endl;
	for (int i = 0; i < 256; i++) {
		for (unsigned int c = 0; c < histogram[i]; c += 10) *out_xls << "+1";
		*out_xls << endl;
	}
	out_xls->close();
	delete out_xls;
}
