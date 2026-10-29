// Used for input/ouptut operations
#include <iostream>

// Import the templates that will be used
#include "template/Card.h"
#include "template/Deck.h"
#include "template/Player.h"

int main()
{
	Deck Deck1 = Deck(); // Create the deck object

	Deck1.shuffle();

	std::cout << "Rank: " << Deck1.peekCard(0).getRank() << endl;
	std::cout << "Suit: " << Deck1.peekCard(0).getSuit();
}
