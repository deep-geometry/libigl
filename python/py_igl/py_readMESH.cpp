// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("readMESH", []
(
  const std::string mesh_file_name
)
{
  Eigen::MatrixXd V;
  Eigen::MatrixXi T;
  Eigen::MatrixXi F;
  igl::readMESH(mesh_file_name, V, T, F);
  return std::make_tuple(V,T,F);
}, __doc_igl_readMESH,
py::arg("mesh_file_name"));

