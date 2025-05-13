//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit1.h"
#include "Home_page.h"
#include "Login_page.h"
#include "Data.h"
#include "welcome_page.h"
#include "banking appPCH1.h"
#include "Registration_page.h"
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