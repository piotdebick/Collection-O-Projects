//Piotr Debicki

#include "stack.h"
#include <iostream>
#include <string>



int main()
{
	arr_stack s, postfix;
	std::string expr;
	char token;
	int length;
	std::cout << "Enter infix expression: " << std::endl;
	getline(std::cin, expr);
	length = expr.length();
	for(int i = 0; i < length; i++)//compares the priority of each operation
	{
		switch(expr[i])
		{
		case '(' : {
						   s.push(expr[i]);
						   break;
					}	
		case ')' : do{	
						s.pop(token);
						postfix.push(token);
						if(s.getTop(token) == '(')
							break;
				   }while(s.getTop(token) != '(');
		case '+' : if(s.getTop(token) == '-' || s.getTop(token) == '*'||s.getTop(token) == '/'||s.getTop(token) == '^'||s.getTop(token) == '+')
				   {	
					   s.pop(token);
					   postfix.push(token);
					   s.push(expr[i]);
					   break;
				   }
				   {
						   s.push(expr[i]);
						   break;
					}	
		case '-' : if(s.getTop(token) == '-' || s.getTop(token) == '*'||s.getTop(token) == '/'||s.getTop(token) == '^'||s.getTop(token) == '+')
				   {	
					   s.pop(token);
					   postfix.push(token);
					   s.push(expr[i]);
					   break;
				   }
				   else	
					{
						   s.push(expr[i]);
						   break;
					}	
		case '*' : if(s.getTop(token) == '*'||s.getTop(token) == '/'||s.getTop(token) == '^')
				   {	
					   s.pop(token);
					   postfix.push(token);
					   s.push(expr[i]);
					   break;
				   }
				   else	
				   {
						   s.push(expr[i]);
						   break;
					}	
		case '/' : if(s.getTop(token) == '*'||s.getTop(token) == '/'||s.getTop(token) == '^')
				   {	
					   s.pop(token);
					   postfix.push(token);
					   s.push(expr[i]);
					   break;
				   }
				   else	
				   {
						   s.push(expr[i]);
						   break;
					}	
		case '^' : if(s.getTop(token) == '^')
				   {	
					   s.pop(token);
					   postfix.push(token);
					   s.push(expr[i]);
					   break;
				   }
				   else	s.push(expr[i]);
		default : {
					postfix.push(expr[i]);
					break;
				  }
		}
	}
	while(s.getTop(token))//pops remaining tokens from stack s and pushes them into stack postfix
	{
		s.pop(token);
		postfix.push(token);
	}
	for(int i = 0; i < length; i++) // reverses the order of the postfix expression
	{
		postfix.pop(token);
		s.push(token);
	}
	for(int i = 0; i < length; i++) //prints postfix expression
	{
		s.pop(token);
		if(token == '(' || token == ')')
			std::cout << "";
		else std::cout << token << " ";
	}
	std::cout << std::endl;
	return 0;
}