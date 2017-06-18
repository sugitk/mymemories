#include <iostream.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXINPUTBUF	255

enum boolean {TRUE, FALSE};

// global変数
char buf[MAXINPUTBUF];
int i = 0;
boolean isLeftValue = TRUE;

// 関数の定義
void analyze();
void syntaxerr(int);

boolean isFollowS();
boolean isFollowE();
boolean isFollowT();
boolean isFollowF();
boolean isFollowI();
boolean isFollowV();

boolean syntax();
boolean expression();
boolean term();
boolean factor();
boolean identifier();
boolean value();

// Follow(K)の確認
boolean isFollowS()
{
	if(buf[i] == ';')
	{
		return TRUE;
	}
	return FALSE;
}

boolean isFollowE()
{
	if(buf[i] == ')' || buf[i] == ';')
	{
		return TRUE;
	}
	return FALSE; 
}

boolean isFollowT()
{
	if(buf[i] == '+' || buf[i] == '-' ||
	   buf[i] == ')' || buf[i] == ';')
	{
		return TRUE;
	}
	return FALSE; 
}

boolean isFollowF()
{
	if(buf[i] == '+' || buf[i] == '-' ||
	   buf[i] == '*' || buf[i] == '/' ||
	   buf[i] == ')' || buf[i] == ';')
	{
		return TRUE;
	}
	return FALSE; 
}

boolean isFollowI()
{
	if(buf[i] == '=')
	{
		return TRUE;
	}
	else if(buf[i] == ';' || buf[i] == '+' ||
	        buf[i] == '-' || buf[i] == '*' ||
	        buf[i] == '/' || buf[i] == ')' )
	{
		isLeftValue = FALSE;
		return TRUE;
	}
	return FALSE; 
}

boolean isFollowV()
{
	if(buf[i] == '+' || buf[i] == '-' ||
	   buf[i] == '*' || buf[i] == '/' ||
	   buf[i] == ')' || buf[i] == ';')
	{
		isLeftValue = FALSE;
		return TRUE;
	}
	return FALSE; 
}

// 構文解析

boolean syntax()
{
	boolean temp;

	if(isalpha(buf[i]))
	{
		temp = identifier();
	}
	else syntaxerr(0);

	if(buf[i] != '=') syntaxerr(1);
	i++;

	while(isLeftValue == TRUE)
	{
		temp = expression();
		if(buf[i] == '=')
		{
			if(isLeftValue == FALSE) syntaxerr(2); 
			i++;
		}
	}

	temp = expression();	

	if(temp == FALSE) syntaxerr(3);

	if(isFollowS() == FALSE) syntaxerr(4);
	return TRUE;
}

boolean expression()
{
	boolean temp;

	temp = term();

	while(buf[i] == '+' || buf[i] == '-')
	{
		i++;
		temp = term();
	}

	if(temp == FALSE) syntaxerr(5);

	if(isFollowE() == FALSE) syntaxerr(6);
	return TRUE;
}

boolean term()
{
	boolean temp;

	temp = factor();

	while(buf[i] == '*' || buf[i] == '/')
	{
		i++;
		temp = factor();
	}

	if(temp == FALSE) syntaxerr(7);

	if(isFollowT() == FALSE) syntaxerr(8);
	return TRUE;
}

boolean factor()
{
	boolean temp;

	if(buf[i] >= '0' && buf[i] <= '9')
	{
		temp = value();
	}
	else if(isalpha(buf[i]))
	{
		temp = identifier();
	}
	else if(buf[i] == '(')
	{
		i++;
		temp = expression();
		if(buf[i] != ')') syntaxerr(9);
		i++;
	}

	if(temp == FALSE) syntaxerr(10);

	if(isFollowF() == FALSE) syntaxerr(11);
	return TRUE;
}

boolean identifier()
{
	while(isalnum(buf[i]))
	{
		i++;
	}
	
	if(isFollowI() == FALSE) syntaxerr(12);

	cout << "This is identifier." << endl;
	return TRUE;
}

boolean value()
{
	while(isdigit(buf[i]))
	{
		i++;
	}
	if(isFollowV() == FALSE) syntaxerr(13);

	cout << "This is value." << endl;
	return TRUE;
}

// 起動部分
void analyze()
{
	boolean isSuccess;

	isSuccess = syntax();

	if(isSuccess == FALSE) syntaxerr(14);
	cout << "Succeeded." << endl;
}

// error表示
void syntaxerr(int error)
{
	cout << "Syntax error at " << i+1 << "th character." << endl;
	cout << "Error code is " << error << "." << endl;

	exit(1);
}

// main
int main()
{
	cin >> buf;
	analyze();
	cout << buf << endl;
	
	return 0;
}

