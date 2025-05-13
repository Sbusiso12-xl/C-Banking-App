//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Home_page.h"
#include "Registration_page.h"
#include "welcome_page.h"
#include "Login_page.h"
#include "Data.h"
#include "banking appPCH1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THomePage *HomePage;
double availableBalance;
//---------------------------------------------------------------------------
__fastcall THomePage::THomePage(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THomePage::FormClose(TObject *Sender, TCloseAction &Action)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall THomePage::DepositClick(TObject *Sender)
{
	try
{
	double initialBalance = StrToFloat(edtDepositAmount->Text);

	if (initialBalance <= 0)
	{
		ShowMessage("Invalid amount. Please enter a positive value.");
		return;
	}

	availableBalance += initialBalance; // Update available balance
   //	StatusBar1->Panels->Items[0]->Text = "Deposited: R" + FloatToStrF(initialBalance, ffFixed, 10, 2);
	Balance->Caption = "R" + FloatToStrF(availableBalance, ffFixed, 10, 2);
	ShowMessage("Deposit Successful.");



	// Update the status bar with the deposited amount

}
catch (Exception &e)
{
	ShowMessage("Invalid input. Please enter a valid numeric value.");
}

}
//---------------------------------------------------------------------------






void __fastcall THomePage::Button1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall THomePage::ValidateClick(TObject *Sender)
{
   AnsiString phoneNumber = edtNumber->Text.Trim();
	//AnsiString selectedNetwork = ComboBox1->Text;

	// Validate phone number length (exactly 10 digits)
	int dummy;
	if (phoneNumber.Length() != 10|| !TryStrToInt(phoneNumber, dummy))
	{
		ShowMessage("Please enter a 10-digit phone number. and make sure to select the network");
		return;
	}

	 if(phoneNumber.Length() == 10)// || IsNumeric (phoneNumber))
	 {

	   ShowMessage("CellNumber succesfully validated.");
		// Valid phone number
	   // lblResult->Caption = "Valid phone number!";
		// Populate combo box with network options
		NetworkType->Items->Clear();
	   //	ComboBox1->Items->Add("MTN");

		NetworkType->Items->Add("Telkom ");
		NetworkType->Items->Add(" MTN") ;
		NetworkType->Items->Add("Vodacom");
		NetworkType->Items->Add("Cell C");

	}
}
//---------------------------------------------------------------------------


void __fastcall THomePage::PurchaseClick(TObject *Sender)
{
	try

 {




   /*	else
	{
		// Invalid phone number
		lblResult->Caption = "Invalid phone number!";
		ComboBox1->Items->Clear(); // Clear combo box
	} */

	//lblResult->Caption = "Selected network for " + phoneNumber + ": " + selectedNetwork;



		double purchaseAmount = StrToFloat(edtAmount->Text);

        // Validate purchase amount (ensure it's positive)
		if (purchaseAmount <= 0)
		{
			ShowMessage("Invalid purchase amount. Please enter a positive value.");
			return;
		}
			if( NetworkType->ItemIndex == -1)
	{
	   ShowMessage("Please Select Network");
		return;
	}
        // Check if purchase amount is available in balance
		if (purchaseAmount > availableBalance)
		{
			ShowMessage("Insufficient balance. Please recharge your account.");
			return;
		}

		// Deduct the purchase amount from available balance
		availableBalance -= purchaseAmount;
		Balance->Caption = "R" + FloatToStrF(availableBalance, ffFixed, 10, 2);

		// Display success message
		ShowMessage("Airtime purchased successfully!");
   }
	catch (Exception &e)
    {
        ShowMessage("Invalid input. Please enter a valid numeric value.");
    }

}

//---------------------------------------------------------------------------





void __fastcall THomePage::Timer1Timer(TObject *Sender)
{

        static bool moveRight1 = true;
    static bool moveRight2 = true;
    static bool moveRight3 = true;

	const int stepSize1 = 30; // Adjust as needed for Panel1
	const int stepSize2 = 20; // Adjust as needed for Panel2
	const int stepSize3 = 40; // Adjust as needed for Panel3

    if (moveRight1)
    {
		Panel5->Left += stepSize1;
		if (Panel5->Left + Panel5->Width >= ClientWidth)
            moveRight1 = false;
    }
    else
    {
		Panel5->Left -= stepSize1;
		if (Panel5->Left <= 0)
            moveRight1 = true;
    }

    if (moveRight2)
    {
		Panel6->Left += stepSize2;
		if (Panel6->Left + Panel6->Width >= ClientWidth)
            moveRight2 = false;
    }
    else
    {
		Panel6->Left -= stepSize2;
		if (Panel6->Left <= 0)
            moveRight2 = true;
    }

    if (moveRight3)
    {
		Panel7->Left += stepSize3;
		if (Panel7->Left + Panel7->Width >= ClientWidth)
			moveRight3 = false;
	}
	else
    {
		Panel7->Left -= stepSize3;
		if (Panel7->Left <= 0)
			moveRight3 = true;
	}
}

//---------------------------------------------------------------------------

void __fastcall THomePage::Button2Click(TObject *Sender)
{ // Get the input from the edit boxes
UnicodeString userInput = edtBeneficiaryName->Text;
UnicodeString phoneNumberStr = edtBeneficiaryNumber->Text;
UnicodeString meterNumberStr = edtMeterNum->Text;
UnicodeString purchaseAmountStr = edtAm->Text;

// Validate beneficiary name (letters only)
bool isNameValid = true;
for (int i = 1; i <= userInput.Length(); ++i)
{
    if (!isalpha(userInput[i]))
    {
        isNameValid = false;
        break; // Exit the loop as soon as an invalid character is found
    }
}

if (!isNameValid)
{
    ShowMessage("Enter a valid Name");
    Label12->Caption = "Enter a valid Name";
    Label12->Font->Color = clRed;
    return; // Stop further processing
}
else
{
    Label12->Caption = "Valid Name";
    Label12->Font->Color = clGreen;
}

// Validate phone number (10 digits, non-negative)
int phoneNumber = StrToIntDef(phoneNumberStr, -1);
if (phoneNumberStr.Length() != 10 || phoneNumber < 0)
{
    ShowMessage("Please enter a valid 10-digit non-negative phone number.");
    edtBeneficiaryNumber->SetFocus();
    return; // Stop further processing
}
else
{
    Label13->Caption = "Valid phone number";
    Label13->Font->Color = clGreen;
}

// Validate meter number (13 digits, numeric)
bool isMeterValid = true;
for (int i = 1; i <= meterNumberStr.Length(); ++i)
{
    if (!isdigit(meterNumberStr[i]))
    {
        isMeterValid = false;
        break;
    }
}

if (meterNumberStr.Length() != 13 || !isMeterValid)
{
    ShowMessage("Please enter a valid 13-digit numeric meter number.");
    edtMeterNum->SetFocus();
    return; // Stop further processing
}
else
{
    Label14->Caption = "Valid meternumber";
    Label14->Font->Color = clGreen;
}

// Validate purchase amount (not empty)
double purchaseAmount = StrToFloatDef(purchaseAmountStr, -1);
if (purchaseAmount <= 0)
{
	ShowMessage("Please enter a valid purchase amount.");
	edtAm->SetFocus();
	return; // Stop further processing
}

// Check if available balance is sufficient
if (purchaseAmount > availableBalance)
{
	ShowMessage("Insufficient amount. Recharge your account.");
	return; // Stop further processing
}

// Deduct the purchase amount from available balance
availableBalance -= purchaseAmount;
Balance->Caption = "R" + FloatToStrF(availableBalance, ffFixed, 10, 2);

// Generate a random token (11 digits)
int token = random(1000000000) + 1000000000;

// Display success message
ShowMessage("Successfully bought R" + FloatToStrF(purchaseAmount, ffFixed, 10, 2) +
			 " electricity for " + userInput + "\nToken: " + IntToStr(token));
//---------------------------------------------------------------------------
  }



void __fastcall THomePage::AddClick(TObject *Sender)
{
	String enteredName = edtAdd->Text;

    // Add the entered name to the combo box
	names->Items->Add(enteredName);

     TStringList *nameList = new TStringList;
    nameList->LoadFromFile("names.txt"); // Load names from the file

    // Add each name to the combo box
    for (int i = 0; i < nameList->Count; ++i) {
        names->Items->Add(nameList->Strings[i]);
    }

	delete nameList; // Clean up memory








	Add->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall THomePage::Button3Click(TObject *Sender)
{
// Get selected name
String selectedName = names->Text;

// Check if the selected name is in the ComboBox items
bool isValidName = names->Items->IndexOf(selectedName) >= 0;

if (isValidName)
{
    // Get entered amount
	double amountPaid = StrToFloatDef(edtpay->Text, 0.0);

    // Validate amount (non-negative)
    if (amountPaid >= 0.0)
    {
        // Check available balance
        if (amountPaid > availableBalance)
        {
            ShowMessage("Insufficient balance. Please recharge your account.");
        }
        else
        {
            // Deduct the purchase amount from available balance
			availableBalance -= amountPaid;
            Balance->Caption = "R" + FloatToStrF(availableBalance, ffFixed, 10, 2);

			// Display success message
		ShowMessage("Successfully paid " + selectedName);
		 displaybar->Panels->Items[0]->Width = 500;
		 displaybar->Panels->Items[0]->Text = "Amount Paid R" + FloatToStrF(amountPaid, ffFixed, 10, 2) ;
		// " for " + selectedName + " at " + Time().FormatString("hh:mm:ss");
			displaybar->Panels->Items[1]->Text =  "Time: " + Time().FormatString("hh:mm:ss");


		}
	}
    else
	{
        ShowMessage("Please enter a valid non-negative amount.");
    }
}
else
{
    ShowMessage("Please choose a valid name from the ComboBox.");
}

}

//---------------------------------------------------------------------------





void __fastcall THomePage::stgInfoClick(TObject *Sender)
{
	stgInfo->Cells[0][0]="name";
	stgInfo->Cells[1][0]="Transactions";
	//stgInfo->Celll[2][1]=Add(name);
	//stgInfo->Celll[2][1]=Add(amount);
}
//---------------------------------------------------------------------------

