#include "Application.h"

int main(void)
{
    Application* app = new Application();
    app->initialization(); //OpenGL inicialization

    //Loading scene
    app->createModels();
    app->run(); //Rendering 
}

// zapnout zbuffer
// v loopu na zacatku vymazat hloubkovy a barevny buffer
// deltaPOs.x *0.01
// target.x = cos targetA
// target.y = sin targetA
//
// scena -> objekty, shadery,
// transformatiion -> pro jednotlive tridy zvlast
// camera object ve scene
// controler -> vsechny callback funkce -> kdyz se neco zmeni -> rozhodne co se stane
// observer mezi shaderPrograme a Camerou -> camera se zmenila a sp se rozhodne co se zmeni
