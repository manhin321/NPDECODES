#ifndef SOLVECAUCHYPROBLEM_H
#define SOLVECAUCHYPROBLEM_H

/**
 * @file solvecauchyproblem.h
 * @brief NPDE exam problem summer 2019 "CLEmpiricFlux" code
 * @author Oliver Rietmann
 * @date 19.07.2019
 * @copyright Developed at ETH Zurich
 */

#include "clempiricflux.h"
#include "uniformcubicspline.h"

#include <utility>

#include <Eigen/Core>

namespace CLEmpiricFlux {

/**
 * @brief Compute an interval containing the support of the solution u at time
 * t.
 *
 * @param f flux function (describing the PDE)
 * @param initsupp interval containing the support of u at initial time
 * @return interval containg the support of u at time t
 */
Eigen::Vector2d findSupport(const UniformCubicSpline &f,
                            const Eigen::Vector2d &initsupp, double t);

/**
 * @brief Computes the cell averages at initial time on an interval
 * containing the support of the solution u(x,t) for all 0 < t < T.
 *
 * @param f flux function (describing the PDE)
 * @param u0 initial data, -1 < u0 < 1, supported in [-1, 1],
 *                           modeling std::function<double(double)>
 * @param h spacial meshwidth, h > 0.0
 * @param T final time, T > 0.0
 * @return cell averages of u(x, 0)
 */
template <typename FUNCTOR>
Eigen::VectorXd computeInitVec(const UniformCubicSpline &f, FUNCTOR &&u0,
                               double h,
                               double T) {
  Eigen::VectorXd mu0;
  /* SOLUTION_BEGIN */
  /* SOLUTION_END */
  return mu0;
}

/**
 * @brief Implements Ralston's method to solve a homogenous ODE
 *
 * @param rhs right-hand side of the homogenous ODE, models
 *                            std::function<Eigen::VectorXd(Eigen::VectorXd)>
 * @param mu0 initial data, vector of size N
 * @param tau timestep size, tau > 0.0
 * @param n number of timesteps to perform, n > 0
 * @return vector of size N containg the approximate solution at time n * tau
 */
template <typename FUNCTOR>
Eigen::VectorXd RalstonODESolver(FUNCTOR &&rhs, Eigen::VectorXd mu0, double tau,
                                 int n);

/**
 * @brief Implements a finite volume scheme to solve a conservation law with
 * strictly convex flux function
 *
 * @param f flux function (describing the PDE)
 * @param mu0 cell averages of initial data
 * @param N number of spacial nodes, N > 1
 * @param T final time, T > 0.0
 * @return cell averages at final time, i.e.of the solution u(x,T)
 */
Eigen::VectorXd solveCauchyProblem(const UniformCubicSpline &f,
                                   const Eigen::VectorXd &mu0, double h,
                                   double T);

} // namespace CLEmpiricFlux

#endif