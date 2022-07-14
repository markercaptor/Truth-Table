#include "Classes.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string op;
	TableGen table; //Tablegen object
	int maxToken=0; //token
	int choice1=0, choice2=0; //for choices
	string fullStatement; //statement from user
	cout << "\n\n\nWelcome to the Truth Table Generator.\n"
		 << "Please select an option from the menu below:\n"
		 << "\t1 - Truth Table Presets\n"
		 << "\t2 - Custom Truth Table Generator\n"
		 << "\t3 - About Us\n"
		 << "\t4 - Exit\n";
	cin >> choice1; //get user input

	switch (choice1)
	{
		case 1: cout << "\nPlease enter the preset that you would like to see\n"
					 << "from the menu below:\n"								 // Each preset is supposed to display its own table, right?
					 << "\t1 - 'If p, then q' table\n"							 // All options print out the same table because of table.display().
					 << "\t2 - 'If, and only if, p, then q' table\n"
					 << "\t3 - 'If p, then not p' table\n"
					 << "\t4 - 'Tautology' table\n"
					 << "\t5 - 'Contradiction' table\n";

				cin >> choice2; //get user input

				//table.choice_validation(choice2); //validate user input
				if(choice2==1)
				{
					cout << "If Then Here";
					fullStatement="p -> q";

				}
				else if(choice2==2)
				{
					cout << "If and Only If Here";
					fullStatement="p <-> q";
				}
				else if(choice2==3)
				{
					cout << "Negation Here";
					fullStatement="p -> ~p";
				}
				else if(choice2==4)
				{
					cout << "Tautology Here";
					fullStatement="t";
				}
				else if(choice2==5)
				{
					cout << "Contradiction Here";
					fullStatement="c";
				}
			break;
		case 2: cout << "\nBefore you construct your custom truth table," // Same as before, when typing in statements, it outputs the same table/truth values from table.display().
					 << "\nplease read the following information: "
					 << "\n\t\tYou are permitted to use any of the symbols or words listed below"
					 << "\n\tto signify their listed meaning when writing our your statement for analysis."
					 << "\n\tPlease undestand that the generator will automatically convert all the symbols"
					 << "\n\tlisted below into a universal form, which is likewise denoted below. The references"
					 << "\n\twill begin with the way that the symbol will be displayed, followed by what will be"
					 << "\n\tacceptable forms of input for that symbol."
					 << "\n\n\t &&: &, &&, AND, and, ^"
					 << "\n\t ||: ||, or, OR, V"
					 << "\n\t  ~: !, ~ (negation)"
					 << "\n\t ->:  -> (Only acceptable form for If Then)"
					 << "\n\t<->: <-> (Only acceptable form for biconditional/ If and Only If)";
            cin.ignore(); //needed to make getline work
				cout << "\n\nEnter your statement below. Separate your components(p's, q's, V's, ->'s)\n"
					 << "with spaces. Do not separate ~, !, or parenthesis from the variables.\n"
            << "Example: (~p V !q) AND q || s\n\tYour statement: ";
            getline(cin, fullStatement); //get input
				cout << "\nText is: " << fullStatement << endl;
			break;
		case 3: cout << "\n\nAbout This Project - This program was designed " // Use exit(0) for now. We may need to make it to where the user can choose to go back to the main menu.
					 << "for Professor Lane Cosper of Texas A&M University - Corpus Christi, who "
					 << "asked our team to create a truth table generator for classroom use. "
					 << "Professor Cosper wanted the user of the program to choose between preset "
					 << "statements or custom statements, both of which will lead to the truth values "
					 << "of the requested statements.\n";
				exit(0);
			break;
		case 4: cout << "\nThank you for using this Truth Generator Program.\nGoodbye.\n\n";
				exit(0);
			break;
	}
	maxToken=table.setTokens(fullStatement);

	cout << "\nNum of Tokens: " << maxToken << endl;
	for(int i=0; i<maxToken; i++)
	{
		cout << "\nToken " << (i+1) << ": " << table.getToken(i);
	}

	cout << "\nConverting...\n";
	table.tokenConverter();
	fullStatement="";
	for(int i=0; i<maxToken; i++)
	{
		cout << "\nToken " << (i+1) << ": " << table.getToken(i);
		fullStatement.append(table.getToken(i));
	}
	cout << "\n" << fullStatement << "\n";
    table.tokenConnector();
    table.truthVal();
    table.display(choice1, choice2);

	return 0;
}