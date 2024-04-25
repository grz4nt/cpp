#include <string>
#include <vector>

class Gracz;
// Klasa reprezentująca pole na planszy
class Pole {
public:
    std::string nazwa;
    int kosztZakupu;
    int kosztDomu;
    int kosztHotelu;
    int wartoscHipoteki;
    int czynsz;
    int kara;
    int bonus;

    Pole(std::string nazwa, int kosztZakupu, int kosztDomu, int kosztHotelu, int wartoscHipoteki, int czynsz, int kara, int bonus);
    virtual void wyladujNaPolu(Gracz& gracz) = 0; // Metoda do obsługi lądowania na polu
};

// Klasa reprezentująca pole nieruchomości
class PoleNieruchomosci : public Pole {
public:
    PoleNieruchomosci(std::string nazwa, int kosztZakupu, int kosztDomu, int kosztHotelu, int wartoscHipoteki, int czynsz);
    void wyladujNaPolu(Gracz& gracz) override;
};

// Klasa reprezentująca pole kary
class PoleKary : public Pole {
public:
    PoleKary(std::string nazwa, int kara);
    void wyladujNaPolu(Gracz& gracz) override;
};

// Klasa reprezentująca pole bonusu
class PoleBonusu : public Pole {
public:
    PoleBonusu(std::string nazwa, int bonus);
    void wyladujNaPolu(Gracz& gracz) override;
};

// Klasa reprezentująca gracza
class Gracz {
public:
    std::string nazwa;
    int pieniadze;
    std::vector<Pole*> nieruchomosci;

    Gracz(std::string nazwa, int pieniadze);
    void kupNieruchomosc(Pole& pole);
    void sprzedajNieruchomosc(Pole& pole);
    void zaplacCzynsz(Pole& pole);
    void odbierzCzynsz(Pole& pole);
    void postawDom(Pole& pole);
    void postawHotel(Pole& pole);
};

// Klasa reprezentująca bankiera
class Bankier {
public:
    std::vector<Pole*> nieruchomosci;

    void sprzedajNieruchomosc(Gracz& gracz, Pole& pole);
    void kupNieruchomosc(Gracz& gracz, Pole& pole);
    void zastawNieruchomosc(Gracz& gracz, Pole& pole);
    void wykupNieruchomosc(Gracz& gracz, Pole& pole);
};

int main() {
    return 0;
}