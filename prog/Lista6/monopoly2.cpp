#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

class Gracz;
class Pole;
class Miasto;
class Plansza;
class KartaSzansy;
class KasaSpoleczna;
class Kosc;
class Uzytek;
class Dworzec;
class DarmowyParking;
class Dom;
class Hotel;
class Bankier;

class Gracz {
private:
    std::vector<Miasto*> nieruchomosci;
    bool kartaWiezienie;
    int ileDworzec;
    int ileUzytek;
    int ileDom;
    int ileHotel;

public:
    int pieniadze;
    std::string name;
    bool wWiezieniu;
    int pozycja;
    void przesun(int ruchy, int liczbaPol);
    Gracz(std::string n, int p) : name(n), pieniadze(p), pozycja(0), wWiezieniu(false), kartaWiezienie(false), ileDworzec(0), ileUzytek(0), ileDom(0), ileHotel(0) {}
    ~Gracz() = default;

    friend class Bankier;
};

class Pole {
protected:
    std::string name;
    Gracz* owner;

public:
    Pole(std::string n) : name(n), owner(nullptr) {}
    virtual ~Pole() = default;

    friend class Bankier;
};

class PoleNieruchomosc : public Pole {
protected:
    int koszt;
    int wynajem;

public:
    PoleNieruchomosc(std::string n, int k, int w) : Pole(n), koszt(k), wynajem(w) {}
    friend class Bankier;
};

class Miasto : public PoleNieruchomosc {
private:
    int cena;
    int czynsz[6];
    int ileDom;
    int ileHotel;
    Dom* domy[4];
    Hotel* hotel;

public:
    Miasto(std::string n, int c, int* cz) : PoleNieruchomosc(n, c, cz[0]), cena(c), ileDom(0), ileHotel(0)
        {
            for(int i = 0; i < 6; i++) czynsz[i] = cz[i];
        }
    ~Miasto() = default;

    friend class Bankier;
};

class Uzytek : public PoleNieruchomosc {
public:
    Uzytek(std::string n, int k, int w) : PoleNieruchomosc(n, k, w) {}
    friend class Bankier;
};

class Dworzec : public PoleNieruchomosc {
public:
    Dworzec(std::string n, int k, int w) : PoleNieruchomosc(n, k, w) {}
    friend class Bankier;
};

class Plansza {
private:
    std::vector<Pole*> pola;
    std::vector<Gracz*> gracze;
    std::vector<KartaSzansy*> kartySzans;
    std::vector<KasaSpoleczna*> kartySpoleczne;
    std::vector<Uzytek*> uzytki;
    std::vector<Dworzec*> dworce;
    DarmowyParking* parking;
    KartaSzansy* szansaPole;
    KasaSpoleczna* spolecznaPole;
    std::vector<Dom*> domy;
    std::vector<Hotel*> hotele;

public:
    const std::vector<Pole*>& getPola() const { return pola; }
    const std::vector<Gracz*>& getGracze() const { return gracze; }
    const std::vector<KartaSzansy*>& getKartySzans() const { return kartySzans; }
    const std::vector<KasaSpoleczna*>& getKartySpoleczne() const { return kartySpoleczne; }
    const std::vector<Uzytek*>& getUzytki() const { return uzytki; }
    const std::vector<Dworzec*>& getDworce() const { return dworce; }
    DarmowyParking* getParking() const { return parking; }
    KartaSzansy* getSzansaPole() const { return szansaPole; }
    KasaSpoleczna* getSpolecznaPole() const { return spolecznaPole; }
    const std::vector<Dom*>& getDomy() const { return domy; }
    const std::vector<Hotel*>& getHotele() const { return hotele; }

    Plansza() : parking(nullptr), szansaPole(nullptr), spolecznaPole(nullptr) {}
    ~Plansza() = default;
};

class Karta {
public:
    std::string opis;
    int efekt;
    bool kartaWyjdzWiezienie;
    bool kartaDoStart;
    int gotowkaIle;
    int przesunIle;
    Karta(std::string o, int e, bool kw, bool ks, int gi, int pi)
        : opis(o), efekt(e), kartaWyjdzWiezienie(kw), kartaDoStart(ks), 
          gotowkaIle(gi), przesunIle(pi) {}
};

class KartaSzansy : public Karta {
public:
    KartaSzansy(std::string o, int e, bool kw, bool ks, int gi, int pi)
        : Karta(o, e, kw, ks, gi, pi) {}
};

class KasaSpoleczna : public Karta {
public:
    bool zabierzPieniadze;
    bool dajPieniadze;
    KasaSpoleczna(std::string o, int e, bool kw, bool ks, int gi, int pi, bool zp, bool dp)
        : Karta(o, e, kw, ks, gi, pi), zabierzPieniadze(zp), dajPieniadze(dp) {}
};

class Kosc {
public:
    bool koscRzucona;
    int wynikRzutu;
    int ileRuchu;

    Kosc() : koscRzucona(false), wynikRzutu(0), ileRuchu(0) {}

    int rzuc() {
        koscRzucona = true;
        wynikRzutu = (rand() % 6) + 1;
        ileRuchu = wynikRzutu;
        return wynikRzutu;
    }
};
class Bankier {
private:
    int sumaPieniadze;
    std::vector<Miasto*> nieruchomosci;
    std::vector<Gracz*> graczePozyczka;

public:
    Bankier(int sp) : sumaPieniadze(sp) {}
    ~Bankier() = default;

    void dodajPieniadze(Gracz& gracz, int kwota) {
        gracz.pieniadze += kwota;
    }

    void zabierzPieniadze(Gracz& gracz, int kwota) {
        gracz.pieniadze -= kwota;
    }

    void ustawWlasciciela(Pole& pole, Gracz* gracz) {
        pole.owner = gracz;
    }
};

class Wiezienie {
private:
    int oplataWiezienie;
    std::vector<Gracz*> wiezniowie;

public:
    Wiezienie(int ow) : oplataWiezienie(ow) {}
    ~Wiezienie() = default;

    void dodajGracza(Gracz* gracz) {
        wiezniowie.push_back(gracz);
        gracz->wWiezieniu = true;
    }

    void zwolnijGracza(Gracz* gracz) {
        gracz->wWiezieniu = false;
        wiezniowie.erase(std::remove(wiezniowie.begin(), wiezniowie.end(), gracz), wiezniowie.end());
    }
};

class Podatek : public Pole {
public:
    int kwotaPodatek;
    Podatek(std::string n, int kp) : Pole(n), kwotaPodatek(kp) {}
};

class PoleStart : public Pole {
public:
    int premiaStart;
    PoleStart(std::string n, int ps) : Pole(n), premiaStart(ps) {}
};

class DarmowyParking : public Pole {
public:
    std::vector<Gracz*> gracze;
    int loteria;
    DarmowyParking(std::string n) : Pole(n), loteria(0) {}
};

class Dom : public PoleNieruchomosc {
public:
    Dom(std::string n, int k, int w) : PoleNieruchomosc(n, k, w) {}
};

class Hotel : public PoleNieruchomosc {
public:
    Hotel(std::string n, int k, int w) : PoleNieruchomosc(n, k, w) {}
};

void Gracz::przesun(int ruchy, int liczbaPol) {
    pozycja = (pozycja + ruchy) % liczbaPol;
}

int main() {
    srand(time(NULL));
    int liczbaPol = 40;
    Gracz Grzegorz("Grzegorz", 1500);
    Gracz Janusz("Janusz", 1500);
    Kosc kosc;
    Bankier bankier(10000);
    bankier.dodajPieniadze(Grzegorz, 500);
    bankier.dodajPieniadze(Janusz, 500);

    for (int i = 0; i < 3; i++) {
        int wynikRzutuGrzegorz = kosc.rzuc();
        std::cout << "Wynik Rzutu Grzegorz: " << wynikRzutuGrzegorz << std::endl;
        Grzegorz.przesun(wynikRzutuGrzegorz, liczbaPol);

        int wynikRzutuJanusz = kosc.rzuc();
        std::cout << "Wynik Rzutu Janusz: " << wynikRzutuJanusz << std::endl;
        Janusz.przesun(wynikRzutuJanusz, liczbaPol);
    }

    std::cout << "Pozycja Grzegorz: " << Grzegorz.pozycja << std::endl;
    std::cout << "Pieniadze Grzegorz: " << Grzegorz.pieniadze << std::endl;
    std::cout << "Pozycja Janusz: " << Janusz.pozycja << std::endl;
    std::cout << "Pieniadze Janusz: " << Janusz.pieniadze << std::endl;

    return 0;
}
