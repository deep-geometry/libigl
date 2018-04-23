// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

m.def("triangle_triangle_adjacency", []
(
  const Eigen::MatrixXi& F
)
{
  Eigen::MatrixXi TT;
  Eigen::MatrixXi TTi;
  igl::triangle_triangle_adjacency(F, TT, TTi);
  return std::make_tuple(TT,TTi);
}, __doc_igl_triangle_triangle_adjacency,
py::arg("F"));

m.def("triangle_triangle_adjacency", []
(
  const Eigen::MatrixXi& F
)
{
  Eigen::MatrixXi TT;
  igl::triangle_triangle_adjacency(F, TT);
  return TT;
}, __doc_igl_triangle_triangle_adjacency,
py::arg("F"));
