#pragma once
#include <array>
#include <vector>
#include <string>
#include <map>
#include "settings.h"

class Organisme{
	//gen-strengen som forteller hvilke sensorer som kobles med hvilke vekter og output 
	std::string genotype; 
	bool kjonn; //pikk eller pung (livmor)
	std::array<float, ANTALL_VEKTER> vekter; //vekter, verdi mellom -1, 1 
	//Posisjonen inngår ikke i sensorer, da det er urealistisk at organismen vet sin absolutte posisjon
	std::array<float, 2> posisjon;	

	// Egenskapene er representert som en float-verdi. De kan ikke være negative.
	// [hastighet, 
	std::vector<float> egenskaper;

	public:
		
	Organisme(std::string conf = "");

	std::vector<float> rEgenskaper() const;
	std::array<float, 2> getPos() const;
	void oppdaterEgenskaper(std::vector<float> nyeEgenskaper);
	void tilfeldigEgenskaper();

	std::string pGener() const;
	std::string pVekter() const;
	std::string pEgenskaper() const;
	std::string pSensorer() const;

	enum class Egenskaper {

		hastighet = 0, //default 1, raskere = < energi
		vekt, //default 1, tyngre blir tregere, < energi, men mer liv
		syn, //default 0, maks 1, detektere objekt foran med %-vis nøyaktighet, se lenger unna
		genAntall, //default 5, antall koblinger mellom sensorer, vekter og handlinger. Flere koblinger = < energi
		tann_spisshet, // default 0.5, lavere gir flatere, høyere spissere. Påvirker mat-spising og skade på andre.
		magesyre, // default 0.5. lavere bedre på planter, høyere bedre på kjøtt, råttent kjøtt.
		feromoner, //default 0, %vis økning for å tiltrekke partner. Øker og sjanse for å hisse på seg andre. 
		luktesans, // default 0. %-vis sjanse for å detektere lukt, lukte lenger unna, mer presis retning        
		reproduksjonstid, //default 1. lenger gir sterkere avkom, men er sårbar lenger
		mot, //default 1, hvor redd du blir i møte med andre
		
		//Potensielle egenskaper:
		// - størrelse -> påvirker kroppstetthet, akslerasjon etc
		// hunter / prey eyes -> snevert og skarpt mot bredt og svakt.
		COUNT //For å telle antall egenskaper
	};

	enum class Sensorer {
		syn, 
		lukt, 
		temperatur,
		posisjon, //kartkvadrant
		helse, //liv
		stamina, //utmattelse
		sult,
		tørst,
		smak,
		frykt,
		reting,
		COUNT //For å få størrelsen 

	};

	enum class Handlinger {

		rusle_N, //Nord
		rusle_O, //Øst
		rusle_S, //Sør
		rusle_V, //Vest
		roter_med, //klokka
		roter_mot, //klokka
		
		flykt,
		fight,

		smak,
		spis,
		drikk,
		pul
		
	};

	~Organisme(){};
};

inline const std::map<Organisme::Egenskaper, std::string> EgenskapMap = {

	{Organisme::Egenskaper::hastighet , "Hastighet"}, 
	{Organisme::Egenskaper::vekt , "Vekt"},
	{Organisme::Egenskaper::syn , "Syn"},
	{Organisme::Egenskaper::genAntall , "Antall Gener"},
	{Organisme::Egenskaper::tann_spisshet , "Tennenes Spisshet"},
	{Organisme::Egenskaper::magesyre , "Magesyretype"},
	{Organisme::Egenskaper::feromoner , "Feromoner"},
	{Organisme::Egenskaper::luktesans , "Luktesans"},
	{Organisme::Egenskaper::reproduksjonstid , "Graviditetstid"},
	{Organisme::Egenskaper::mot , "Dumdristighet"}
};

inline const std::map<Organisme::Sensorer, std::string> SensorMap = {

	{Organisme::Sensorer::syn , "Syn"}, 
	{Organisme::Sensorer::lukt , "Lukt"},
	{Organisme::Sensorer::temperatur , "Temperatur"},
	{Organisme::Sensorer::posisjon , "Posisjon"},
	{Organisme::Sensorer::helse , "Helse/liv"},
	{Organisme::Sensorer::stamina , "Stamina/Sleten"},
	{Organisme::Sensorer::sult , "sult"},
	{Organisme::Sensorer::tørst , "Hydrering"},
	{Organisme::Sensorer::smak , "Smaksløker"},
	{Organisme::Sensorer::frykt , "Frykt"}
};


inline const std::map<Organisme::Handlinger, std::string> HandlingMap = {

	{Organisme::Handlinger::rusle_N , "Gå Nord"}, 
	{Organisme::Handlinger::rusle_O , "Gå Øst"}, 
	{Organisme::Handlinger::rusle_S , "Gå Sør"}, 
	{Organisme::Handlinger::rusle_V , "Gå Vest"}, 
	{Organisme::Handlinger::roter_med , "Roter med klokka"},
	{Organisme::Handlinger::roter_mot , "Roter mot klokka"},

	{Organisme::Handlinger::flykt , "Flykte"},
	{Organisme::Handlinger::fight , "Fighte"},
	{Organisme::Handlinger::smak, "Smake"},
	{Organisme::Handlinger::spis , "Spise"},
	{Organisme::Handlinger::drikk , "Drikke"},
	{Organisme::Handlinger::pul , "Pule"}
};


// UTILS
//
int st(Organisme::Egenskaper);

