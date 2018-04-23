// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("readOBJ", []
(
  const std::string str
)
{
  Eigen::MatrixXd V;
  Eigen::MatrixXd TC;
  Eigen::MatrixXd CN;
  Eigen::MatrixXi F;
  Eigen::MatrixXi FTC;
  Eigen::MatrixXi FN;
  igl::readOBJ(str,V,TC,CN,F,FTC,FN);
  return std::make_tuple(V,TC,CN,F,FTC,FN);
}, __doc_igl_readOBJ,
py::arg("str"));
