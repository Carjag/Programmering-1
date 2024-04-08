#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <random>

using namespace std;

int getRandomNumber() {

	 // Använder random device för att seeda Mersenne Twister engine
	random_device rd;
	mt19937 mt(rd());

	// Genererar ett random nummer mellan 1 och 10
	uniform_int_distribution<int> distribution(1, 10);
	int randomNumber = distribution(mt);

	return randomNumber;
}

void printMessage(string message) { // Skickar meddelandet till konsolen

	cout << message;

}

int calculateSum(int num1, int num2) { // adderar variablerna num1 & num2

	return num1 + num2;

}

void swapNumbers(int &num1, int &num2) { // byter referensvariablernas värde

	swap(num1, num2);

}

double calculateAverage(int arr[], int size) { // kalkylerar medelvärdet genom att addera värdena i arrayen och dela dessa med storleken. 

	int i, sum = 0;

	for (i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return double(sum) / size;

}

void reversearray(int arr[], int size) {

	for (int i = 0; i < size / 2; i++) // Byter ordningen på arrayen med en loop och funktionen swap. 
		swap(arr[i], arr[size - i - 1]);
}

int main() {

	string name = "Calle";
	string message = name + " is learning C++ functions, loops, and more!\n";
	printMessage(message); // skickar meddelandet till printMessage som skriver ut det

	int num1 = getRandomNumber(); // genererar 1 random siffra
	cout << num1 << "\n";
	int num2 = getRandomNumber(); // genererar ytterligare en random siffra
	cout << num2 << "\n";	

	int total = calculateSum(num1, num2);
	cout << total << "\n"; // Skriver ut summan av de två talen num1 och num2

	for (int i = 0; i < 10; i++) { // Loop med random nummer och antal iterationer av denna.
		
		int num3 = getRandomNumber();
		cout << num3 << " Iteration: " << (i + 1) << "\n";

	}

	int myNumbers[5];
	cout << "Your initial array is: "; // Randomiserar 5 nummer som läggs in i arrayen då i ökar med 1 varje gång ett nummer lagts till.
	for (int i = 0; i < 5; i++) {

		myNumbers[i] = getRandomNumber();
		cout << myNumbers[i] << " ";
	}

	double Average = calculateAverage(myNumbers, 5); // skickar arrayen och antal nummer inkluderat till calculateAverage som räknar ut medelvärdet av siffrorna.
	cout << "\nYour average is: " << Average;

	cout << "\nThe reversed array is: "; // Skickar arrayen och storleken till funktionen reversearray som byter ordning på alla siffror. 
	reversearray(myNumbers, 5);
	for (int i = 0; i < 5; i++) {
		cout << myNumbers[i] << " ";
	}

	cout << "\nThe swapped array (compared to the reversed) is: "; // Skickar två nummer från arrayen till swapNumbers funktionen som byter dessa. 
	swapNumbers(myNumbers[2], myNumbers[4]);
	for (int i = 0; i < 5; i++) {
		cout << myNumbers[i] << " "; // Skriver den nya arrayen till konsolen.
	}
	cout << "\nComplex loop with function calls: "; // Genererar random nummer som adderas till summan överstiger eller är 100. 
	int i = 0;
	while (i < 100) {
		i += getRandomNumber();
		cout << i << " ";
	}
	string limit = "Limit reached"; // Skickar meddelandet till funktionen printMessage som skriver det till konsolen.
	printMessage(limit);

}