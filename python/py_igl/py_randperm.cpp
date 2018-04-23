// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Sebastian Koch <s.koch@tu-berlin.de> and Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("randperm", []
(
  int n
)
{
  Eigen::MatrixXi temp1;
  igl::randperm(n, temp1);
  return temp1;
}, __doc_igl_randperm,
py::arg("n"));

