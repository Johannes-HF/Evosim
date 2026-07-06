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
	std::uniform_real_distribution<float> dist(lav, hoy);

	return dist(generator);

}
double randomDouble(double lav, double hoy){
	
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> dist(lav, hoy);

	return dist(generator);

}

float normalDist(float mu, float sigma){
	std::random_device rd;

	std::mt19937 gen(rd());

	std::normal_distribution<float> dist(mu, sigma);

	return dist(gen);
}
