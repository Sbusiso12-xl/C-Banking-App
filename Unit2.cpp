//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


Account::Account()
 {
		accountNumber = "null";
		accountHolderName = "null ";
		balance = 0.0;
 }
void Account::setValue(AnsiString accNum,AnsiString accHolderName,double initBalance)
{
		accountNumber = accNum;
		accountHolderName = accHolderName;
		balance = initBalance;
}
AnsiString Account::getAccNum()
{
	return accountNumber;
}
AnsiString Account::getAccName()
{
	return accountHolderName;
}
double Account::getBalance()
{
	return balance;
}
/* int getAccNum() const {
		return accountNumber;
	} */