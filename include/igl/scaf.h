// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef SCAF_H
#define SCAF_H

#include <igl/slim.h>
#include <igl/igl_inline.h>

namespace igl
{
    // Use a similar interface to igl::slim
    // Implement ready-to-use 2D version of the algorithm described in 
    // SCAF: Simplicial Complex Augmentation Framework for Bijective Maps
    // Zhongshi Jiang, Scott Schaefer, Daniele Panozzo, ACM Trancaction on Graphics (Proc. SIGGRAPH Asia 2017)
    // For a complete implementation and customized UI, please refer to https://github.com/jiangzhongshi/scaffold-map

    struct SCAFData
    {
      double scaffold_factor = 10;
      igl::SLIMData::SLIM_ENERGY scaf_energy = igl::SLIMData::SYMMETRIC_DIRICHLET;
      igl::SLIMData::SLIM_ENERGY slim_energy = igl::SLIMData::SYMMETRIC_DIRICHLET;

      // Output
      int dim = 2;
      double energy; // objective value

      long mv_num = 0, mf_num = 0;
      long sv_num = 0, sf_num = 0;
      long v_num{}, f_num = 0;
      Eigen::MatrixXd m_V; // input initial mesh V
      Eigen::MatrixXi m_T; // input initial mesh F/T
      // INTERNAL
      Eigen::MatrixXd w_uv; // whole domain uv: mesh + free vertices
      Eigen::MatrixXi s_T; // scaffold domain tets: scaffold tets
      Eigen::MatrixXi w_T;

      Eigen::VectorXd m_M; // mesh area or volume
      Eigen::VectorXd s_M; // scaffold area or volume
      Eigen::VectorXd w_M; // area/volume weights for whole
      double mesh_measure; // area or volume
      double proximal_p = 0;

      Eigen::VectorXi frame_ids;
      Eigen::VectorXi fixed_ids;

      std::map<int, Eigen::RowVectorXd> soft_cons;
      double soft_const_p = 1e4;

      Eigen::VectorXi internal_bnd;
      Eigen::MatrixXd rect_frame_V;
      // multi-chart support
      std::vector<int> component_sizes;
      std::vector<int> bnd_sizes;
    
        // reweightedARAP interior variables.
        bool has_pre_calc = false;
        Eigen::SparseMatrix<double> Dx_s, Dy_s, Dz_s;
        Eigen::SparseMatrix<double> Dx_m, Dy_m, Dz_m;
        Eigen::MatrixXd Ri_m, Ji_m, Ri_s, Ji_s;
        Eigen::MatrixXd W_m, W_s;
    };


// Compute necessary information to start using SCAF
// Inputs:
//		V           #V by 3 list of mesh vertex positions
//		F           #F by 3/3 list of mesh faces (triangles/tets)
//    data          igl::SCAFData
//    slim_energy Energy type to minimize
//    b           list of boundary indices into V (soft constraint)
//    bc          #b by dim list of boundary conditions (soft constraint)
//    soft_p      Soft penalty factor (can be zero)
    IGL_INLINE void scaf_precompute(
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const Eigen::MatrixXd &V_init,
        SCAFData &data,
        SLIMData::SLIM_ENERGY slim_energy,
        Eigen::VectorXi& b,
        Eigen::MatrixXd& bc,
        double soft_p);


// Run iter_num iterations of SCAF, with precomputed data
// Outputs:
//    V_o (in SLIMData): #V by dim list of mesh vertex positions
  IGL_INLINE Eigen::MatrixXd scaf_solve(SCAFData &data, int iter_num);
  }

#ifndef IGL_STATIC_LIBRARY
#  include "scaf.cpp"
#endif

#endif //SCAF_H
