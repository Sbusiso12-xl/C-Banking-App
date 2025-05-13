//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "welcome_page.h"
#include "Home_page.h"
#include "Login_page.h"
#include "Registration_page.h"
#include "Data.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TwelcomePage_form *welcomePage_form;
//---------------------------------------------------------------------------
__fastcall TwelcomePage_form::TwelcomePage_form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TwelcomePage_form::btnLoginClick(TObject *Sender)
{
	welcomePage_form ->Hide();
	LoginForm ->Show();
}
//---------------------------------------------------------------------------
void __fastcall TwelcomePage_form::btn_RegisterClick(TObject *Sender)
{
	RegistrationForm -> Show();
	welcomePage_form ->Hide();

    //
}
//---------------------------------------------------------------------------
void __fastcall TwelcomePage_form::FormClose(TObject *Sender, TCloseAction &Action)

{
    Application->Terminate();
}
//---------------------------------------------------------------------------

