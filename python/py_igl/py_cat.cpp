// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("cat", []
(
  const int dim,
  const Eigen::MatrixXd& A,
  const Eigen::MatrixXd& B
)
{
  Eigen::MatrixXd C;
  igl::cat(dim, A, B, C);
  return C;
}, __doc_igl_cat,
py::arg("dim"), py::arg("A"), py::arg("B"));

m.def("cat", []
(
  const int dim,
  const Eigen::MatrixXi& A,
  const Eigen::MatrixXi& B
)
{
  Eigen::MatrixXi C;
  igl::cat(dim, A, B, C);
  return C;
}, __doc_igl_cat,
py::arg("dim"), py::arg("A"), py::arg("B"));

m.def("cat", []
(
  const int dim,
  const Eigen::SparseMatrix<double>& A,
  const Eigen::SparseMatrix<double>& B
)
{
  Eigen::SparseMatrix<double> C;
  igl::cat(dim, A, B, C);
  return C;
}, __doc_igl_cat,
py::arg("dim"), py::arg("A"), py::arg("B"));

