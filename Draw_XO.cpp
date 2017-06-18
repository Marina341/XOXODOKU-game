/*
Igrica: XOXODOKU,
Potrebno je osvojiti tri krizic kruzica za pobjedu u cjelokupnoj igri (po principu:|-\/). 
Nakon sto je jedan krizic kruzic osvojen neispunjena polja postaju '-' ali igrac jos uvijek 
u njih moze unosit svoj znak. Za vrijeme igre se moze unositi znak u bilo koje od 81 polja, 
bez obzira je li prosli krizic kruzic rjesen (osim ako je polje vec zauzeto).
Potrebno je prvo odabrati krizic kruzic po redosljedu:
1 2 3
4 5 6
7 8 9
i nakon toga polje u krizic kruzicu
Zabava zagarantirana :)
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

//deklaracije varijabli izvan main-a, one koje ce se koristiti u vise funkcija
char matrix[9] = {};
char matrix1[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char matrix2[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char matrix3[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char matrix4[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char matrix5[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char matrix6[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char matrix7[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char matrix8[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char matrix9[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0;
int x = 1;
char player = 'X';
char z = (char)176;

//Ispis:
void DrawFirstLine(char matrix[9])
{
	for (int i = 0; i < 3; i++)
	{
		cout << matrix[i] << " ";
	}
}
void DrawSecondLine(char matrix[9])
{
	for (int i = 3; i < 6; i++)
	{
		cout << matrix[i] << " ";
	}
}
void DrawThirdLine(char matrix[9])
{
	for (int i = 6; i < 9; i++)
	{
		cout << matrix[i] << " ";
	}
}
void Draw() {
	cout << endl;
	cout << "   " << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << endl;
	cout << "   " << z << z << z << z << z << z << z << z << z << "XOXODOKU!" << z << z << z << z << z << z << z << z << endl;
	cout << "   " << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << z << endl;
	cout << "    ";
	DrawFirstLine(matrix1);
	cout << " | ";
	DrawFirstLine(matrix2);
	cout << " | ";
	DrawFirstLine(matrix3);
	cout << endl;
	cout << "    ";
	DrawSecondLine(matrix1);
	cout << " | ";
	DrawSecondLine(matrix2);
	cout << " | ";
	DrawSecondLine(matrix3);
	cout << endl;
	cout << "    ";
	DrawThirdLine(matrix1);
	cout << " | ";
	DrawThirdLine(matrix2);
	cout << " | ";
	DrawThirdLine(matrix3);
	cout << endl << "   ------------------------- \n";
	cout << "    ";
	DrawFirstLine(matrix4);
	cout << " | ";
	DrawFirstLine(matrix5);
	cout << " | ";
	DrawFirstLine(matrix6);
	cout << endl;
	cout << "    ";
	DrawSecondLine(matrix4);
	cout << " | ";
	DrawSecondLine(matrix5);
	cout << " | ";
	DrawSecondLine(matrix6);
	cout << endl;
	cout << "    ";
	DrawThirdLine(matrix4);
	cout << " | ";
	DrawThirdLine(matrix5);
	cout << " | ";
	DrawThirdLine(matrix6);
	cout << endl << "   ------------------------- \n";
	cout << "    ";
	DrawFirstLine(matrix7);
	cout << " | ";
	DrawFirstLine(matrix8);
	cout << " | ";
	DrawFirstLine(matrix9);
	cout << endl;
	cout << "    ";
	DrawSecondLine(matrix7);
	cout << " | ";
	DrawSecondLine(matrix8);
	cout << " | ";
	DrawSecondLine(matrix9);
	cout << endl;
	cout << "    ";
	DrawThirdLine(matrix7);
	cout << " | ";
	DrawThirdLine(matrix8);
	cout << " | ";
	DrawThirdLine(matrix9);
	cout << endl;
}

//Izmjena igraca:
void TogglePlayer()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}
//Upis u polje
void Input(char matrix[9], int field) {
	for (int i = 0; i < 9; i++) {
		if ((i+1) == field) {
			if (matrix[i] != 'X' && matrix[i] != 'O' && matrix[i] != '-') {
				matrix[i] = player;
			}
			else {
				cout << "Polje je zautezo, igrajte ponovno!" << endl;
				system("pause");
				TogglePlayer();
				break;
			}
		}
	}
}
//'-'
void OneWinX(char matrix[9]) {
	for (int i = 0; i < 9; i++) {
		if (matrix[i] != 'X' && matrix[i] != 'O') {
			matrix[i] = '-';
		}
	}
}
void OneWinO(char matrix[9]) {
	for (int i = 0; i < 9; i++) {
		if (matrix[i] != 'X' && matrix[i] != 'O') {
			matrix[i] = '-';
		}
	}
}
//Funkcije koje vracaju X ili O ako je jedan krizic kruzic osvojen
char WinOne_X(char matrix[9])
{
	if (matrix[0] == 'X' && matrix[1] == 'X' && matrix[2] == 'X') {
		OneWinX(matrix);
		return 'X';
	}
	if (matrix[3] == 'X' && matrix[4] == 'X' && matrix[5] == 'X') {
		OneWinX(matrix);
		return 'X';
	}
	if (matrix[6] == 'X' && matrix[7] == 'X' && matrix[8] == 'X') {
		OneWinX(matrix);
		return 'X';
	}
	if (matrix[0] == 'X' && matrix[3] == 'X' && matrix[6] == 'X') {
		OneWinX(matrix);
		return 'X';
	}
	if (matrix[1] == 'X' && matrix[4] == 'X' && matrix[7] == 'X') {
		OneWinX(matrix);
		return 'X';
	}
	if (matrix[2] == 'X' && matrix[5] == 'X' && matrix[8] == 'X') {
		OneWinX(matrix);
		return 'X';
	}
	if (matrix[0] == 'X' && matrix[4] == 'X' && matrix[8] == 'X') {
		OneWinX(matrix);
		return 'X';
	}
	if (matrix[2] == 'X' && matrix[4] == 'X' && matrix[6] == 'X') {
		OneWinX(matrix);
		return 'X';
	}

	return '/';
}
char WinOneO(char matrix[9]){
	if (matrix[0] == 'O' && matrix[1] == 'O' && matrix[2] == 'O') {
		OneWinO(matrix);
		return 'O';
	}
	if (matrix[3] == 'O' && matrix[4] == 'O' && matrix[5] == 'O') {
		OneWinO(matrix);
		return 'O';
	}
	if (matrix[6] == 'O' && matrix[7] == 'O' && matrix[8] == 'O') {
		OneWinO(matrix);
		return 'O';
	}
	if (matrix[0] == 'O' && matrix[3] == 'O' && matrix[6] == 'O') {
		OneWinO(matrix);
		return 'O';
	}
	if (matrix[1] == 'O' && matrix[4] == 'O' && matrix[7] == 'O') {
		OneWinO(matrix);
		return 'O';
	}
	if (matrix[2] == 'O' && matrix[5] == 'O' && matrix[8] == 'O') {
		OneWinO(matrix);
		return 'O';
	}
	if (matrix[0] == 'O' && matrix[4] == 'O' && matrix[8] == 'O') {
		OneWinO(matrix);
		return 'O';
	}
	if (matrix[2] == 'O' && matrix[4] == 'O' && matrix[6] == 'O') {
		OneWinO(matrix);
		return 'O';
	}
	return '/';
}
void Win_One_xo() {
	WinOne_X(matrix1);
	WinOne_X(matrix2);
	WinOne_X(matrix3);
	WinOne_X(matrix4);
	WinOne_X(matrix5);
	WinOne_X(matrix6);
	WinOne_X(matrix7);
	WinOne_X(matrix8);
	WinOne_X(matrix9);
	WinOneO(matrix1);
	WinOneO(matrix2);
	WinOneO(matrix3);
	WinOneO(matrix4);
	WinOneO(matrix5);
	WinOneO(matrix6);
	WinOneO(matrix7);
	WinOneO(matrix8);
	WinOneO(matrix9);
}
//Funkcije sa cout ukoliko je krizic kruzic osvojen ili je nerjeseno
void IfWin() {
	if (WinOne_X(matrix1) == 'X') {
		cout << z << z << z << "X je pobijedio u prvom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOne_X(matrix2) == 'X') {
		cout << z << z << z << "X je pobijedio u drugom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOne_X(matrix3) == 'X') {
		cout << z << z << z << "X je pobijedio u trecem krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOne_X(matrix4) == 'X') {
		cout << z << z << z << "X je pobijedio u cetvrtom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOne_X(matrix5) == 'X') {
		cout << z << z << z << "X je pobijedio u petom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOne_X(matrix6) == 'X') {
		cout << z << z << z << "X je pobijedio u sestom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOne_X(matrix7) == 'X') {
		cout << z << z << z << "X je pobijedio u sedmom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOne_X(matrix8) == 'X') {
		cout << z << z << z << "X je pobijedio u osmom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOne_X(matrix9) == 'X') {
		cout << z << z << z << "X je pobijedio u devetom krizic kruzicu!" << z << z << z << endl;
	}
	//'O'
	if (WinOneO(matrix1) == 'O') {
		cout << z << z << z << "O je pobijedio u prvom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOneO(matrix2) == 'O') {
		cout << z << z << z << "O je pobijedio u drugom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOneO(matrix3) == 'O') {
		cout << z << z << z << "O je pobijedio u trecem krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOneO(matrix4) == 'O') {
		cout << z << z << z << "O je pobijedio u cetvrtom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOneO(matrix5) == 'O') {
		cout << z << z << z << "O je pobijedio u petom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOneO(matrix6) == 'O') {
		cout << z << z << z << "O je pobijedio u sestom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOneO(matrix7) == 'O') {
		cout << z << z << z << "O je pobijedio u sedmom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOneO(matrix8) == 'O') {
		cout << z << z << z << "O je pobijedio u osmom krizic kruzicu!" << z << z << z << endl;
	}
	if (WinOneO(matrix9) == 'O') {
		cout << z << z << z << "O je pobijedio u devetom krizic kruzicu!" << z << z << z << endl;
	}
}
void nerijeseno() {
	if (num1 == 9 && WinOne_X(matrix1) != 'X' && WinOne_X(matrix1) != 'O') {
		cout << z << z << z << "Nerijeseno je u prvom krizic kruzicu!" << z << z << z << endl;
	}
	if (num2 == 9 && WinOne_X(matrix2) != 'X' && WinOne_X(matrix2) != 'O') {
		cout << z << z << z << "Nerijeseno je u drugom krizic kruzicu!" << z << z << z << endl;
	}
	if (num3 == 9 && WinOne_X(matrix3) != 'X' && WinOne_X(matrix3) != 'O') {
		cout << z << z << z << "Nerijeseno je u trecem krizic kruzicu!" << z << z << z << endl;
	}
	if (num4 == 9 && WinOne_X(matrix4) != 'X' && WinOne_X(matrix4) != 'O') {
		cout << z << z << z << "Nerijeseno je u cetvrtom krizic kruzicu!" << z << z << z << endl;
	}
	if (num5 == 9 && WinOne_X(matrix5) != 'X' && WinOne_X(matrix5) != 'O') {
		cout << z << z << z << "Nerijeseno je u petom krizic kruzicu!" << z << z << z << endl;
	}
	if (num6 == 9 && WinOne_X(matrix6) != 'X' && WinOne_X(matrix6) != 'O') {
		cout << z << z << z << "Nerijeseno je u sestom krizic kruzicu!" << z << z << z << endl;
	}
	if (num7 == 9 && WinOne_X(matrix7) != 'X' && WinOne_X(matrix7) != 'O') {
		cout << z << z << z << "Nerijeseno je u sedmom krizic kruzicu!" << z << z << z << endl;
	}
	if (num8 == 9 && WinOne_X(matrix8) != 'X' && WinOne_X(matrix8) != 'O') {
		cout << z << z << z << "Nerijeseno je u osmom krizic kruzicu!" << z << z << z << endl;
	}
	if (num9 == 9 && WinOne_X(matrix9) != 'X' && WinOne_X(matrix9) != 'O') {
		cout << z << z << z << "Nerijeseno je u devetom krizic kruzicu!" << z << z << z << endl;
	}
}
//Provjera je li cjelokupni krizic kruzic osvojen
void UltimateWin() {
	int y = 0;
	do {
		if (WinOne_X(matrix1) == 'X' && WinOne_X(matrix2) == 'X' && WinOne_X(matrix3) == 'X')
		{
			cout << "X je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOne_X(matrix4) == 'X' && WinOne_X(matrix5) == 'X' && WinOne_X(matrix6) == 'X')
		{
			cout << "X je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOne_X(matrix7) == 'X' && WinOne_X(matrix8) == 'X' && WinOne_X(matrix9) == 'X')
		{
			cout << "X je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		if (WinOne_X(matrix1) == 'X' && WinOne_X(matrix4) == 'X' && WinOne_X(matrix7) == 'X')
		{
			cout << "X je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOne_X(matrix2) == 'X' && WinOne_X(matrix5) == 'X' && WinOne_X(matrix8) == 'X')
		{
			cout << "X wins!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOne_X(matrix3) == 'X' && WinOne_X(matrix6) == 'X' && WinOne_X(matrix9) == 'X')
		{
			cout << "X je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOne_X(matrix1) == 'X' && WinOne_X(matrix5) == 'X' && WinOne_X(matrix9) == 'X')
		{
			cout << "X je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOne_X(matrix3) == 'X' && WinOne_X(matrix5) == 'X' && WinOne_X(matrix7) == 'X')
		{
			cout << "X je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		//O
		if (WinOneO(matrix1) == 'O' && WinOneO(matrix2) == 'O' && WinOneO(matrix3) == 'O')
		{
			cout << "O je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOneO(matrix4) == 'O' && WinOneO(matrix5) == 'O' && WinOneO(matrix6) == 'O')
		{
			cout << "O je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOneO(matrix7) == 'O' && WinOneO(matrix8) == 'O' && WinOneO(matrix9) == 'O')
		{
			cout << "O je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}	
		if (WinOneO(matrix1) == 'O' && WinOneO(matrix4) == 'O' && WinOneO(matrix7) == 'O')
		{
			cout << "O je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOneO(matrix2) == 'O' && WinOneO(matrix5) == 'O' && WinOneO(matrix8) == 'O')
		{
			cout << "O je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOneO(matrix3) == 'O' && WinOneO(matrix6) == 'O' && WinOneO(matrix9) == 'O')
		{
			cout << "O je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOneO(matrix1) == 'O' && WinOneO(matrix5) == 'O' && WinOneO(matrix9) == 'O')
		{
			cout << "O je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		else if (WinOneO(matrix3) == 'O' && WinOneO(matrix5) == 'O' && WinOneO(matrix7) == 'O')
		{
			cout << "O je pobijedio!" << endl;
			x = 2;
			Draw();
			break;
		}
		y++;
	} while (y != 1);
}

int main()
	{
	do {
		IfWin();
		nerijeseno();
		Draw();
		cout << endl;
		cout << "  Izaberite redosljed krizic kruzica!" << endl;
		int matrix_num, field;
		cin >> matrix_num;
		if (matrix_num == 1) {
			num1++;
		}
		else if (matrix_num == 2) {
			num2++;
		}
		else if (matrix_num == 3) {
			num3++;
		}
		else if (matrix_num == 4) {
			num4++;
		}
		else if (matrix_num == 5) {
			num5++;
		}
		else if (matrix_num == 6) {
			num6++;
		}
		else if (matrix_num == 7) {
			num7++;
		}
		else if (matrix_num == 8) {
			num8++;
		}
		else if (matrix_num == 9) {
			num9++;
		}
		cout << endl;
		cout << "  Izaberite polje u odabranom krizic kruzicu!" << endl;
		cin >> field;
		if (matrix_num == 1) {
			Input(matrix1, field);
		}
		else if (matrix_num == 2) {
			Input(matrix2, field);
		}
		else if (matrix_num == 3) {
			Input(matrix3, field);
		}
		else if (matrix_num == 4) {
			Input(matrix4, field);
		}
		else if (matrix_num == 5) {
			Input(matrix5, field);
		}
		else if (matrix_num == 6) {
			Input(matrix6, field);
		}
		else if (matrix_num == 7) {
			Input(matrix7, field);
		}
		else if (matrix_num == 8) {
			Input(matrix8, field);;
		}
		else if (matrix_num == 9) {
			Input(matrix9, field);
		}
		system("cls");
		TogglePlayer();
		UltimateWin();
	} while (x == 1);

		system("pause");
		return 0;
	}