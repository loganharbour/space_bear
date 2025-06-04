#include "UnobtaniumMaterial.h"

registerMooseObject("SpaceBearApp", UnobtaniumMaterial);

InputParameters
UnobtaniumMaterial::validParams()
{
  InputParameters params = ADMaterial::validParams();
  return params;
}

UnobtaniumMaterial::UnobtaniumMaterial(const InputParameters & parameters)
  : ADMaterial(parameters), _k(declareADPropertyByName<Real>("k"))
{
}

void
UnobtaniumMaterial::computeQpProperties()
{
  _k[_qp] = 1.0;
}
