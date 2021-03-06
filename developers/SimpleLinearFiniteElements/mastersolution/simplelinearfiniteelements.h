/**
 * @file
 * @brief NPDE homework SimpleLinearFiniteElements
 * @author Amélie Loher
 * @date 11/12/2019
 * @copyright Developed at ETH Zurich
 */
#include <cmath>
#include <functional>
#include <string>
#include <tuple>

#include <Eigen/Dense>
#include <Eigen/SparseLU>

#include "tria_mesh_2D.h"

namespace SimpleLinearFiniteElements {

Eigen::Matrix<double, 2, 3> gradbarycoordinates(const Eigen::Matrix<double, 2, 3>& triangle);

Eigen::Matrix3d ElementMatrix_Mass_LFE(const Eigen::Matrix<double, 2, 3>& triangle);

Eigen::Matrix3d ElementMatrix_Lapl_LFE(const Eigen::Matrix<double, 2, 3>& triangle);

Eigen::Matrix3d ElementMatrix_LaplMass_LFE(const Eigen::Matrix<double, 2, 3>& triangle);

double L2Error(const SimpleLinearFiniteElements::TriaMesh2D& mesh, const Eigen::VectorXd& uFEM,
               const std::function<double(const Eigen::Vector2d&)> exact);

double H1Serror(const SimpleLinearFiniteElements::TriaMesh2D& mesh, const Eigen::VectorXd& uFEM,
                const std::function<Eigen::Vector2d(const Eigen::Vector2d&)> exact);

Eigen::SparseMatrix<double> GalerkinAssembly(
    const SimpleLinearFiniteElements::TriaMesh2D& mesh, const std::function<Eigen::Matrix3d(const Eigen::Matrix<double, 2, 3>&)>& getElementMatrix);

Eigen::VectorXd assemLoad_LFE(const SimpleLinearFiniteElements::TriaMesh2D& mesh,
                              const std::function<double(const Eigen::Vector2d&)>& f);

std::tuple<Eigen::VectorXd, double, double> solve(const SimpleLinearFiniteElements::TriaMesh2D &mesh);

} // namespace SimpleLinearFiniteElements 
