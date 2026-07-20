#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "organisme.h"
#include "matte.h"
#include "settings.h"

Organisme::Organisme( std::string conf ){
	if (conf == "default"){

		this->egenskaper = defaultEgenskaper;
	}
	else if (conf == "random") {
		Organisme::tilfeldigEgenskaper();	
	}
	
	std::cout << "Organisme opprettet" << std::endl;
	if (conf == ""){
		std::cout << "Type TOM" << std::endl;
	}
	this->posisjon = {randomFloat(-1, 1), randomFloat(-1, 1)};
};

std::vector<float> Organisme::rEgenskaper() const {


	return this->egenskaper;
}

std::array<float, 2> Organisme::getPos() const {return this->posisjon;}

void Organisme::tilfeldigEgenskaper(){
	using e = Organisme::Egenskaper;

	std::vector<float> nyeEgenskaper( static_cast<int>(Organisme::Egenskaper::COUNT) );

	nyeEgenskaper.at(st(e::hastighet))	  = normalDist  (1, 0.1667);
	nyeEgenskaper.at(st(e::vekt))		  = normalDist  (1, 0.1667);
	nyeEgenskaper.at(st(e::syn))		  = randomFloat (0, 1);
	nyeEgenskaper.at(st(e::genAntall))	  = randomInt	(3, 6);
	nyeEgenskaper.at(st(e::tann_spisshet))	  = normalDist	(0.5, 0.1667);
	nyeEgenskaper.at(st(e::magesyre))	  = normalDist	(0.5, 0.1667);
	nyeEgenskaper.at(st(e::feromoner))	  = randomFloat	(0, 1);
	nyeEgenskaper.at(st(e::luktesans))	  = randomFloat	(0, 1);
	nyeEgenskaper.at(st(e::reproduksjonstid)) = normalDist	(1, 0.1667 );
	nyeEgenskaper.at(st(e::mot)) 		  = normalDist	(1, 0.1667 );
	
	for (float& e : nyeEgenskaper){
		if (e < 0) e = 0;
	}
	this->egenskaper = nyeEgenskaper;
	this->genotype = randomHex(nyeEgenskaper.at(st(e::genAntall))); 
}

void Organisme::oppdaterEgenskaper(std::vector<float> nyeEgenskaper) {

	this->egenskaper = nyeEgenskaper;
	std::cout <<"Egenskapene er opprettet"<< std::endl;

};

std::string Organisme::pGener() const {return this->genotype;};


std::string Organisme::pVekter() const {

	std::stringstream vektStrom;	

	for(int i = 0 ; this->vekter.size() ; i++){

		vektStrom << "Vekt " << i << ": " << this->vekter[i] << "\n";
		
	}
	return vektStrom.str(); 
};

std::string Organisme::pEgenskaper() const {

	std::stringstream egenskapStream;
	egenskapStream << "======= Egenskaper =======\n\n";
	for (size_t i = 0; i < this->egenskaper.size(); i++){

		Organisme::Egenskaper egenskap = static_cast<Organisme::Egenskaper>(i);

		egenskapStream << EgenskapMap.at(egenskap) << " : " << this->egenskaper.at(i) << "\n";
		
	}

	egenskapStream << "Posisjon: ( " << this->posisjon[0] << ", " << this->posisjon[1] << " )\n";

	return egenskapStream.str();

}

std::string Organisme::pSensorer() const {
	std::stringstream sensorStream;
	sensorStream << "======= Sensorer =======\n\n";
	for (int i = 0; i < static_cast<int>(Organisme::Sensorer::COUNT) -1; i++){

		Organisme::Sensorer sensor = static_cast<Organisme::Sensorer>(i);

		sensorStream << SensorMap.at(sensor) << ", \n";
		
	}
	return sensorStream.str();
}

// UTILS
// static cast egenskap til int
int st(Organisme::Egenskaper egenskap){
	return static_cast<int>(egenskap);
}


