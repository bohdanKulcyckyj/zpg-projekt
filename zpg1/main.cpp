#include "Application.h"

int main(void)
{
    Application* app = new Application();
    app->initialization(); //OpenGL inicialization
    app->run(); //Rendering 
}

// deltaPOs.x *0.01
// target.x = cos targetA
// target.y = sin targetA
//
// scena -> objekty, shadery,
// transformation -> pro jednotlive tridy zvlast
// camera object ve scene
// controler -> vsechny callback funkce -> kdyz se neco zmeni -> rozhodne co se stane
// observer mezi shaderProgramem a Camerou -> camera se zmenila a sp se rozhodne co se zmeni

// =======================
// v ShaderProgramu do updateUnoform posilat spis tridu transformace a ne matici