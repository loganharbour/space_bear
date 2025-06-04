#include "UnobtaniumMaterial.h"

registerMooseObject("SpaceBearApp", UnobtaniumMaterial);

InputParameters
UnobtaniumMaterial::validParams()
{
  InputParameters params = ADMaterial::validParams();
  return params;
}

UnobtaniumMaterial::UnobtaniumMaterial(const InputParameters & parameters) : ADMaterial(parameters)
{
}

void
UnobtaniumMaterial::computeQpProperties()
{
}
