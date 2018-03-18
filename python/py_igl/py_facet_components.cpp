// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("facet_components", []
(
  const Eigen::MatrixXi& F,
  Eigen::MatrixXi& C
)
{
  return igl::facet_components(F, C);
}, __doc_igl_facet_components,
py::arg("F"), py::arg("C"));