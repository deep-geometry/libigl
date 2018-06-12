// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

py::class_<igl::SCAFData> SCAFData(m, "SCAFData");

SCAFData
.def(py::init<>())
.def_readonly("energy", &igl::SCAFData::energy)
.def_readonly("w_uv", &igl::SCAFData::w_uv)
;

m.def("scaf_precompute", [](
        const Eigen::MatrixXd &V,
        const Eigen::MatrixXi &F,
        const Eigen::MatrixXd &V_init,
        igl::SCAFData &data,
        igl::MappingEnergyType slim_energy,
        Eigen::MatrixXi& b,
        Eigen::MatrixXd& bc,
        double soft_p) {
          assert_not_empty("V_init", V_init);
          assert_is_VectorX("b", b);
          Eigen::VectorXi new_b = Eigen::Map<Eigen::VectorXi>(b.data(), b.size());
          return igl::scaf_precompute(V,F,V_init, data, slim_energy, new_b, bc, soft_p);
        }, __doc_igl_scaf_precompute, 
py::arg("V"), py::arg("F"), py::arg("V_init"), py::arg("data"), py::arg("slim_energy"), py::arg("b"), py::arg("bc"), py::arg("soft_p"));

m.def("scaf_solve", &igl::scaf_solve, __doc_igl_scaf_solve, py::arg("data"), py::arg("iter_num"));
