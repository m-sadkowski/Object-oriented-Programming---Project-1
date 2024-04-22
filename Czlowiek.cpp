#include"Czlowiek.h"
#include"Swiat.h"
#include"Roslina.h"

void Czlowiek::akcja(char c) {
	// OBSLUGA MOCY
	if (czasMocy == 5)
	{
		this->sila = stalaSila;
		mocUzyta = false;
		czasMocy = 0;
		cooldown = 5;
	}
	if (this->sila > stalaSila && mocUzyta)
	{
		this->sila--;
		swiat->dodajKomunikat("Sila czlowieka wynosi " + std::to_string(this->sila));
	}

	// RUCH
	int newX = this->x;
	int newY = this->y;
	if (c == 'w') {
		if (this->y > 1) {
			newY--;
		}
	}
	else if (c == 's') {
		if (this->y < swiat->getWysokosc() - 2) {
			newY++;
		}
	}
	else if (c == 'a') {
		if (this->x > 1) {
			newX--;
		}
	}
	else if (c == 'd') {
		if (this->x < swiat->getSzerokosc() - 2) {
			newX++;
		}
	}
	else if (c == 'm') {
		if (!mocUzyta && !cooldown) {
			aktywujMoc();
			czasMocy++;
		}
	}

	// KOLIZJA PO RUCHU
	if (newX != x || newY != y) {
		if (swiat->getOrganizm(newX, newY) != nullptr)
		{
			this->Zwierze::kolizja(swiat->getOrganizm(newX, newY));
			
		}
		else
		{
			swiat->przeniesOrganizm(this, newX, newY);
		}
	}
}

void Czlowiek::aktywujMoc() {
	this->sila = 10;
	this->mocUzyta = true;
	swiat->dodajKomunikat("Czlowiek aktywowal moc");
}

Czlowiek::~Czlowiek() {}