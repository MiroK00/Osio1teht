#include <iostream>

using namespace std;

const int Max_Height = 100;
const int Max_Width = 50;


void kolmio(int kolmiokorkeus, char tahdet[Max_Height][Max_Width])
{
	//Alustetaan taulukko

	for (int i = 0; i < Max_Height; i++)
	{
		for (int j = 0; j < Max_Width; j++)
		{
			tahdet[i][j] = ' ';
		}
	}
	//Tulostetaan kolmion yläosa
	for (int i = 0; i < kolmiokorkeus; i++)
	{
		for (int j = 0; j < kolmiokorkeus; j++)
		{
			tahdet[i][j] = (j < kolmiokorkeus - 1 - i ? ' ' : '*');
		}
		tahdet[i][kolmiokorkeus] = '\0';
	}
	tahdet[kolmiokorkeus][0] = '\0';

	//Tulostetaan kolmion alaosa
	for (int i = 0; i < kolmiokorkeus - 1; i++)
	{
		for (int j = 0; j < kolmiokorkeus; j++)
		{
			tahdet[kolmiokorkeus + i][j] = (j > i ? '*' : ' ');
		}
		tahdet[kolmiokorkeus + i][kolmiokorkeus] = '\0';
	}

	//ilmaistaan kolmion päätös
	tahdet[kolmiokorkeus * 2 - 1][0] = '\0';
}

//Tulostetaan tähtimuodostelma
void print(char tahdet[Max_Height][Max_Width])
{

	for (int i = 0; i < Max_Height; i++)
	{
		cout << tahdet[i] << "\n";
		if (tahdet[i][0] == '\0')
		{
			break;
		}
	}
}

//Kysytään käyttäjältä kolmion korkeus ja kutsutaan muita metodeja

int main()
{
	int juu;
	int kolmiokorkeus;
	cout << "Anna kolmion korkeus: ";
	cin >> kolmiokorkeus;

	char pyramidi[Max_Height][Max_Width];

	kolmio(kolmiokorkeus, pyramidi);
	print(pyramidi);

	return 0;
}