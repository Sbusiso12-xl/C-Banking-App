//---------------------------------------------------------------------------

#pragma hdrstop

#include "Data.h"

client::client(){
		name = "null";
		surname = "null";
		ID = "null";
		 cell = "null";
		 address = "null";
		 E_Mail = "null"  ;
		 pin = 0000;
};

void client::setValues (AnsiString nm ,AnsiString sm ,AnsiString id ,AnsiString add ,AnsiString cl ,AnsiString mail ,int Pin){
		name = nm;
		surname = sm;
		ID = id;
		 cell = cl;
		 address = add;
		 E_Mail = mail  ;
		 pin = Pin;
};

AnsiString client::getName(){return name;};


AnsiString client::getSurname(){return  surname;};

AnsiString client::getID(){return  ID;};

AnsiString client::getCell(){return  cell;};

AnsiString client::getAddress(){return  address;};

AnsiString client::getE_Mail(){return  E_Mail;};

int client::getPin(){return  pin;};


//---------------------------------------------------------------------------
#pragma package(smart_init)
