//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include "Data.h"
#include "welcome_page.h"
#include "Home_page.h"
#include "Login_page.h"
#include "Registration_page.h"
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

   class Account {
private:
	AnsiString accountNumber;
	AnsiString accountHolderName;
    double balance;

public:
	Account();
	void setValue(AnsiString,AnsiString,double);
	void setAccNum(int num) {
		accountNumber = num;
	}

	AnsiString getAccNum();
	AnsiString getAccName();
	double getBalance();

};
#endif
