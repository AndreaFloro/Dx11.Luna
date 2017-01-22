#include "LightHelper.fx"

cbuffer cbPerFrame
{
    DirectionalLight gDirLight;
    PointLight gPointLight;
    SpotLight gSpotLight;
};