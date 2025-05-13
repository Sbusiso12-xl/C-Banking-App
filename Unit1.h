//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
#include <vcl.h>

//---------------------------------------------------------------------------
class Account {
private:
	AnsiString accountNumber;
	AnsiString accountHolderName;
    double balance;

public:
	Account();
	void setValue(AnsiString,AnsiString,double);
	AnsiString getAccNum();
	AnsiString getAccName();
	double getBalance();

};
#endif
