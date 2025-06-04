#include "UnobtaniumMaterial.h"

registerMooseObject("SpaceBearApp", UnobtaniumMaterial);

InputParameters
UnobtaniumMaterial::validParams()
{
  InputParameters params = ADMaterial::validParams();
  params.addRequiredCoupledVar(
      "variable",
      "The variable to couple to (the one that has the gradient in the denominator of k)");
  return params;
}

UnobtaniumMaterial::UnobtaniumMaterial(const InputParameters & parameters)
  : ADMaterial(parameters),
    _k(declareADPropertyByName<Real>("k")),
    _grad_u(adCoupledGradient("variable"))
{
}

void
UnobtaniumMaterial::computeQpProperties()
{
  _k[_qp] = 1.0 / std::sqrt(1 + _grad_u * _grad_u);
}
