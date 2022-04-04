#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_TRIES = 5;
int letterFill(char, string, string&);

int main()
{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] = {
		"charmander",
		"squirtle",
		"bulbasaur",
		"cyndaquil",
		"totodile",
		"chicorita",
		"torchic",
		"mudkip",
		"treeco"
	};

		//choose and copy a word from the array of words randomly
	srand(time(NULL));
	int n = rand() % 9;
	word = words[n];	//fill strong word with a random pokemon

	//Initialize the secret word with the * character.
	string unknown(word.length(), '*');

	// UI
	cout << "Hangman (Pokemon Starters)\n";

	//Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "Guess a letter: ";
		cin >> letter;
		//Fill secret word with letter if the guess is correct,
		//otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown) == 0)
		{
			cout << "\nOof! Wrong letter!\n";
			num_of_wrong_guesses++;
		}
		else
		{
			cout << "\nNice! You found one! \n";
		}
		//Tell user how many guesses they have left
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		//Check if user guessed the word
		if (word==unknown)
		{
			cout << word << endl;
			cout << "You win!";
			break;
		}
	}
	
	if (num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose =(\n";
		cout << "The word is " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;

}

/*Take a one character guess and the secret word, and fill in the unfinished guessword. Returns number of characters matched.
Alse, Returns zero if the character is already guessed. */

int letterFill(char guess, string secretword, string &guessword)
{
	int matches = 0;
	int len = secretword.length();
	for (int i = 0; i < len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}