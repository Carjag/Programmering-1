// Detta ska vara ett program som likt övningsprovet innefattar stora mängder av det som kommer på framtida programmeringsprov. 
// Viktiga delar är variabler, operatorer, selektion, loopar, funktioner, arrayer och structer.
// Andra viktiga delar innefattar referensparameter, typer av funktioner bl.a.

#include <iostream>
using namespace std;

struct Glass {

	string Gsmak;
	string Gstrut;
	string Gkulor;

}; // Här hade man redan nu kunnat skapa structer, men eftersom att vi vill att individen som kör programmet själv ska få göra detta, så väntar vi med att initialisera structer. 

void sokSmak(Glass g[], int antal);
void sokStrut(Glass g[], int antal);
void sokKulor(Glass g[], int antal); 
void meny(Glass g[], int antal);
void resultat(Glass g[], int i);

int main() {

	system("chcp 1252"); // Använder vokalerna å, ä och ö.

	Glass minaGlassar[5]; // Skapar en array som en struct, som max kan innehålla 5 olika element. (3 * 5 = 15 olika val på smak, strut och kulor tillsammans).
	int antal = 0;
	cout << "Hur många olika glassar vill du ha i din struct?" << endl;
	cout << "(5 glassar får plats) - : ";
	cin >> antal;

	for (int i = 0; i < antal; i++) { // loop som körs (antal) gånger där man får lägga in olika val beroende på hur många glassar man vill skapa. 
		cout << "Vilken smak ska glass nr " << i + 1 << " ha? : ";
		cin >> minaGlassar[i].Gsmak; // Skriver in en struct med namnet minaGlassar[i], där i går från 0 < antal (lägger på 1 för att den inte ska starta från 0 i programmet).
		cout << "Vad vill du ha glass nr " << i + 1 << " i? : ";
		cin >> minaGlassar[i].Gstrut;
		cout << "Hur många kulor ska glass nr " << i + 1 << " ha? : ";
		cin >> minaGlassar[i].Gkulor;
	}
	meny(minaGlassar, antal); // Skickar Arrayerna och antalet arrayer till funktionen meny. 

	return 0;
}

void meny(Glass g[], int antal) { // Skriver endast Glass g[], behöver inte skriva [struct] före Glass. 

	char val; //Använder char för att variabeln sparar en enskild bokstav, vilket vi i detta fall använder oss av. (Med ASCII).
	cout << "\nVälkommen till menyn! Här kan du söka på glassarna du har skapat !" << endl;
	cout << "Sök Glass!" << endl;
	cout << "Vill du söka på Smak, välj [s]" << endl;
	cout << "Vill du söka på variant av strut, välj [t]" << endl;
	cout << "vill du söka på antal kulor, välj [k]" << endl;
	cout << " --> : ";

	cin >> val;

	switch (val) { // En typ av selektion där ett uttryck utvärderas och jämförs med olika scenarion. Om ett scenario stämmer, så körs koden under.
	case 's':
		sokSmak(g, antal);
		break; // används för att ignorera resten av koden i switch-blocket om det första utfallet var det sökta. 
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

void sokSmak(Glass g[], int antal) { // Funktion som hanterar sökandet av smak. Använder arrayen minaGlassar som skickas till meny från main funktionen.

	string sok;
	cout << "Sök på Smak: ";
	cin >> sok;

	int i = 0;
	while (i < antal) {
		if (sok == g[i].Gsmak) { // Söker på om string sok är samma som Gsmak för en av de tidigare valda glassarna.
			resultat(g, i);
			meny(g, antal);
		}

		i++;
	}
	cout << "Den sökta glassen hittas inte." << endl;

	meny(g, antal);
}

void sokStrut(Glass g[], int antal) { // Samma funktion för variant av behållare / bägare ...

	string sok;
	cout << "Sök på variant av behållare: ";
	cin >> sok;

	int i = 0;
	while (i < antal) {
		if (sok == g[i].Gstrut) {
			resultat(g, i);
			meny(g, antal);
		}

		i++;
	}
	cout << "Den sökta glassen hittas inte." << endl;

	meny(g, antal);
}

void sokKulor(Glass g[], int antal) { // Samma funktion fast för antal kulor. 

	string sok;
	cout << "Sök på antal kulor: ";
	cin >> sok;

	int i = 0;
	while (i < antal) {
		if (sok == g[i].Gkulor) {
			resultat(g, i);
			meny(g, antal);
		}

		i++;
	}
	cout << "Den sökta glassen hittas inte." << endl;

	meny(g, antal);
}

void resultat(Glass g[], int i) { // Funktion som skriver ut den sökta glassen, beroende på vilken som tidigare hittades i if satserna för de tre olika valen. 
	// Därefter skickas arrayen g (som från början är minaGlassar) samt variabeln i som har värdet av det som if-satsen fann sant. 
	// På så vis skrivs bara de korrekta värdena nu i konsolen.

	cout << "\nDen sökta glassen är: " << endl;
	cout << "Smak: " << g[i].Gsmak << endl;
	cout << "Behållare: " << g[i].Gstrut << endl;
	cout << "Antal kulor: " << g[i].Gkulor << endl;

}