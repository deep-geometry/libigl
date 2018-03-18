// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("write_triangle_mesh", []
(
  const std::string str,
  Eigen::MatrixXd& V,
  Eigen::MatrixXi& F
)
{
  return igl::write_triangle_mesh(str,V,F);
}, __doc_igl_write_triangle_mesh,
py::arg("str"), py::arg("V"), py::arg("F"));
