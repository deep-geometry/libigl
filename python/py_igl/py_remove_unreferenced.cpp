// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("remove_unreferenced", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
   Eigen::MatrixXd& NV,
   Eigen::MatrixXi& NF,
  Eigen::MatrixXi& I,
  Eigen::MatrixXi& J,
)
{
  return igl::remove_unreferenced(V, F, NV, NF, I, J);
}, __doc_igl_remove_unreferenced,
py::arg("V"),py::arg("F"),py::arg("NV"),py::arg("NF"),py::arg("I"), py::arg("J"));