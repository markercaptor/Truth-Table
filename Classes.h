#ifndef CLASSES_H
#define CLASSES_H
#include <string>
using namespace std;
class TableGen
{
	private:
	// Truth values: p, q, r, c, t /bool variables.
		bool *p_1;
		bool *q_1;
		bool *r_1;
        bool *p_0;
        bool *q_0;
        bool *r_0;
        bool p;
        bool q;
        bool r;
        bool not_q=0;
        bool not_r=0;
        bool not_p=0;
		const bool c=0;
		const bool t=1;
    //static int
        static int var_num;
    // bool arryas: for truth table
		bool **table_show;
    // componets of the table array
		long rows; //rows for final table
		long columns; //colums for final table
		int componet_size; //keeps the size of the componet array
	// string arrays: one for tokens (individual parts), the other for components ("groups" per se, ex: (p || q)).
		string tokens[20];
		string component[5];
	// int array: values of tokens (size of 20).
		int tokenValue[20];
		int numTokens;
	public:
		TableGen();
		void tokenConverter(); //converts to usable form
		void tokenConnector(); //converts to a manipulatable form
		bool truthVal(); // Determines truth
		void display(int, int); //displays the truth table
		int setTokens(string statement); //sets the tokens
		string getToken(int index) //gets the token array
			{ return tokens[index]; }
		int choice_validation(int x); //checks validation for choice picked by the user

};
#endif