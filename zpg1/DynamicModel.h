#pragma once
#include "Model.h"

#include<assimp/Importer.hpp>// C++ importerinterface
#include<assimp/scene.h>// aiSceneoutputdata structure
#include<assimp/postprocess.h>// Post processingflags

#include<vector>

using namespace std;

class DynamicModel : public Model
{
protected:
	int vertexCount = 0;
	vector<float> modelData;
	vector<float> loadModel(const char* source);
public:
	DynamicModel(const char* source);
	void draw() override;
};

