//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Registration_page.h"
#include "welcome_page.h"
#include "Home_page.h"
#include "Login_page.h"
#include "Data.h"
#include<ctype.h>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRegistrationForm *RegistrationForm;
client Client;
//---------------------------------------------------------------------------
__fastcall TRegistrationForm::TRegistrationForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRegistrationForm::btnBackClick(TObject *Sender)
{
	welcomePage_form ->Show();
	RegistrationForm -> Hide();
}
//---------------------------------------------------------------------------

 int count_nums(const AnsiString &IdStr)
{
	int count = 0;
	for(int i = 1; i <= IdStr.Length(); ++i)
	{
		if(isdigit(IdStr[i]))
			count++;
	}
	return count;
}

bool isValid(const AnsiString &str)
{
	bool isValid = true;
	for( int i = 1; i <= str.Length(); ++i)
	{
		if(!isdigit(str[i]))
		{
			isValid = false;
			break;
		}

	}
	if(isValid)
		return true;
	else
		return false;
}

bool isString(AnsiString Str)
{
	for(int i = 1; i <= Str.Length(); ++i)
	{
		if(!isalpha(Str[i]))
			return false;
	}
	return true;
}

void __fastcall TRegistrationForm::btnRegisterClick(TObject *Sender)
{
	//make sure ID and password if filled
	//take data and write it to a text file
	//open the home page and close registration

    {
	 AnsiString name, surname, addUser;
	 int atIndex = edtE_Mail->Text.Pos("@");
	 int idNum, pinNum;
	 int idCount = count_nums(edtID_Number->Text);
	 int cellCount = count_nums(edtCell_Number->Text);
	 int pinCount = count_nums(edtPin->Text);
	 AnsiString cellStr = edtCell_Number->Text;


	if( edtName->Text.IsEmpty())
	{

		lblName->Caption = "Enter a valid Name";
		lblName->Font->Color = clRed;
	}
	else if(!isString(edtName->Text))
	{
		lblName->Caption = "Name must contain only letters.";
		lblName->Font->Color = clRed;
	}
	else if (edtSurname->Text.IsEmpty())
	{

		lblSurname->Caption = "Enter a valid Surname";
		lblSurname->Font->Color = clRed;
	}
	else if(!isString(edtSurname->Text))
	{
		lblSurname->Caption = "Surname must contain only letters.";
		lblSurname->Font->Color = clRed;
	}


	else if (edtID_Number->Text.IsEmpty())
	{

		lblID->Caption = "Enter a valid ID Number";
		lblID->Font->Color = clRed;
	}
	else if(!isValid(edtID_Number->Text))
	{
		lblID->Caption = "ID Number must only contain Numbers";
		lblID->Font->Color = clRed;
	}
	else if(idCount != 13)
	{
		lblID->Caption = "ID Number must consists of 13 Numbers";
		lblID->Font->Color = clRed;
	}


	else if (edtCell_Number->Text.IsEmpty())
	{

		lblCell->Caption = "Enter a Cell Number";
		lblCell->Font->Color = clRed;
	}
	else if(cellStr[1] != '0')
	{
		lblCell->Caption = "Cell Number must strart with a 0 ";
		lblCell->Font->Color = clRed;
    }
	else if(!isValid(edtCell_Number->Text))
	{
		lblCell->Caption = "Cell Number must only contain Numbers";
		lblCell->Font->Color = clRed;
	}
	else if(cellCount != 10)
	{
		lblCell->Caption = "Cell Phone Number must consists of 10 Numbers";
		lblCell->Font->Color = clRed;
	}


	else if (edtAddress->Text.IsEmpty())
	{

		lblAddress->Caption = "Enter a valid Address";
		lblAddress->Font->Color = clRed;
	}
	else if (edtE_Mail->Text.IsEmpty())
	{

		lblMail->Caption = "Enter a valid E-Mail";
		lblMail->Font->Color = clRed;
	}
	else if( atIndex == 0)
	{
		MessageDlg("Invalid Email, Enter a valid E-Mail\n(e.g John12@gmail.com)", mtError, TMsgDlgButtons() << mbOK, 0);
    }
	else if (edtPin->Text.IsEmpty())
	{

		lblPin->Caption = "Enter a valid Pin";
        lblPin->Font->Color = clRed;
	}
	else if(!isValid(edtPin->Text))
	{
		lblID->Caption = "Pin must only contain Numbers";
		lblID->Font->Color = clRed;
	}
	else if(pinCount != 4)
	{
		lblPin->Caption = "Pin must consists of 4 Digits";
		lblPin->Font->Color = clRed;
	}
	else
	{

        MessageDlg("Registration Complete! Welcome to DIGITAL BANK", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

		addUser = edtName->Text + '#' + edtSurname->Text + '#' +  edtID_Number->Text + '#' +  edtAddress->Text + '#' + edtCell_Number->Text + '#' + edtE_Mail->Text + '#' + edtPin->Text;

		TStringList *StringList = new TStringList();
		if(FileExists("clientinfo.txt"))
		{
			StringList->LoadFromFile("clientinfo.txt");
		}
		StringList->Add(addUser);
		StringList->SaveToFile("clientinfo.txt");
		delete StringList;
		welcomePage_form->Show();
		RegistrationForm->Hide();
	}
}

}
//---------------------------------------------------------------------------







void __fastcall TRegistrationForm::edtNameChange(TObject *Sender)
{
    lblName->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::edtSurnameChange(TObject *Sender)
{
    lblSurname->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::edtID_NumberChange(TObject *Sender)
{
    lblID->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::edtCell_NumberChange(TObject *Sender)
{
    lblCell->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::edtAddressChange(TObject *Sender)
{
    lblAddress->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::edtE_MailChange(TObject *Sender)
{
    lblMail->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::edtPinChange(TObject *Sender)
{
    lblPin->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TRegistrationForm::FormClose(TObject *Sender, TCloseAction &Action)

{
	Application->Terminate();
}
//---------------------------------------------------------------------------



