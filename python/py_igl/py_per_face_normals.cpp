// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("per_face_normals", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
  const Eigen::MatrixXd& Z
)
{
  Eigen::MatrixXd N;
  assert_is_VectorX("Z",Z);
  igl::per_face_normals(V,F,Z,N);
  return N;
}, __doc_igl_per_face_normals,
py::arg("V"), py::arg("F"), py::arg("Z"));

m.def("per_face_normals", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F
)
{
  Eigen::MatrixXd N;
  igl::per_face_normals(V,F,N);
  return N;
}, __doc_igl_per_face_normals,
py::arg("V"), py::arg("F"));

m.def("per_face_normals_stable", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F
)
{
  Eigen::MatrixXd N;
  igl::per_face_normals_stable(V,F,N);
  return N;
}, __doc_igl_per_face_normals,
py::arg("V"), py::arg("F"));
