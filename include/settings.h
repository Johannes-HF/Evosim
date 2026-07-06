#pragma once
#include <vector>
const unsigned int SKJERM_BREDDE = 800;
const unsigned int SKJERM_HOYDE = 600;

// -- ORGANISME --
constexpr int ANTALL_VEKTER = 3;
constexpr int PETRI_BREDDE = 800; //Bredde og høyde på "petriskålen" cellene befinner seg i
constexpr int PETRI_HOYDE = 600;
inline std::vector<float> defaultEgenskaper = {

	1, //hastighet
	1, //vekt
	0, //syn	
	5, //GenAntall
	0.5, //tannSpisshet
	0.5,  //magesyre
	0, //feromoner 
	0, //luktesans  
	1, //reproduksjonstid
	1 //mot / Dumdristighet
};

