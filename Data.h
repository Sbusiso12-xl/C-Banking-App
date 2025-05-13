//---------------------------------------------------------------------------

#ifndef DataH
#define DataH

class client{
	 private:
		AnsiString name;
		AnsiString surname;
		AnsiString ID;
		AnsiString cell;
		AnsiString address;
		AnsiString E_Mail  ;
		int pin;

	 public:
		client();
		AnsiString getName();
		AnsiString getSurname();
		AnsiString getID();
		AnsiString getCell();
		AnsiString getAddress();
		AnsiString getE_Mail()  ;
		int getPin();

		void setValues(AnsiString ,AnsiString ,AnsiString ,AnsiString ,AnsiString ,AnsiString ,int);


};

//---------------------------------------------------------------------------
#endif
