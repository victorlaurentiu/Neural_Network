#pragma once

#include <vector>
using namespace std;

class Neuron {
public:
	Neuron();
	Neuron(int);
	~Neuron();
	float feedFoward(vector<float>&);
	void calcOutGradient(float);
	void calcHiddenGradient(const vector<Neuron*>&, int);
	void update(vector<Neuron*>&);

	float getActivation() const;
	void setActivation(float);
	float getGradient() const;
	vector<float>& getWeights();

private:
	float bias;
	float deltaBias;
	vector<float> weights;
	vector<float> deltaWeights;

	float my_out;		// activation output
	float my_gradient;	// error gradient

	static float eta;	// learning rate
	static float alpha;	// momentum constant

	// helper functions
	static float dot(const vector<float>& v1, const vector<float>& v2);	// dot product
	static float sigmoid(float x);
	static float sigmoid_deriv(float x);
	static float sumDow(const vector<Neuron*>& nextLayer, int my_index);
};