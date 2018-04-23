// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

m.def("upsample", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F
)
{
  Eigen::MatrixXd NV;
  Eigen::MatrixXi NF;
  igl::upsample(V, F, NV, NF);
  return std::make_tuple(NV,NF);
}, __doc_igl_upsample,
py::arg("V"), py::arg("F"));

