#include <string>
#include <format>
#include <sstream>

std::string Organisme::pGener(){return this->genotype;};
std::string Organisme::pVekter(){

	std::stringstream vektStrom;	

	for(int i = 0 ; this->vekter.size() ; i++){

		vektStrom << std::format("Vekt {}: ", i) << this->vekter[i] << "\n";
		
	}
	return vektStrom.str(); 
};
std::string Organisme::pEgenskaper(){

	std::stringstream egenskapStream;
	egenskapStream << "======= Egenskaper =======\n\n";
	for (int i = 0; i < this->egenskaper.size(); i++){

		Organisme::Egenskaper egenskap = static_cast<Organisme::Egenskaper>(i);

		egenskapStream << Organisme::EgenskapMap[egenskap] << " : " << this->egenskaper.at(i) << "\n";
		
	}
	return egenskapStream.str();

}

std::string Organisme::pSensorer(){
	std::stringstream sensorStream;
	sensorStream << "======= Sensorer =======\n\n";
	for (int i = 0; i < this->sensorer.size(); i++){

		Organisme::sensorer sensor = static_cast<Organisme::Sensorer>(i);

		sensorStream << Organisme::SensorMap[sensor] << ", \n";
		
	}
	return sensorStream.str();
}


