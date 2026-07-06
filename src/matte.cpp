#include <random>


int randomInt(int lav, int hoy){
	
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> dist(lav, hoy);

	return dist(generator);

}
float randomFloat(float lav, float hoy){
	
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> dist(lav, hoy);

	return dist(generator);

}
double randomFloat(double lav, double hoy){
	
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> dist(lav, hoy);

	return dist(generator);

}
