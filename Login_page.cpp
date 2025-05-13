//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login_page.h"
#include "Registration_page.h"
#include "welcome_page.h"
#include "Home_page.h"
#include "Data.h"
#include "banking appPCH1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginForm *LoginForm;
client Clients[100];
Account ac[100];
int clientCount;
int count;

//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
	: TForm(Owner)
{
		edtPin_Login-> PasswordChar= '*';
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::Button2Click(TObject *Sender)
{
	welcomePage_form ->Show();
	LoginForm ->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::btnLogin_LoginClick(TObject *Sender)
{
	// - check if  fields are not empty
	// - check if we have a record corresponding with the info
	// inserted in the fields
	// - if data is valid, open home page and close login page
	// - else msgdlg "invalid data"
		TStreamReader *data = new TStreamReader("clientinfo.txt");
		bool userVerified = false;

		AnsiString  line, username, userPin, name, surname, email, address, pin, ID, cellNum;
		int index;
		if(!edtID_Number_Login->Text.IsEmpty() || !edtPin_Login->Text.IsEmpty())
		{
		   while(!data->EndOfStream)
		   {
				line = data->ReadLine();

				name = line.SubString(1, line.Pos('#') - 1);
				line.Delete(1, line.Pos('#'));

				surname =  line.SubString(1, line.Pos('#') - 1);
				line.Delete(1, line.Pos('#'));

				ID =  line.SubString(1, line.Pos('#') - 1);
				line.Delete(1, line.Pos('#'));

				address =  line.SubString(1, line.Pos('#') - 1);
				line.Delete(1, line.Pos('#'));

				cellNum = line.SubString(1, line.Pos('#') - 1);
				line.Delete(1, line.Pos('#'));

				email =  line.SubString(1, line.Pos('#') - 1);
				line.Delete(1, line.Pos('#'));

				pin = line;

				Clients[clientCount].setValues(name, surname, ID, address, cellNum, email, StrToInt(pin));
				clientCount++;


		   }



		}
		else
		{
			MessageDlg("Please Enter Username/Pin", mtError, TMsgDlgButtons() << mbOK, 0);
		}
		int i = 0;

		for(int i = 0; i < clientCount; i++)
		{
			if( edtID_Number_Login->Text == Clients[i].getCell() && StrToInt(edtPin_Login->Text) == Clients[i].getPin())
			{
				userVerified = true;
				index=i;
			}
		}

		if(userVerified)
		{

			TStreamReader *acc = new TStreamReader("accountRec.txt");

			AnsiString line,accountNum,accountname;

			double balance;

			while(!acc->EndOfStream)
			{
				  line=acc->ReadLine();


				  accountname=line.SubString(1,line.Pos('#')-1);
				  line.Delete(1,line.Pos('#'));

                   accountNum=line.SubString(1,line.Pos('#')-1);
				  line.Delete(1,line.Pos('#'));


				  balance=StrToFloat(line);


				  ac[count].setValue(accountNum,accountname,balance);
				  count++;
			}

			HomePage->Show();
			LoginForm->Hide();
			HomePage->lblDisplayName ->Caption =Clients[index].getName();
			HomePage->lblDisplaySur->Caption=Clients[index].getSurname();
			HomePage->lblIDDisp->Caption=Clients[index].getID();
			HomePage->lblAdd->Caption=Clients[index].getAddress();
			HomePage->lblDispAdd->Caption=Clients[index].getE_Mail();
			HomePage->lblDispcell->Caption=Clients[index].getCell();


			//display on card
			HomePage->lblcardaccountnr->Caption ="Saving Account number" ;
			HomePage->lblcardusername->Caption =Clients[index].getName().SubString(1,1)+" "+ Clients[index].getSurname();
			if (ac[index].getAccNum() == NULL) {
    // Generate a random 6-digit account number
    int randomAccountNumber = rand() % 900000 + 100000;
	ac[index].setAccNum(randomAccountNumber);
    HomePage->lblaccnr->Caption = IntToStr(randomAccountNumber);
}      else
{
		HomePage->lblaccnr->Caption = ac[index].getAccNum();
}
			HomePage->lblaccnr->Caption = ac[index].getAccNum();
			HomePage->lblCaption->Caption = "Digital Banking";
			HomePage->lblCrdcap->Caption="OneGlobal";

		}
		else
		{
			MessageDlg("Incorrect User Name or Pin", mtError, TMsgDlgButtons() << mbOK, 0);
		}
		data->Close();
}

//---------------------------------------------------------------------------


void __fastcall TLoginForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TLoginForm::CheckBox1Click(TObject *Sender)
{
		 if(CheckBox1->Checked)
		 {
			 edtPin_Login->PasswordChar=0;
		 }else
		 {
			 edtPin_Login->PasswordChar='*';
         }
}
//---------------------------------------------------------------------------

