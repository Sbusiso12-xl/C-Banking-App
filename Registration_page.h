//---------------------------------------------------------------------------

#ifndef Registration_pageH
#define Registration_pageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TRegistrationForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *edtName;
	TEdit *edtSurname;
	TEdit *edtID_Number;
	TEdit *edtCell_Number;
	TEdit *edtAddress;
	TEdit *edtE_Mail;
	TEdit *edtPin;
	TButton *btnRegister;
	TButton *btnBack;
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *lblID;
	TLabel *lblName;
	TLabel *lblCell;
	TLabel *lblAddress;
	TLabel *lblMail;
	TLabel *lblPin;
	TLabel *lblSurname;
	void __fastcall btnBackClick(TObject *Sender);
	void __fastcall btnRegisterClick(TObject *Sender);
	void __fastcall edtNameChange(TObject *Sender);
	void __fastcall edtSurnameChange(TObject *Sender);
	void __fastcall edtID_NumberChange(TObject *Sender);
	void __fastcall edtCell_NumberChange(TObject *Sender);
	void __fastcall edtAddressChange(TObject *Sender);
	void __fastcall edtE_MailChange(TObject *Sender);
	void __fastcall edtPinChange(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TRegistrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRegistrationForm *RegistrationForm;
//---------------------------------------------------------------------------
#endif
