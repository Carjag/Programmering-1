// Detta ska vara ett program som likt �vningsprovet innefattar stora m�ngder av det som kommer p� framtida programmeringsprov. 
// Viktiga delar �r variabler, operatorer, selektion, loopar, funktioner, arrayer och structer.
// Andra viktiga delar innefattar referensparameter, typer av funktioner bl.a.

#include <iostream>
using namespace std;

struct Glass {

	string Gsmak;
	string Gstrut;
	string Gkulor;

}; // H�r hade man redan nu kunnat skapa structer, men eftersom att vi vill att individen som k�r programmet sj�lv ska f� g�ra detta, s� v�ntar vi med att initialisera structer. 

void sokSmak(Glass g[], int antal);
void sokStrut(Glass g[], int antal);
void sokKulor(Glass g[], int antal); 
void meny(Glass g[], int antal);
void resultat(Glass g[], int i);

int main() {

	system("chcp 1252"); // Anv�nder vokalerna �, � och �.

	Glass minaGlassar[5]; // Skapar en array som en struct, som max kan inneh�lla 5 olika element. (3 * 5 = 15 olika val p� smak, strut och kulor tillsammans).
	int antal = 0;
	cout << "Hur m�nga olika glassar vill du ha i din struct?" << endl;
	cout << "(5 glassar f�r plats) - : ";
	cin >> antal;

	for (int i = 0; i < antal; i++) { // loop som k�rs (antal) g�nger d�r man f�r l�gga in olika val beroende p� hur m�nga glassar man vill skapa. 
		cout << "Vilken smak ska glass nr " << i + 1 << " ha? : ";
		cin >> minaGlassar[i].Gsmak; // Skriver in en struct med namnet minaGlassar[i], d�r i g�r fr�n 0 < antal (l�gger p� 1 f�r att den inte ska starta fr�n 0 i programmet).
		cout << "Vad vill du ha glass nr " << i + 1 << " i? : ";
		cin >> minaGlassar[i].Gstrut;
		cout << "Hur m�nga kulor ska glass nr " << i + 1 << " ha? : ";
		cin >> minaGlassar[i].Gkulor;
	}
	meny(minaGlassar, antal); // Skickar Arrayerna och antalet arrayer till funktionen meny. 

	return 0;
}

void meny(Glass g[], int antal) { // Skriver endast Glass g[], beh�ver inte skriva [struct] f�re Glass. 

	char val; //Anv�nder char f�r att variabeln sparar en enskild bokstav, vilket vi i detta fall anv�nder oss av. (Med ASCII).
	cout << "\nV�lkommen till menyn! H�r kan du s�ka p� glassarna du har skapat !" << endl;
	cout << "S�k Glass!" << endl;
	cout << "Vill du s�ka p� Smak, v�lj [s]" << endl;
	cout << "Vill du s�ka p� variant av strut, v�lj [t]" << endl;
	cout << "vill du s�ka p� antal kulor, v�lj [k]" << endl;
	cout << " --> : ";

	cin >> val;

	switch (val) { // En typ av selektion d�r ett uttryck utv�rderas och j�mf�rs med olika scenarion. Om ett scenario st�mmer, s� k�rs koden under.
	case 's':
		sokSmak(g, antal);
		break; // anv�nds f�r att ignorera resten av koden i switch-blocket om det f�rsta utfallet var det s�kta. 
	case 't':
		sokStrut(g, antal);
		break;
	case 'k':
		sokKulor(g, antal);
		break;
	default:
		cout << "Ogiltigt val!" << endl;

		meny(g, antal);

	}

}

void sokSmak(Glass g[], int antal) { // Funktion som hanterar s�kandet av smak. Anv�nder arrayen minaGlassar som skickas till meny fr�n main funktionen.

	string sok;
	cout << "S�k p� Smak: ";
	cin >> sok;

	int i = 0;
	while (i < antal) {
		if (sok == g[i].Gsmak) { // S�ker p� om string sok �r samma som Gsmak f�r en av de tidigare valda glassarna.
			resultat(g, i);
			meny(g, antal);
		}

		i++;
	}
	cout << "Den s�kta glassen hittas inte." << endl;

	meny(g, antal);
}

void sokStrut(Glass g[], int antal) { // Samma funktion f�r variant av beh�llare / b�gare ...

	string sok;
	cout << "S�k p� variant av beh�llare: ";
	cin >> sok;

	int i = 0;
	while (i < antal) {
		if (sok == g[i].Gstrut) {
			resultat(g, i);
			meny(g, antal);
		}

		i++;
	}
	cout << "Den s�kta glassen hittas inte." << endl;

	meny(g, antal);
}

void sokKulor(Glass g[], int antal) { // Samma funktion fast f�r antal kulor. 

	string sok;
	cout << "S�k p� antal kulor: ";
	cin >> sok;

	int i = 0;
	while (i < antal) {
		if (sok == g[i].Gkulor) {
			resultat(g, i);
			meny(g, antal);
		}

		i++;
	}
	cout << "Den s�kta glassen hittas inte." << endl;

	meny(g, antal);
}

void resultat(Glass g[], int i) { // Funktion som skriver ut den s�kta glassen, beroende p� vilken som tidigare hittades i if satserna f�r de tre olika valen. 
	// D�refter skickas arrayen g (som fr�n b�rjan �r minaGlassar) samt variabeln i som har v�rdet av det som if-satsen fann sant. 
	// P� s� vis skrivs bara de korrekta v�rdena nu i konsolen.

	cout << "\nDen s�kta glassen �r: " << endl;
	cout << "Smak: " << g[i].Gsmak << endl;
	cout << "Beh�llare: " << g[i].Gstrut << endl;
	cout << "Antal kulor: " << g[i].Gkulor << endl;

}