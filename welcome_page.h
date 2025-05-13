//---------------------------------------------------------------------------

#ifndef welcome_pageH
#define welcome_pageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TwelcomePage_form : public TForm
{
__published:	// IDE-managed Components
	TButton *btnLogin;
	TButton *btn_Register;
	TLabel *lblBank;
	TImage *Image1;
	TLabel *Label1;
	void __fastcall btnLoginClick(TObject *Sender);
	void __fastcall btn_RegisterClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TwelcomePage_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TwelcomePage_form *welcomePage_form;
//---------------------------------------------------------------------------
#endif
