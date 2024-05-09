#include <string>
#include <vector>

class Gracz;
class PoleMiasto;
class Plansza;
class KartaSzansy;
class KasaSpoleczna;
class Kosc;
class Bankier;
class Wiezienie;
class PoleUzytek;
class PoleDworzec;
class Podatek;
class PoleStart;
class DarmowyParking;
class Dom;
class Hotel;

class Gracz {
    std::string name;
    int pieniadze;
    int pozycja;
    bool wWiezieniu;
    std::vector<PoleMiasto*> nieruchomosci;
    bool kartaWiezienie;
    int ileDworzec;
    int ileUzytek;
    int ileDom;
    int ileHotel;
    void przesun(int ruchy);
};
class PoleMiasto {
    std::string name;
    int koszt;
    int wynajem;
    Gracz* owner;
    bool kredyt;
    int ileDom;
    int ileHotel;
    bool czyMonopoly;
    int kredytWartosc;
    int domKoszt;
    int hotelKoszt;
};
class Plansza {
    std::vector<PoleMiasto*> nieruchomosci;
    std::vector<Gracz*> gracze;
    std::vector<KartaSzansy*> kartySzans;
    std::vector<KasaSpoleczna*> kartySpoleczne;
    std::vector<PoleUzytek*> uzytki;
    std::vector<PoleDworzec*> dworce;
    DarmowyParking* parking;
    KartaSzansy* szansaPole;
    KasaSpoleczna* spolecznaPole;
    std::vector<Dom*> domy;
    std::vector<Hotel*> hotele;
};
class KartaSzansy {
    std::string opis;
    int efekt;
    bool kartaWyjdzWiezienie;
    bool kartaDoStart;
    int gotowkaIle;
    int przesunIle;
};
class KasaSpoleczna {
    std::string opis;
    int efekt;
    bool kartaWyjdzWiezienie;
    bool kartaDoStart;
    int gotowkaIle;
    int przesunIle;
    bool zabierzPieniadze;
    bool dajPieniadze;
};
class Kosc {
    int koscBoki;
    bool koscRzucona;
    int wynikRzutu;
    int ileRuchu;
};
class Bankier {
    int sumaPieniadze;
    std::vector<PoleMiasto*> nieruchomosci;
    std::vector<Gracz*> graczePozyczka;
};
class Wiezienie {
    int oplataWiezienie;
    std::vector<Gracz*> wieznie;
};

class PoleUzytek {
    std::string name;
    int kosztKupna;
    Gracz* owner;
    int wynajem;
};

class PoleDworzec {
    std::string name;
    int koszt;
    Gracz* owner;
    int wynajem;
};

class Podatek {
    int kwotaPodatek;
    std::string nazwaPodatek;
};

class PoleStart {
    int premiaStart;
};

class DarmowyParking {
    std::vector<Gracz*> gracze;
    int loteria;
};

class Dom {
    std::string name;
    int koszt;
    Gracz* owner;
    int wynajem;
};

class Hotel {
    std::string name;
    int koszt;
    Gracz* owner;
    int wynajem;
};

int main() {
    return 0;
}