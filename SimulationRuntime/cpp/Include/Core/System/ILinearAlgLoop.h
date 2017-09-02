#pragma once
/** @addtogroup coreSystem
 *
 *  @{
 */

/*****************************************************************************/
/**

Abstract interface class for algebraic loop in equations in open modelica.

\date     October, 1st, 2008
\author

*/
/*****************************************************************************
Copyright (c) 2008, OSMC
*****************************************************************************/


class ILinearAlgLoop
{
public:

  virtual ~ILinearAlgLoop() {};

  /// Provide index of equation
  virtual int getEquationIndex() const = 0;

  /// Provide number (dimension) of variables according to the data type
  virtual int getDimReal() const = 0;

  /// (Re-) initialize the system of equations
  virtual void initialize() = 0;

  /// Provide names of alg loop variables
  virtual void getNamesReal(const char** names) const = 0;
  /// Provide nominal values for alg loop variables
  virtual void getNominalReal(double* nominals) const = 0;
  /// Provide min values for alg loop variables
  virtual void getMinReal(double* mins) const = 0;
  /// Provide max values for alg loop variables
  virtual void getMaxReal(double* maxs) const = 0;

  /// Return simulation time
  virtual double getSimTime() const = 0;
  /// Provide variables of given data type
  virtual void getReal(double* lambda) const = 0;
  /// Set variables with given data type
  virtual void setReal(const double* lambda) = 0;

  /// Evaluate equations for given variables
  virtual void evaluate() = 0;

  /// Provide the right hand side (b-vector)
  virtual void getb(double* res) const = 0;

  //testing commenting out virtual void getSparseAdata(double* data, int nonzeros) = 0;

  virtual const matrix_t& getAMatrix()  = 0;
  virtual  sparsematrix_t& getSparseAMatrix()  = 0;
  virtual bool isLinearTearing() = 0;
  virtual bool isConsistent() = 0;
  virtual bool getUseSparseFormat() = 0;
  virtual void setUseSparseFormat(bool value) = 0;
  virtual float queryDensity() = 0;

  /*/// Fügt das übergebene Objekt als Across-Kante hinzu
  void addAcrossEdge(IObject& new_obj);

  /// Fübt das übergebene Objekt als Through-Kante hinzu
  void addThroughEdge(IObject& new_obj);

  /// Definiert die übergebene Größe als Schnittgröße
  void addConstraint(double& constr_value);
  */
  //public : double * _AData;
};
/** @} */ // end of coreSystem
