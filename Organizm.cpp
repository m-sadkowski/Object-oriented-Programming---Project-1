#include"Organizm.h"
#include"Cursor.h"
#include"Swiat.h"

Organizm::Organizm(int sila, int inicjatywa, char symbol, int x, int y, Swiat* swiat)
	: sila(sila), inicjatywa(inicjatywa), symbol(symbol), x(x), y(y), swiat(swiat), wiek(0) {}

Organizm::Organizm(int x, int y, Swiat* swiat, char symbol, int wiek, int sila, int inicjatywa, int cooldown) 
	: x(x), y(y), swiat(swiat), symbol(symbol), wiek(wiek), sila(sila), inicjatywa(inicjatywa), cooldown(cooldown) {}

std::ostream& operator<<(std::ostream& out, Organizm* org) {
	out << org->getSymbol() << " x: " << org->getX() << " y: " << org->getY() << " wiek: " << org->getWiek() << " sila: " << org->getSila() << " inicjatywa: " << org->getInicjatywa() << "\n";
	return out;
}

Organizm::~Organizm() {}

void Organizm::rysowanie() {
	int x = this->getX();
	int y = this->getY();
	gotoxy(x, y);
	std::cout << symbol;
	gotoxy(0, 0);
}

std::string Organizm::nazwaOrganizmu(char symbol) {
    switch (symbol) {
    case 'C':
        return "Czlowiek";
    case 'W':
        return "Wilk";
    case 'O':
        return "Owca";
    case 'Z':
        return "Zolw";
    case 'L':
        return "Lis";
    case 'A':
        return "Antylopa";
    case 't':
        return "Trawa";
    case 'm':
        return "Mlecz";
    case 'g':
        return "Guarana";
    case 'w':
        return "Wilcze Jagody";
    case 'b':
        return "Barszcz Sosnowskiego";
    default:
        return "Nieznany";
    }
}


