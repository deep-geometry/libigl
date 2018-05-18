// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

py::class_<igl::SLIMData> SLIMData(m, "SLIMData");

SLIMData
.def(py::init<>())
;

m.def("slim_precompute", 
[](
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const Eigen::MatrixXd &V_init,
        igl::SLIMData &data,
        igl::MappingEnergyType slim_energy,
        Eigen::MatrixXi& b,
        Eigen::MatrixXd& bc,
        double soft_p) {
          Eigen::VectorXi new_b = Eigen::Map<Eigen::VectorXi>(b.data(), b.size());
          return igl::slim_precompute(V,F,V_init, data, slim_energy, new_b, bc, soft_p);
        }, __doc_igl_slim_precompute, py::arg("V"), py::arg("F"), py::arg("V_init"), 
py::arg("data"), py::arg("slim_energy"), py::arg("b"), py::arg("bc"), py::arg("soft_p"));

m.def("slim_solve", &igl::slim_solve, __doc_igl_slim_solve, py::arg("data"), py::arg("iter_num"));