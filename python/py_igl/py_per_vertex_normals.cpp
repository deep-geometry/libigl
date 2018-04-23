// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
py::enum_<igl::PerVertexNormalsWeightingType>(m, "PerVertexNormalsWeightingType")
    .value("PER_VERTEX_NORMALS_WEIGHTING_TYPE_UNIFORM", igl::PER_VERTEX_NORMALS_WEIGHTING_TYPE_UNIFORM)
    .value("PER_VERTEX_NORMALS_WEIGHTING_TYPE_AREA", igl::PER_VERTEX_NORMALS_WEIGHTING_TYPE_AREA)
    .value("PER_VERTEX_NORMALS_WEIGHTING_TYPE_ANGLE", igl::PER_VERTEX_NORMALS_WEIGHTING_TYPE_ANGLE)
    .value("PER_VERTEX_NORMALS_WEIGHTING_TYPE_DEFAULT", igl::PER_VERTEX_NORMALS_WEIGHTING_TYPE_DEFAULT)
    .value("NUM_PER_VERTEX_NORMALS_WEIGHTING_TYPE", igl::NUM_PER_VERTEX_NORMALS_WEIGHTING_TYPE)
    .export_values();

m.def("per_vertex_normals", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
  const igl::PerVertexNormalsWeightingType weighting
)
{
  Eigen::MatrixXd N;
  igl::per_vertex_normals(V,F,weighting,N);
  return N;
}, __doc_igl_per_vertex_normals,
py::arg("V"), py::arg("F"), py::arg("weighting"));

m.def("per_vertex_normals", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F
)
{
  Eigen::MatrixXd N;
  igl::per_vertex_normals(V,F,N);
  return N;
}, __doc_igl_per_vertex_normals,
py::arg("V"), py::arg("F"));

m.def("per_vertex_normals", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
  const igl::PerVertexNormalsWeightingType weighting,
  const Eigen::MatrixXd& FN
)
{
  Eigen::MatrixXd N;
  igl::per_vertex_normals(V,F,weighting,FN,N);
  return N;
}, __doc_igl_per_vertex_normals,
py::arg("V"), py::arg("F"), py::arg("weighting"), py::arg("FN"));

m.def("per_vertex_normals", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
  const Eigen::MatrixXd& FN
)
{
  Eigen::MatrixXd N;
  igl::per_vertex_normals(V,F,FN,N);
  return N;
}, __doc_igl_per_vertex_normals,
py::arg("V"), py::arg("F"), py::arg("FN"));
