#include "DynamicModel.h"

DynamicModel::DynamicModel(const char* source) : Model() {
    modelData = loadModel(source);

    // Vertex buffer object (VBO)
    this->VBO = 0;
    glGenBuffers(1, &this->VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(modelData), modelData.data(), GL_STATIC_DRAW);
    // Vertex Array Object (VAO)
    this->VAO = 0;
    glGenVertexArrays(1, &this->VAO); //generate the VAO
    glBindVertexArray(this->VAO); //bind the VAO
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), NULL);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

}

vector<float> DynamicModel::loadModel(const char* source)
{
    vertexCount = 0;
    Assimp::Importer importer;
    unsigned int importOptions = aiProcess_Triangulate
        | aiProcess_OptimizeMeshes              // reduce the number of draw calls
        | aiProcess_JoinIdenticalVertices       // identifies and joins identical vertex data sets within all imported meshes
        | aiProcess_Triangulate                 // triangulates all faces of all meshes 
        | aiProcess_CalcTangentSpace;           // calculates the tangents and bitangents for the imported meshes

    const aiScene* scene = importer.ReadFile(source, importOptions);

    if (scene) {
        aiMesh* mesh = scene->mMeshes[0];//Only first mesh 
        printf("Triangles:%d \n", mesh->mNumFaces);
        vertexCount = mesh->mNumFaces * 3;

        aiFace* f;
        for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];

            for (unsigned int j = 0; j < 3; j++)
            {
                int id = face.mIndices[j];

                //Vertex position
                aiVector3D pos = mesh->mVertices[id];
                modelData.push_back(pos.x);
                modelData.push_back(pos.y);
                modelData.push_back(pos.z);

                //Vertex normal
                aiVector3D nor = mesh->mNormals[id];
                modelData.push_back(nor.x);
                modelData.push_back(nor.y);
                modelData.push_back(nor.z);

                //Vertex uv
                aiVector3D uv = mesh->mTextureCoords[0][id];
                modelData.push_back(uv.x);
                modelData.push_back(uv.y);

            }
        }
    }
    else
    {
        std::cout << "An error occurred while loading model." << std::endl;
        exit(EXIT_FAILURE);
    };

    return modelData;
}

void DynamicModel::draw() {
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}