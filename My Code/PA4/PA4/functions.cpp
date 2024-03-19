/*
Author: Jeffrey Popek
Class: CSI-281-01: Data Structures & Algorithms
Date Assigned: 10-28-22
Due Date: 11-4-22

Description: Takes in math expression and calculates it using stack and queue


Certification of Authenticity: I  certify  that  this  is  entirely  my  own  work,  except  where  I  have  given fully-documented
references  to  the  work  of  others.  I  understand  the definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:-Reproduce  this  assignment  and  provide  a  copy  to  another
member  of academic staff; and/or-Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking service  (which  may  then
retain  a  copy  of  this  assignment  on  its database for the purpose of future plagiarism checking)
*/

#include "functions.h"

#pragma region Utility Functions

int calculate(int v1, int v2, char op)
{
	/*
	PRE: Two numbers and a operator are created
	POST: Returns the answer based on the numbers and operator
	PURPOSE: Helps with evaluating the postfix expression
	*/
	if (op == '+')
	{
		return v2 + v1;
	}
	if (op == '-')
	{
		return v2 - v1;
	}
	if (op == '*')
	{
		return v2 * v1;
	}
	if (op == '/')
	{
		return v2 / v1;
	}
	if (op == '^')
	{
		return pow(v2, v1);
	}

}

bool checkValid(string infix, int i)
{
	/*
	PRE: Infix expression created
	POST: Returns whether the expression is a valid expression
	PURPOSE: Returns bool by checking each character in the string and seeing if it is a valid input
	*/
	if (isNum(infix[i]) || infix[i] == ADD || infix[i] == MINUS || infix[i] == MULTIPLY || infix[i] == DIVIDE || infix[i] == POWER || infix[i] == '(' || infix[i] == ')' || infix[i] == '\n' || infix[i] == ' ' || infix[i] == '\r')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool countParetheses(string infix)
{
	/*
	PRE: Infix expression created
	POST: Paretheses in infix expression will be counted
	PURPOSE: To make sure the entered expression is valid with the correct amount of paretheses
	*/
	int counter = 0;
	for (int i = 0; i <= infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			counter++;
		}
		else if (infix[i] == ')')
		{
			counter--;
		}
	}

	if (counter != 0)
	{
		return false;
	}
	return true;
}

string getInput()
{
	/*
	PRE: None
	POST: Return's user's input
	PURPOSE: Use to get the infix expression from the user
	*/
	string infix = "";
	cout << "INFIX TO POSTFIX" << endl;
	cout << "Type your infix expression with paretheses on both ends: ";

	getline(cin, infix);

	return infix;
}

bool isNum(char input)
{
	/*
	PRE: Input created
	POST: Returns whether a char is a digit or not
	PURPOSE: To tell user if the entered char is a digit or not
	*/
	if (input >= '0' && input <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isOperator(char input) {
	/*
	PRE: Input created
	POST: Returns whether a char is a operator or not
	PURPOSE: To tell user if the entered char is a operator or not
	*/
	if (input == '+' || input == '-' || input == '*' || input == '/' || input == '^')
	{
		return true;
	}

	return false;
}

#pragma endregion


#pragma region Infix and Postfix Functions

int evaluate(string postfix)
{
	/*
	PRE: Postfix expression created
	POST: Answer to the postfix expression
	PURPOSE: Evaluates the postfix expression with Stack
	*/
	int result = 0;
	Stack<int> stack;
	int temp = 0;
	int i = 0;
	int length = postfix.length() / 2;
	int runThrough = length;
	while (i < length)
	{
		char t = postfix[i];
		if (isNum(postfix[i])) {
			temp = temp * 10 + (postfix[i] - '0');
		}
		else if (postfix[i] == ' ') {
			stack.push(temp);
			temp = 0;
		}
		else
		{
			int v1 = stack.pop();
			int v2 = stack.pop();

			result = calculate(v1, v2, t);
			stack.push(result);
			i++;

		}
		i++;
		runThrough--;
		if (runThrough == 0)
		{
			break;
		}
	}

	result = stack.pop();
	return result;
}

string getPostfix(string infix)
{
	/*
	PRE: Infix expression created
	POST: Postfix expression returned
	PURPOSE: Uses Stack and Queue to create the postfix expression from the infix expression
	*/
	Queue<string> queue;
	Stack<char> stack;
	string numHolder = "";

	//Check for correct amount of paretheses
	if (!(countParetheses(infix)))
	{
		cout << "Invalid infix expression";
		exit(0);
	}

	for (int i = 0; i <= infix.length(); i++)
	{
		//Check to see if infix expression is valid
		if (checkValid(infix, i))
		{
			//Check to see if index is a number, paretheses, or operator
			if (isNum(infix[i]))
			{
				numHolder += infix[i];

				//If the next index is not a number, enqueue the number
				if (!(isNum(infix[i + 1])))
				{
					queue.enqueue(numHolder);
					numHolder = "";
				}
			}
			else if (infix[i] == ')')
			{
				if (infix[i + 1] == NULL)
				{
					for (int i = 0; i < infix.length(); i++)
					{
						//Smartspace tutor helped with turning char into string
						char c = stack.pop();
						string temp(1, c);
						queue.enqueue(temp);
					}
				}
				char c = stack.pop();
				string temp(1, c);
				queue.enqueue(temp);
			}
			else
			{
				if (isOperator(infix[i]))
				{
					stack.push(infix[i]);
				}
			}
		}
		else
		{
			//Smartspace tutor helped with preventing getting an invalid character on the end of the string
			if ((int)infix[i] == 0) { continue; }

			cout << "Invalid infix expression" << endl;
			exit(0);
		}
	}

	cout << "Postfix expression: ";
	queue.display();

	//Put postfix into string and return it
	string temp, postfix;
	for (int i = 0; i < infix.length(); i++)
	{
		temp = queue.dequeue();
		postfix += temp + ' ';
	}

	return postfix;
}
#pragma endregion
